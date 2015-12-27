#include <QDebug>
#include "httpheaderhandler.h"

HTTPHeaderHandler::HTTPHeaderHandler(QByteArray &rawHeader)
{
    // extract target
    QList<QByteArray> method_field = rawHeader.mid(0, rawHeader.indexOf('\r')).split(' ');

    // check if the header methods has been break into 3 piece
    Q_ASSERT(method_field.length() == 3);

    // assign each element
    method["Method"] = method_field.at(0);
    method["Target"] = method_field.at(1);
    method["Version"] = method_field.at(2);

    // process the rest of headers
    QList<QByteArray> header_field_list = rawHeader.mid(rawHeader.indexOf('\n') + 1).trimmed().split('\n');

    // insert new header field into map
    for (QByteArray &line : header_field_list)
    {
        int loc = line.indexOf(':');

        QByteArray key = line.left(loc).trimmed();
        QByteArray value = line.mid(loc + 1).trimmed();
        header[key] = value;
    }
}

void HTTPHeaderHandler::setHeaderField(QByteArray &key, QByteArray value)
{
    // check the length of each value
    Q_ASSERT(value.length() < 8190);

    // check the total number of fields
    Q_ASSERT(header.size() < 100);

    header[key] = value;
}

QByteArray HTTPHeaderHandler::getHeaderField(const QByteArray &key)
{
    return header[key];
}

HTTPHeaderHandler::KnownMethods HTTPHeaderHandler::getMethod()
{
    const QByteArray method_value = method["Method"];

    if (method_value == "GET")
    {
        return GET;
    }
    else if (method_value == "HEAD")
    {
        return HEAD;
    }
    else if (method_value == "POST")
    {
        return POST;
    }
    else if (method_value == "PUT")
    {
        return PUT;
    }
    else if (method_value == "DELETE")
    {
        return DELETE;
    }
    else if (method_value == "CONNECT")
    {
        return CONNECT;
    }
    else if (method_value == "OPTIONS")
    {
        return OPTIONS;
    }
    else if (method_value == "TRACE")
    {
        return TRACE;
    }
    else
    {
        return UNKNOWN;
    }
}

QByteArray HTTPHeaderHandler::getTarget()
{
    return method["Target"];
}

QByteArray HTTPHeaderHandler::getVersion()
{
    return method["Version"];
}


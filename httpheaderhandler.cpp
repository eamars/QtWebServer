#include <QDebug>
#include "httpheaderhandler.h"

HTTPHeaderHandler::HTTPHeaderHandler(QByteArray &rawHeader)
{
    // extract target
    QList<QByteArray> request_field = rawHeader.mid(0, rawHeader.indexOf('\r')).split(' ');

    // check if the header methods has been break into 3 piece
    Q_ASSERT(request_field.length() == 3);

    // assign each element
    request["Method"] = request_field.at(0);
    request["Target"] = request_field.at(1);
    request["Version"] = request_field.at(2);

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

    qDebug() << request;
    qDebug() << header;
}


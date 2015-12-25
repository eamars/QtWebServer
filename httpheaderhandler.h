#ifndef HTTPHEADERHANDLER_H
#define HTTPHEADERHANDLER_H

#include <QByteArray>
#include <QMap>

class HTTPHeaderHandler
{
public:
    HTTPHeaderHandler(QByteArray &rawHeader);
    void setValue(QByteArray &key, QByteArray value);
    QByteArray getValue(QByteArray &key);

protected:
    QMap<QByteArray, QByteArray> header;
    QMap<QByteArray, QByteArray> request;
};

#endif // HTTPHEADERHANDLER_H

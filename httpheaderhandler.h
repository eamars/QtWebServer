#ifndef HTTPHEADERHANDLER_H
#define HTTPHEADERHANDLER_H

#include <QByteArray>
#include <QMap>

class HTTPHeaderHandler
{
    enum KnownMethods
    {
        UNKNOWN = 0,
        GET = 1,
        HEAD = 2,
        POST = 3,
        PUT = 4,
        DELETE = 5,
        CONNECT = 6,
        OPTIONS = 7,
        TRACE = 8
    };


public:
    HTTPHeaderHandler(QByteArray &rawHeader);
    void setHeaderField(QByteArray &key, QByteArray value);
    QByteArray getHeaderField(const QByteArray &key);

    KnownMethods getMethod();
    QByteArray getTarget();
    QByteArray getVersion();

protected:
    QMap<QByteArray, QByteArray> header;
    QMap<QByteArray, QByteArray> method;
};

#endif // HTTPHEADERHANDLER_H

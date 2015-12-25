#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include <QTcpServer>
#include <QThreadPool>

class HTTPServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit HTTPServer(QObject *parent=0);
    void startServer();

protected:
    void incomingConnection(qintptr handle);

private:
    QThreadPool *pool;
};

#endif // HTTPSERVER_H

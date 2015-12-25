#ifndef HTTPWORKER_H
#define HTTPWORKER_H

#include <QRunnable>

class HTTPWorker : public QRunnable
{
public:
    HTTPWorker(qintptr handle);

protected:
    void run();

protected:
    qintptr clientFd;
    QTcpSocket *socket;
};

#endif // HTTPWORKER_H

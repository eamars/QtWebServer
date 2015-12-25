#include <QDebug>
#include "httpserver.h"
#include "httpworker.h"

HTTPServer::HTTPServer(QObject *parent)
    : QTcpServer(parent)
{
    pool = new QThreadPool(this);
    pool->setMaxThreadCount(1);
}

void HTTPServer::startServer()
{
    if (this->listen(QHostAddress::Any, 80))
    {
        qDebug() << "Server started";
    }
    else
    {
        qDebug() << "Server failed to start";
    }
}

void HTTPServer::incomingConnection(qintptr handle)
{
    // create a handler to handle the request from client
    HTTPWorker *worker = new HTTPWorker(handle);
    worker->setAutoDelete(true);

    // put worker in task queue
    pool->start(worker);
}

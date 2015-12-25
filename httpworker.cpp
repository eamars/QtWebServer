#include <QTcpSocket>
#include <QThread>
#include <QDebug>
#include "httpworker.h"
#include "httpheaderhandler.h"

HTTPWorker::HTTPWorker(qintptr handle)
{
    clientFd = handle;
}

void HTTPWorker::run()
{
    qDebug() << "Worker" << QThread::currentThreadId() << "started";

    QByteArray buffer;
    // create new socket
    socket = new QTcpSocket();
    socket->setSocketDescriptor(clientFd);

    // listen to any incoming message
    while (socket->waitForReadyRead())
    {
        // read from socket
        buffer.append(socket->readAll());
        qDebug() << "Worker" << QThread::currentThreadId() << "received:\n" << buffer;

        // process http header
        HTTPHeaderHandler header(buffer);
        buffer.clear();
    }

    delete socket;

    qDebug() << "Worker" << QThread::currentThreadId() << "ended";
}

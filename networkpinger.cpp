#include "networkpinger.h"
#include <QtNetwork/QTcpSocket>
#include <QDebug>
#include <QTimer>

NetworkPinger::NetworkPinger()
{
    moveToThread(this);
}

NetworkPinger::~NetworkPinger()
{

}

void NetworkPinger::run()
{
    _time=new QTimer(this);
    _time->setInterval(1000);
    connect(_time,&QTimer::timeout,
            this,&NetworkPinger::pingOnce);
    _time->start();
    exec();
}

void NetworkPinger::pause(bool isAPause)
{
    if (isAPause)
        _time->stop();
    else
        _time->start();
}

bool NetworkPinger::isPaused() const
{
    return false;
}



void NetworkPinger::pingOnce()
{
    auto _conn=new QTcpSocket(nullptr);
    _conn->connectToHost("216.58.219.36", 80);
    //_conn->connectToHost("74.125.224.83", 80);
    if (!_conn->waitForConnected(500))
    {
        //qDebug()<<"Not connected" <<_conn->error();
        if (!isPaused())
            emit connectionHit(false);
    }
    else
    {
        //qDebug()<<"Connected!";
        if (!isPaused())
            emit connectionHit(true);
    }
    delete _conn;
}


#ifndef NETWORKPINGER_H
#define NETWORKPINGER_H

#include <QThread>
#include <QTimer>

class QTcpSocket;

class NetworkPinger : public QThread
{
    Q_OBJECT
public:
    explicit NetworkPinger();
    virtual ~NetworkPinger();
    virtual void run() override;

    bool isPaused() const;
signals:
    void connectionHit(bool worked);
public slots:
    // true is pause, false is unpause
    void pause(bool isAPause=true);

    void pingOnce();
private:
//    QTcpSocket* _conn=nullptr;
    QTimer* _time=nullptr;
};

#endif // NETWORKPINGER_H

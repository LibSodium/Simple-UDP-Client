#ifndef MYUDPCLIENT_H
#define MYUDPCLIENT_H

#include <QUdpSocket>

class MyUdpClient : public QObject 
{
    Q_OBJECT
public:
    MyUdpClient(qint16 port);
    
public slots:
    void onReadyRead();
    void send(QByteArray data, QHostAddress address, quint16 port);
    
private:
    qint16 port_;
    QUdpSocket *socket_;
};

#endif // MYUDPCLIENT_H

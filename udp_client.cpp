#include "udp_client.h"

MyUdpClient::MyUdpClient(qint16 port) : QObject(NULL)
{
    socket_ = new QUdpSocket;
    QObject::connect(socket_, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    socket_->bind(port);
}

void MyUdpClient::onReadyRead()
{
    QByteArray buffer;
    buffer.resize(socket_->pendingDatagramSize());
    QHostAddress sender;
    quint16 port;
    socket_->readDatagram(buffer.data(), buffer.size(), &sender, &port);
}

void MyUdpClient::send(QByteArray data, QHostAddress address, quint16 port)
{
    if(!socket_->writeDatagram(data, address, port)) {
        qDebug() << socket_->errorString();
    } else {
        qDebug() << "written";
    }
}

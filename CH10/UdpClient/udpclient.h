#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <QDialog>
#include<QVBoxLayout>
#include<QTextEdit>
#include<QPushButton>
#include<QUdpSocket>

class UdpClient : public QDialog
{
    Q_OBJECT

public:
    UdpClient(QWidget *parent = nullptr);
    ~UdpClient();
private:
    QTextEdit *ReceiveTextEdit;
    QPushButton *CloseBtn;
    QVBoxLayout *mainLayout;
    int port;
    QUdpSocket *udpSocket;
public slots:
    void CloseBtnClicked();
    void dataReceived();

};
#endif // UDPCLIENT_H

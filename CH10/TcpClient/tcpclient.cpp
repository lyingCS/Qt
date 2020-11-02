#include "tcpclient.h"
#include<QMessageBox>
#include<QHostInfo>
#include<QtDebug>

TcpClient::TcpClient(QWidget *parent,Qt::WindowFlags f)
    : QDialog(parent)
{
    setWindowTitle("TCP Client");
    contentListWidget=new QListWidget;
    sendLineEdit=new QLineEdit;
    sendBtn=new QPushButton("send");
    userNameLabel=new QLabel("username: ");
    userNameLineEdit=new QLineEdit;
    serverIPLabel=new QLabel("IP address: ");
    serverIPLineEdit=new QLineEdit;
    portLabel=new QLabel("port: ");
    portLineEdit=new QLineEdit;
    enterBtn=new QPushButton("Enter a chat room");
    mainLayout=new QGridLayout(this);
    mainLayout->addWidget(contentListWidget,0,0,1,2);
    mainLayout->addWidget(sendLineEdit,1,0);
    mainLayout->addWidget(sendBtn,1,1);
    mainLayout->addWidget(userNameLabel,2,0);
    mainLayout->addWidget(userNameLineEdit,2,1);
    mainLayout->addWidget(serverIPLabel,3,0);
    mainLayout->addWidget(serverIPLineEdit,3,1);
    mainLayout->addWidget(portLabel,4,0);
    mainLayout->addWidget(portLineEdit,4,1);
    mainLayout->addWidget(enterBtn,5,0,1,2);

    status=false;
    port=8010;
    portLineEdit->setText(QString::number(port));
    serverIP=new QHostAddress();
    connect(enterBtn,SIGNAL(clicked()),this,SLOT(slotEnter()));
    connect(sendBtn,SIGNAL(clicked()),this,SLOT(slotSend()));
    sendBtn->setEnabled(false);
}

TcpClient::~TcpClient()
{
}

void TcpClient::slotEnter()
{
    if(!status)
    {
        QString ip=serverIPLineEdit->text();
        if(!serverIP->setAddress(ip))
        {
            QMessageBox::information(this,"error","server ip address error!");
            return;
        }
        if(userNameLineEdit->text()=="")
        {
            QMessageBox::information(this,"error","server name error!");
            return;
        }
        userName=userNameLineEdit->text();
        tcpSocket=new QTcpSocket(this);
        connect(tcpSocket,SIGNAL(connected()),this,SLOT(slotConnected()));
        connect(tcpSocket,SIGNAL(disconnected()),this,SLOT(slotDisconnected()));
        connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(dataReceived()));
        tcpSocket->connectToHost(*serverIP,port);
        status=true;
    }
    else
    {
        int length=0;
        QString msg=userName+(": Leave Chat Room");
        if((length=tcpSocket->write(msg.toLatin1(),msg.length()))!=msg.length())
        {
            qDebug()<<1;
            return;
        }
        tcpSocket->disconnectFromHost();
        status=false;
    }
}

void TcpClient::slotConnected()
{
    sendBtn->setEnabled(true);
    enterBtn->setText("Leave");
    int length=0;
    QString msg=userName+(": Enter Chat Room");
    if((length=tcpSocket->write(msg.toLatin1(),msg.length()))!=msg.length())
    {
        return;
    }
}

void TcpClient::slotSend()
{
    if(sendLineEdit->text()=="")
        return;
    QString msg=userName+": "+sendLineEdit->text();
    tcpSocket->write(msg.toLatin1(),msg.length());
    sendLineEdit->clear();
}

void TcpClient::slotDisconnected()
{
    sendBtn->setEnabled(false);
    enterBtn->setText("Enter a chat room");
}

void TcpClient::dataReceived()
{
    while(tcpSocket->bytesAvailable()>0)
    {
        QByteArray datagram;
        datagram.resize(tcpSocket->bytesAvailable());
        tcpSocket->read(datagram.data(),datagram.size());
        QString msg=datagram.data();
        contentListWidget->addItem(msg.left(datagram.size()));
    }
}
































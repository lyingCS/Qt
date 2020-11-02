#include "udpserver.h"
#include<QHostAddress>

UdpServer::UdpServer(QWidget *parent,Qt::WindowFlags f)
    : QDialog(parent,f)
{
    setWindowTitle("UDP Server");
    TimerLabel=new QLabel("Timer",this);
    TextLineEdit=new QLineEdit(this);
    StartBtn=new QPushButton("Start",this);

    mainLayout=new QVBoxLayout(this);
    mainLayout->addWidget(TimerLabel);
    mainLayout->addWidget(TextLineEdit);
    mainLayout->addWidget(StartBtn);

    connect(StartBtn,SIGNAL(clicked()),this,SLOT(StartBtnClicked()));
    port=5555;
    isStarted=false;
    udpSocket=new QUdpSocket(this);
    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timeout()));
}

UdpServer::~UdpServer()
{
}

void UdpServer::StartBtnClicked()
{
    if(!isStarted)
    {
        StartBtn->setText("Stop");
        timer->start(1000);
        isStarted=true;
    }
    else
    {
        StartBtn->setText("Start");
        isStarted=false;
        timer->stop();
    }
}

void UdpServer::timeout()
{
    QString msg=TextLineEdit->text();
    int length=0;
    if(msg=="")
    {
        return;
    }
    if((length=udpSocket->writeDatagram(msg.toLatin1(),msg.length(),QHostAddress::Broadcast,port))!=msg.length())
    {
        return;
    }
}

















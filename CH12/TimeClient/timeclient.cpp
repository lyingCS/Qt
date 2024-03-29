#include "timeclient.h"
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QGridLayout>
#include<QDataStream>
#include<QMessageBox>

TimeClient::TimeClient(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Muitithreaded time client");
    serverNameLabel=new QLabel("Server name: ");
    serverNameLineEdit=new QLineEdit("Localhost");
    portLabel=new QLabel("port: ");
    portLineEdit=new QLineEdit;
    QGridLayout *layout=new QGridLayout;
    layout->addWidget(serverNameLabel,0,0);
    layout->addWidget(serverNameLineEdit,0,1);
    layout->addWidget(portLabel,1,0);
    layout->addWidget(portLineEdit,1,1);
    dateTimeEdit=new QDateTimeEdit(this);
    QHBoxLayout *layout1=new QHBoxLayout;
    layout1->addWidget(dateTimeEdit);
    stateLabel=new QLabel("Please start the time server first!");
    QHBoxLayout *layout2=new QHBoxLayout;
    layout2->addWidget(stateLabel);
    getBtn=new QPushButton("Get time");
    getBtn->setDefault(true);
    getBtn->setEnabled(false);
    quitBtn=new QPushButton("Quit");
    QHBoxLayout *layout3=new QHBoxLayout;
    layout3->addStretch();
    layout3->addWidget(getBtn);
    layout3->addWidget(quitBtn);
    QVBoxLayout *mainLayout=new QVBoxLayout(this);
    mainLayout->addLayout(layout);
    mainLayout->addLayout(layout1);
    mainLayout->addLayout(layout2);
    mainLayout->addLayout(layout3);
    connect(serverNameLineEdit,SIGNAL(textChanged(QString)),this,SLOT(enableGetBtn()));
    connect(portLineEdit,SIGNAL(textChanged(QString)),this,SLOT(enableGetBtn()));
    connect(getBtn,SIGNAL(clicked()),this,SLOT(getTime()));
    connect(quitBtn,SIGNAL(clicked()),this,SLOT(close()));
    tcpSocket=new QTcpSocket(this);
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readTime()));
    connect(tcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(showError(QAbstractSocket::SocketError)));
    portLineEdit->setFocus();
}

TimeClient::~TimeClient()
{
}

void TimeClient::enableGetBtn()
{
    getBtn->setEnabled(!serverNameLineEdit->text().isEmpty()&&!portLineEdit->text().isEmpty());
}

void TimeClient::getTime()
{
    getBtn->setEnabled(false);
    time2u=0;
    tcpSocket->abort();
    tcpSocket->connectToHost(serverNameLineEdit->text(),portLineEdit->text().toInt());
}

void TimeClient::readTime()
{
    QDataStream in(tcpSocket);
    in.setVersion(QDataStream::Qt_5_11);
    if(time2u==0)
    {
        if(tcpSocket->bytesAvailable()<(int)sizeof(uint))
            return;
        in>>time2u;
    }
    dateTimeEdit->setDateTime(QDateTime::fromTime_t(time2u));
    getBtn->setEnabled(true);
}

void TimeClient::showError(QAbstractSocket::SocketError socketError)
{
    switch (socketError)
    {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::information(this,"Time client","Host unreachable");
        break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::information(this,"Time client","Connection refused");
        break;
    default:
        QMessageBox::information(this,"Time client",tr("Produces the following error: %1").arg(tcpSocket->errorString()));
        break;
    }
    getBtn->setEnabled(true);
}


























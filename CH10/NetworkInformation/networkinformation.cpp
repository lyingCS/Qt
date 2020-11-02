#include "networkinformation.h"
#include<QHostInfo>
#include<QNetworkInterface>

NetworkInformation::NetworkInformation(QWidget *parent)
    : QWidget(parent)
{
    hostLabel=new QLabel("host name: ");
    LineEditLocalHostName=new QLineEdit;
    ipLabel=new QLabel("IP address: ");
    LineEditAddress=new QLineEdit;
    detailBtn=new QPushButton("detail");
    mainLayout=new QGridLayout(this);
    mainLayout->addWidget(hostLabel,0,0);
    mainLayout->addWidget(LineEditLocalHostName,0,1);
    mainLayout->addWidget(ipLabel,1,0);
    mainLayout->addWidget(LineEditAddress,1,1);
    mainLayout->addWidget(detailBtn,2,0,1,2);
    getHostInfomation();
    connect(detailBtn,SIGNAL(clicked()),this,SLOT(slotDetail()));
}

NetworkInformation::~NetworkInformation()
{
}

void NetworkInformation::getHostInfomation()
{
    QString localHostName=QHostInfo::localHostName();
    LineEditLocalHostName->setText(localHostName);
    QHostInfo hostInfo=QHostInfo::fromName(localHostName);

    QList<QHostAddress> listAddress=hostInfo.addresses();
    if(!listAddress.isEmpty())
    {
        LineEditAddress->setText(listAddress.at(2).toString());
    }
}

void NetworkInformation::slotDetail()
{
    QString detail="";
    QList<QNetworkInterface> list=QNetworkInterface::allInterfaces();

    for (int i=0;i<list.count();i++) {
        QNetworkInterface interface=list.at(i);
        detail=detail+"devices: "+interface.name()+'\n';
        detail=detail+"hardware address: "+interface.hardwareAddress()+'\n';
        QList<QNetworkAddressEntry> entryList=interface.addressEntries();
        for(int j=1;j<entryList.count();j++){
            QNetworkAddressEntry entry=entryList.at(j);
            detail=detail+'\t'+"IP address: "+entry.ip().toString()+'\n';
            detail=detail+'\t'+"netmask: "+entry.netmask().toString()+'\n';
            detail=detail+'\t'+"broadcast: "+entry.broadcast().toString()+'\n';
        }
    }
    QMessageBox::information(this,"Detail",detail);
}























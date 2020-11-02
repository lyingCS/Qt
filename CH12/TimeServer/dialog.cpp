#include "dialog.h"
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QMessageBox>
#include"timeserver.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Multithreaded time server");
    Label1=new QLabel("Server port: ");
    Label2=new QLabel;
    quitBtn=new QPushButton("quit");
    QHBoxLayout *BtnLayout=new QHBoxLayout;
    BtnLayout->addStretch(1);
    BtnLayout->addWidget(quitBtn);
    BtnLayout->addStretch(1);
    QVBoxLayout *mainLayout=new QVBoxLayout(this);
    mainLayout->addWidget(Label1);
    mainLayout->addWidget(Label2);
    mainLayout->addLayout(BtnLayout);
    connect(quitBtn,SIGNAL(clicked()),this,SLOT(close()));
    count=0;
    timeServer=new TimeServer(this);
    if(!timeServer->listen())
    {
        QMessageBox::critical(this,"Multithreaded time server",tr("Unable to start the server: %1.").arg(timeServer->errorString()));
        close();
        return;
    }
    Label1->setText(tr("Server port: %1").arg(timeServer->serverPort()));
}

Dialog::~Dialog()
{
}

void Dialog::slotShow()
{
    Label2->setText(tr("The %1th request is complete.").arg(++count));
}

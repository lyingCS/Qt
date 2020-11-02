#include "threaddlg.h"
#include<QHBoxLayout>

ThreadDlg::ThreadDlg(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Thread");
    startBtn=new QPushButton("Start");
    stopBtn=new QPushButton("Stop");
    quitBtn=new QPushButton("Quit");
    QHBoxLayout *mainLayout=new QHBoxLayout(this);
    mainLayout->addWidget(startBtn);
    mainLayout->addWidget(stopBtn);
    mainLayout->addWidget(quitBtn);
    connect(startBtn,SIGNAL(clicked()),this,SLOT(slotStart()));
    connect(stopBtn,SIGNAL(clicked()),this,SLOT(slotStop()));
    connect(quitBtn,SIGNAL(clicked()),this,SLOT(close()));
}

ThreadDlg::~ThreadDlg()
{
}

void ThreadDlg::slotStart()
{
    for(int i=0;i<MAXSIZE;i++)
    {
        workThread[i]=new WorkThread();
    }
    for(int i=0;i<MAXSIZE;i++)
    {
        workThread[i]->start();
    }
    startBtn->setEnabled(false);
    stopBtn->setEnabled(true);
}

void ThreadDlg::slotStop()
{
    for(int i=0;i<MAXSIZE;i++)
    {
        workThread[i]->terminate();
        workThread[i]->wait();
    }
    startBtn->setEnabled(true);
    stopBtn->setEnabled(false);
}

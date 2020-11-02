#include "msgboxdlg.h"
#include<QMessageBox>

MsgBoxDlg::MsgBoxDlg(QWidget* parent):QDialog(parent)
{
    setWindowTitle(tr("Msg dialog"));
    label=new QLabel;
    label->setText(tr("Please choose a kind of Msg"));
    questionBtn=new QPushButton;
    questionBtn->setText(tr("QuestionMsg"));
    informatonBtn=new QPushButton;
    informatonBtn->setText(tr("InformationMsg"));
    warningBtn=new QPushButton;
    warningBtn->setText(tr("WarningMsg"));
    criticalBtn=new QPushButton;
    criticalBtn->setText(tr("CriticalMsg"));
    aboutBtn=new QPushButton;
    aboutBtn->setText(tr("AboutMsg"));
    aboutQtBtn=new QPushButton;
    aboutQtBtn->setText(tr("AboutQtMsg"));

    mainLayout=new QGridLayout(this);
    mainLayout->addWidget(label,0,0,1,2);
    mainLayout->addWidget(questionBtn,1,0);
    mainLayout->addWidget(informatonBtn,1,1);
    mainLayout->addWidget(warningBtn,2,0);
    mainLayout->addWidget(criticalBtn,2,1);
    mainLayout->addWidget(aboutBtn,3,0);
    mainLayout->addWidget(aboutQtBtn,3,1);

    connect(questionBtn,SIGNAL(clicked()),this,SLOT(showQuestionMsg()));
    connect(informatonBtn,SIGNAL(clicked()),this,SLOT(showInformationMsg()));
    connect(warningBtn,SIGNAL(clicked()),this,SLOT(showWarningMsg()));
    connect(criticalBtn,SIGNAL(clicked()),this,SLOT(showCritialMsg()));
    connect(aboutBtn,SIGNAL(clicked()),this,SLOT(showAboutMsg()));
    connect(aboutQtBtn,SIGNAL(clicked()),this,SLOT(showAboutQtMsg()));

}

void MsgBoxDlg::showQuestionMsg()
{
    label->setText(tr("Question Message Box"));
    switch (QMessageBox::question(this,tr("Question Message"),\
                                  tr("Save successfully,do you want to quit the program?"),\
                                  QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok))
    {
    case QMessageBox::Ok:
        label->setText("Question button/Ok");
        break;
    case QMessageBox::Cancel:
        label->setText("Question button/Cancel");
        break;
    default:
        break;
    }
    return;
}

void MsgBoxDlg::showInformationMsg()
{
    label->setText(tr("Information Message Box"));
    QMessageBox::information(this,tr("Information Msg"),\
                             tr("Welcome to Information dialog test!"));
    return;
}

void MsgBoxDlg::showWarningMsg()
{
    label->setText(tr("Warning Message Box"));
    switch (QMessageBox::warning(this,tr("Warning Msg")\
                                 ,tr("Your information wasn't saved, do you want to quit?"),\
                                 QMessageBox::Save|QMessageBox::Discard|QMessageBox::Cancel,QMessageBox::Save))
    {
    case QMessageBox::Save:
        label->setText(tr("Warning button/Save"));
        break;
    case QMessageBox::Discard:
        label->setText(tr("Warning button/Discard"));
        break;
    case QMessageBox::Cancel:
        label->setText(tr("Warning button/Cancel"));
        break;
    default:
        break;
    }
    return;
}

void MsgBoxDlg::showCritialMsg()
{
    label->setText(tr("Critical Message Box"));
    QMessageBox::critical(this,tr("Critical Msg"),tr("This is a critical dialog test!"));
    return;
}

void MsgBoxDlg::showAboutMsg()
{
    label->setText(tr("About Message Box"));
    QMessageBox::about(this,tr("About Msg"),tr("This is an about dialog test!"));
    return;
}

void MsgBoxDlg::showAboutQtMsg()
{
    label->setText(tr("About Qt Message Box"));
    QMessageBox::aboutQt(this,tr("About Qt Msg"));
    return;
}





































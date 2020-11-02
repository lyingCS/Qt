#include "dialog.h"
#include<QPushButton>
#include<QFileDialog>
#include<QGridLayout>
#include<QColorDialog>
#include<QFontDialog>
#include<QMessageBox>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("All kinds of dialog exmple"));

    fileBtn=new QPushButton;
    fileBtn->setText(tr("File dialog example"));
    fileLIneEdit=new QLineEdit;
    mainLayout=new QGridLayout(this);
    mainLayout->addWidget(fileBtn,0,0);
    mainLayout->addWidget(fileLIneEdit,0,1);
    connect(fileBtn,SIGNAL(clicked()),this,SLOT(showFile()));

    colorBtn=new QPushButton;
    colorBtn->setText(tr("Color dialog example"));
    colorFrame=new QFrame;
    colorFrame->setFrameShape(QFrame::Box);
    colorFrame->setAutoFillBackground(true);
    mainLayout->addWidget(colorBtn,1,0);
    mainLayout->addWidget(colorFrame,1,1);
    connect(colorBtn,SIGNAL(clicked()),this,SLOT(showColor()));

    fontBtn=new QPushButton;
    fontBtn->setText(tr("Font dialog Example"));
    fontLineEdit=new QLineEdit;
    fontLineEdit->setText(tr("Welcome"));
    mainLayout->addWidget(fontBtn,2,0);
    mainLayout->addWidget(fontLineEdit,2,1);
    connect(fontBtn,SIGNAL(clicked()),this,SLOT(showFont()));

    inputBtn=new QPushButton;
    inputBtn->setText(tr("Input dialog example"));
    mainLayout->addWidget(inputBtn,3,0);
    connect(inputBtn,SIGNAL(clicked()),this,SLOT(showInputDig()));

    MsgBtn=new QPushButton;
    MsgBtn->setText(tr("Msg dialog"));
    mainLayout->addWidget(MsgBtn,3,1);
    connect(MsgBtn,SIGNAL(clicked()),this,SLOT(showMsgDlg()));

    CustomBtn=new QPushButton;
    CustomBtn->setText(tr("Custom dialog example"));
    label=new QLabel;
    label->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    mainLayout->addWidget(CustomBtn,4,0);
    mainLayout->addWidget(label,4,1);
    connect(CustomBtn,SIGNAL(clicked()),this,SLOT(showCustomDlg()));
}

Dialog::~Dialog()
{
}

void Dialog::showFile()
{
    QString s=QFileDialog::getOpenFileName(this,"open file dialog","/","C++ files(*.cpp);;C files(*.c);;Head files(*.h)");
    fileLIneEdit->setText(s);
}

void Dialog::showColor()
{
    QColor c=QColorDialog::getColor((Qt::blue));
    if(c.isValid()){
        colorFrame->setPalette(QPalette(c));
    }
}

void Dialog::showFont()
{
    bool ok;
    QFont f=QFontDialog::getFont(&ok);
    if(ok){
        fontLineEdit->setFont(f);
    }
}

void Dialog::showInputDig()
{
    inputDlg=new Inputdlg(this);
    inputDlg->show();
}

void Dialog::showMsgDlg()
{
    msgDlg=new MsgBoxDlg();
    msgDlg->show();
}

void Dialog::showCustomDlg()
{
    label->setText(tr("Custom Message Box"));
    QMessageBox customMsgBox;
    customMsgBox.setWindowTitle(tr("Custom Msg"));
    QPushButton *yesBtn=customMsgBox.addButton(tr("Yes"),QMessageBox::ActionRole);
    QPushButton *noBtn=customMsgBox.addButton(tr("No"),QMessageBox::ActionRole);
    QPushButton *cancelBtn=customMsgBox.addButton(QMessageBox::Cancel);
    customMsgBox.setText(tr("This is a custom Msg Box"));
    customMsgBox.setIconPixmap(QPixmap("Qt.png"));
    customMsgBox.exec();
    if(customMsgBox.clickedButton()==yesBtn)
        label->setText("Custom Message Box/Yes");
    if(customMsgBox.clickedButton()==noBtn)
        label->setText("Custom Message Box/No");
    if(customMsgBox.clickedButton()==cancelBtn)
        label->setText("Custom Message Box/Cancel");
    return;
}

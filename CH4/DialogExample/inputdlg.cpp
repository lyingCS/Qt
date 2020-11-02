#include "inputdlg.h"
#include<QInputDialog>

Inputdlg::Inputdlg(QWidget* parent):QDialog(parent)
{
    setWindowTitle(tr("Input dialog example"));
    nameLabel1=new QLabel;
    nameLabel1->setText(tr("Name: "));
    nameLabel2=new QLabel;
    nameLabel2->setText(tr("Peter Parker"));
    nameLabel2->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    nameBtn=new QPushButton;
    nameBtn->setText(tr("Change the name"));

    sexLabel1=new QLabel;
    sexLabel1->setText(tr("Sex: "));
    sexLabel2=new QLabel;
    sexLabel2->setText(tr("male"));
    sexLabel2->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    sexBtn=new QPushButton;
    sexBtn->setText(tr("Change the sex"));

    ageLabel1=new QLabel;
    ageLabel1->setText(tr("Age: "));
    ageLabel2=new QLabel;
    ageLabel2->setText(tr("21"));
    ageLabel2->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    ageBtn=new QPushButton;
    ageBtn->setText(tr("Change the age"));

    scoreLabel1=new QLabel;
    scoreLabel1->setText(tr("Score: "));
    scoreLabel2=new QLabel;
    scoreLabel2->setText(tr("80"));
    scoreLabel2->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    scoreBtn=new QPushButton;
    scoreBtn->setText(tr("Change the score"));

    mainLayout=new QGridLayout(this);
    mainLayout->addWidget(nameLabel1,0,0);
    mainLayout->addWidget(nameLabel2,0,1);
    mainLayout->addWidget(nameBtn,0,2);

    mainLayout->addWidget(sexLabel1,1,0);
    mainLayout->addWidget(sexLabel2,1,1);
    mainLayout->addWidget(sexBtn,1,2);

    mainLayout->addWidget(ageLabel1,2,0);
    mainLayout->addWidget(ageLabel2,2,1);
    mainLayout->addWidget(ageBtn,2,2);

    mainLayout->addWidget(scoreLabel1,3,0);
    mainLayout->addWidget(scoreLabel2,3,1);
    mainLayout->addWidget(scoreBtn,3,2);

    mainLayout->setMargin(15);
    mainLayout->setSpacing(10);

    connect(nameBtn,SIGNAL(clicked()),this,SLOT(ChangeName()));
    connect(sexBtn,SIGNAL(clicked()),this,SLOT(ChangeSex()));
    connect(ageBtn,SIGNAL(clicked()),this,SLOT(ChangeAge()));
    connect(scoreBtn,SIGNAL(clicked()),this,SLOT(ChangeScore()));

}

void Inputdlg::ChangeAge()
{
    bool ok;
    int age=QInputDialog::getInt(this,tr("Int dialog"),tr("Please input your age: "),\
                                 ageLabel2->text().toInt(&ok),0,100,1,&ok);
    if(ok)
    {
        ageLabel2->setText(QString(tr("%1").arg(age)));
    }

}
void Inputdlg::ChangeSex()
{
    QStringList SexItems;
    SexItems<<tr("male")<<tr("female");
    bool ok;
    QString Sexitem=QInputDialog::getItem(this,tr("Item dialog"),tr("Please choose your sex")\
                                          ,SexItems,0,false,&ok);
    if(ok&&!Sexitem.isEmpty())
    {
        sexLabel2->setText(Sexitem);
    }

}
void Inputdlg::ChangeName()
{
    bool ok;
    QString text=QInputDialog::getText(this,tr("Input Dialog"),tr("Please input the name: ")\
                                       ,QLineEdit::Normal,nameLabel2->text(),&ok);
    if(ok&&!text.isEmpty())
    {
        nameLabel2->setText(text);
    }
}
void Inputdlg::ChangeScore()
{
    bool ok;
    double score=QInputDialog::getDouble(this,tr("Double dialog"),tr("Please input your score: "),\
                                         scoreLabel2->text().toDouble(&ok),0,100,1,&ok);
    if(ok)
    {
        scoreLabel2->setText(QString(tr("%1")).arg(score));
    }
}





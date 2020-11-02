#include "extensiondlg.h"
#include<QVBoxLayout>
#include<QLabel>
#include<QLineEdit>
#include<QComboBox>
#include<QPushButton>
#include<QDialogButtonBox>
#include<QHBoxLayout>

ExtensionDlg::ExtensionDlg(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("Extension Dialog"));
    createBaseInfo();
    createDetailInfo();
    QVBoxLayout *layout=new QVBoxLayout(this);
    layout->addWidget(baseWidget);
    layout->addWidget(detailWidget);
    layout->setSizeConstraint(QLayout::SetFixedSize);
    layout->setSpacing(10);
}

ExtensionDlg::~ExtensionDlg()
{
}

void ExtensionDlg::createBaseInfo()
{
    baseWidget=new QWidget;
    QLabel *nameLabel=new QLabel(tr("Name: "));
    QLineEdit *nameLineEdit=new QLineEdit;
    QLabel *sexLabel=new QLabel(tr("Sex: "));
    QComboBox *sexComboBox=new QComboBox;
    sexComboBox->insertItem(0,tr("female"));
    sexComboBox->insertItem(1,tr("male"));
    QGridLayout *leftLayout=new QGridLayout;
    leftLayout->addWidget(nameLabel,0,0);
    leftLayout->addWidget(nameLineEdit,0,1);
    leftLayout->addWidget(sexLabel);
    leftLayout->addWidget(sexComboBox);
    QPushButton *OKBtn=new QPushButton(tr("Yes"));
    QPushButton *DetailBtn=new QPushButton(tr("Detail"));
    QDialogButtonBox *btnBox=new QDialogButtonBox(Qt::Vertical);
    btnBox->addButton(OKBtn,QDialogButtonBox::ActionRole);
    btnBox->addButton(DetailBtn,QDialogButtonBox::ActionRole);
    QHBoxLayout *mainlayout=new QHBoxLayout(baseWidget);
    mainlayout->addLayout(leftLayout);
    mainlayout->addWidget(btnBox);
    connect(DetailBtn,SIGNAL(clicked()),this,SLOT(showDetailInfo()));
}

void ExtensionDlg::createDetailInfo()
{
    detailWidget=new QWidget;
    QLabel *ageLabel=new QLabel(tr("Age: "));
    QLineEdit *ageLineEdit=new QLineEdit;
    ageLineEdit->setText(tr("30"));
    QLabel *departmentLabel=new QLabel(tr("Department: "));
    QComboBox *departmentComboBox=new QComboBox;
    departmentComboBox->addItem(tr("department1"));
    departmentComboBox->addItem(tr("department2"));
    departmentComboBox->addItem(tr("department3"));
    departmentComboBox->addItem(tr("department4"));
    QLabel *emailLabel=new QLabel(tr("email: "));
    QLineEdit *emailLineEdit=new QLineEdit;
    QGridLayout *mainlayout=new QGridLayout(detailWidget);
    mainlayout->addWidget(ageLabel,0,0);
    mainlayout->addWidget(ageLineEdit,0,1);
    mainlayout->addWidget(departmentLabel,1,0);
    mainlayout->addWidget(departmentComboBox,1,1);
    mainlayout->addWidget(emailLabel,2,0);
    mainlayout->addWidget(emailLineEdit,2,1);
    detailWidget->hide();
}

void ExtensionDlg::showDetailInfo()
{
    if(detailWidget->isHidden())
    {
        detailWidget->show();
    }
    else detailWidget->hide();
}

























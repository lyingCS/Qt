#include "detail.h"

Detail::Detail(QWidget *parent) : QWidget(parent)
{
    NationalLabel=new QLabel(tr("Country: "));
    NationalComboBox=new QComboBox;
    NationalComboBox->insertItem(0,tr("china"));
    NationalComboBox->insertItem(1,tr("America"));
    NationalComboBox->insertItem(2,tr("British"));

    ProvinceLabel=new QLabel(tr("Province: "));
    ProvinceComboBox=new QComboBox;
    ProvinceComboBox->insertItem(0,tr("JiangSu Province"));
    ProvinceComboBox->insertItem(1,tr("ShangDong Province"));
    ProvinceComboBox->insertItem(2,tr("ZheJiang Province"));

    CityLabel=new QLabel(tr("City: "));
    CityLineEdit=new QLineEdit;
    IntroductLabel=new QLabel(tr("Introduction"));
    IntroductTextEdit=new QTextEdit;
    mainLayout=new QGridLayout(this);
    mainLayout->setMargin(15);
    mainLayout->setSpacing(10);
    mainLayout->addWidget(NationalLabel,0,0);
    mainLayout->addWidget(NationalComboBox,0,1);
    mainLayout->addWidget(ProvinceLabel,1,0);
    mainLayout->addWidget(ProvinceComboBox,1,1);
    mainLayout->addWidget(CityLabel,2,0);
    mainLayout->addWidget(CityLineEdit,2,1);
    mainLayout->addWidget(IntroductLabel,3,0);
    mainLayout->addWidget(IntroductTextEdit,3,1);
}

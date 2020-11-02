#include "widget.h"
#include<QVBoxLayout>
#include<QTranslator>
#include<QApplication>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    createScreen();
}

Widget::~Widget()
{
}

void Widget::createScreen()
{
    combo=new QComboBox;
    combo->addItem("English","en");
    combo->addItem("Chinese","zh");
    combo->addItem("Latin","la");
    label=new QLabel;
    refreshLabel();
    QVBoxLayout *layout=new QVBoxLayout;
    layout->addWidget(combo,1);
    layout->addWidget(label,5);
    setLayout(layout);
    connect(combo,SIGNAL(currentIndexChanged(int)),this,SLOT(changeLang(int)));
}

void Widget::refreshLabel()
{
    label->setText(tr("TXT_HELLO_WORLD","Hello World"));
}

void Widget::changeLang(int index)
{
    QString langCode=combo->itemData(index).toString();
    changeTr(langCode);
    refreshLabel();
}

void Widget::changeTr(const QString &langCode)
{
    static QTranslator* translator;
    if(translator !=NULL)
    {
        qApp->removeTranslator(translator);
        delete translator;
        translator=NULL;
    }
    translator= new QTranslator;
    QString qmFilename="lang_"+langCode;
    if(translator->load(QString("E:/programme/Qt/CH15/LangSwitch/")+qmFilename))
    {
        qApp->installTranslator(translator);
    }
}

































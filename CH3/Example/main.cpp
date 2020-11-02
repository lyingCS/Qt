#include "content.h"
#include<QApplication>
#include<QTextCodec>
#include<QSplitter>
#include<QListWidget>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont font("AR PL KaittiM GB",12);
    a.setFont(font);

    QSplitter *splitterMain=new QSplitter(Qt::Horizontal,0);
    splitterMain->setOpaqueResize(true);
    QListWidget *list=new QListWidget(splitterMain);
    list->insertItem(0,QObject::tr("Basic Info"));
    list->insertItem(1,QObject::tr("Contacts"));
    list->insertItem(2,QObject::tr("Details"));

    Content *content=new Content(splitterMain);
    QObject::connect(list,SIGNAL(currentRowChanged(int)),content->stack,SLOT(setCurrentIndex(int)));

    splitterMain->setWindowTitle(QObject::tr("Amend the Info"));
    splitterMain->setMinimumSize(splitterMain->minimumSize());
    splitterMain->setMaximumSize(splitterMain->maximumSize());
    splitterMain->show();
//    Content w;
//    w.show();
    return a.exec();
}

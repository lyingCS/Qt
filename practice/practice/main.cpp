#include "mainwindow.h"
#include<QDebug>
#include <QApplication>

int main(int argc, char *argv[])
{
    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();*/
    QList<QString> list;
    {
        QString str("   this is a test string   ");
        list<<str;
    }
    qDebug()<<list[0]<<"How are you";
    qDebug()<<list[0].trimmed();
    return 0;
}

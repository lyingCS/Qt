#include "mainwindow.h"
#include<QTranslator>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator *translator=new QTranslator;
    translator->load("E:/programme/Qt/CH15/testHello/testHello.qm");
    a.installTranslator(translator);
    MainWindow w;
    w.show();
    return a.exec();
}

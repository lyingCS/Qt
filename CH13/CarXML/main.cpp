#include "mainwindow.h"
#include<QDialog>
#include"connectdlg.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ConnDlg dialog;
    if(dialog.exec()!=QDialog::Accepted)
        return -1;
    QFile *carDetails=new QFile("attribs.xml");
    MainWindow window("factory","cars",carDetails);
    window.show();
    return a.exec();
}

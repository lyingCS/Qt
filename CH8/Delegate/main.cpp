#include "mainwindow.h"
#include"datedelegate.h"
#include"spindelegate.h"
#include"combodelegate.h"
#include <QApplication>
#include<QStandardItemModel>
#include<QTableView>
#include<QFile>
#include<QTextStream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QStandardItemModel model(4,4);
    QTableView tableView;
    tableView.setModel(&model);
    DateDelegate dateDelegate;
    ComboDelegate comboDelegate;
    SpinDelegate spinDelegate;
    tableView.setItemDelegateForColumn(3,&spinDelegate);
    tableView.setItemDelegateForColumn(2,&comboDelegate);
    tableView.setItemDelegateForColumn(1,&dateDelegate);
    model.setHeaderData(0,Qt::Horizontal,"Name");
    model.setHeaderData(1,Qt::Horizontal,"Birthday");
    model.setHeaderData(2,Qt::Horizontal,"Job");
    model.setHeaderData(3,Qt::Horizontal,"income");
    QFile file("1.txt");
    if(file.open(QFile::ReadOnly|QFile::Text))
    {
        QTextStream stream(&file);
        QString line;
        model.removeRows(0,model.rowCount(QModelIndex()),QModelIndex());
        int row=0;
        do{
            line=stream.readLine();
            if(!line.isEmpty())
            {
                model.insertRows(row,1,QModelIndex());
                QStringList pieces=line.split(",",QString::SkipEmptyParts);
                model.setData(model.index(row,0,QModelIndex()),pieces.value(0));
                model.setData(model.index(row,1,QModelIndex()),pieces.value(1));
                model.setData(model.index(row,2,QModelIndex()),pieces.value(2));
                model.setData(model.index(row,3,QModelIndex()),pieces.value(3));
            }
        }while(!line.isEmpty());
        file.close();
    }
    tableView.setWindowTitle("Delegate");
    tableView.show();
    return a.exec();
}

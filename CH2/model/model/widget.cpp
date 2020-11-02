#include "widget.h"
#include "./ui_widget.h"
#include<QtDebug>
#include<QVariant>
#include<QColor>
#include<qapplication.h>
#include<qpushbutton.h>
#include<qfont.h>
#include<QLabel>
#include<QDateTime>
#include<QLineEdit>
#include<QHBoxLayout>
#include<QTableView>
#include<QVBoxLayout>
#include<QTableView>
#include<QTableWidget>
#include<QAbstractItemModel>
#include<QAbstractItemView>
#include<QtSql/QSqlDatabase>
#include<QtSql/qsqlquery.h>
#include<QtSql/QSqlTableModel>
#include<QStandardItemModel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QSqlTableModel *model=new QSqlTableModel;
    model->setTable("employee");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    model->removeColumn(0);
    model->setHeaderData(0,Qt::Horizontal,tr("Name"));
    model->setHeaderData(1,Qt::Horizontal,tr("Salary"));
    QTableView *view=new QTableView;
    view->setModel(model);
    view->show();
}

Widget::~Widget()
{
    delete ui;
}


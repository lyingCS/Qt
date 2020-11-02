#include "widget.h"
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
{
    setMinimumSize(200,120);
    setMaximumSize(2000,1200);
//    QWidget *window=new QWidget();
//    window->resize(320,240);
//    window->show();
//    QPushButton*button=new QPushButton(tr("Press me"),window);
//    button->move(100,100);
//    button->show();
//    QLabel *datalabel=new QLabel();
//    QDateTime *datatime=new QDateTime(QDateTime::curren5tDateTime());
//    datalabel->setText(datatime->date().toString());
//    datalabel->setGeometry(750,300,1000,500);
//    QWidget *window=new QWidget;
//    window->resize(1000,1000);
//    window->show();
//    QLabel *label=new QLabel(tr("Name:"));
//    QLineEdit * lineEdit=new QLineEdit();
//    QHBoxLayout *layout=new QHBoxLayout();
//    layout->addWidget(label);
//    layout->addWidget(lineEdit);
//    window->setLayout(layout);
//    QLabel *queryLabel=new QLabel(tr("Query:"));
//    QLineEdit *queryEdit=new QLineEdit();
//    QTableView *resultView=new QTableView();
//    QHBoxLayout*queryLayout=new QHBoxLayout();
//    queryLayout->addWidget(queryLabel);
//    queryLayout->addWidget(queryEdit);
//    QVBoxLayout *mainLayout=new QVBoxLayout();
//    mainLayout->addLayout(queryLayout);
//    mainLayout->addWidget(resultView);
//    window->setLayout(mainLayout);
//    QSqlTableModel *model=new QSqlTableModel;
//    model->setTable("employee");
//    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
//    model->select();
//    model->removeColumn(0);
//    model->setHeaderData(0,Qt::Horizontal,tr("Name"));
//    model->setHeaderData(1,Qt::Horizontal,tr("Salary"));
//    QTableView *view=new QTableView;
//    view->setModel(model);
//    view->show();
    QStandardItemModel *model;
    model=new QStandardItemModel(4,2);
    QPushButton*quit=new QPushButton("Quit",this);
    quit->setGeometry(0,0,750,300);
    quit->setFont(QFont("Times",18,QFont::Bold));
    connect(quit,SIGNAL(clicked()),qApp,SLOT(quit()));
}

Widget::~Widget()
{
}


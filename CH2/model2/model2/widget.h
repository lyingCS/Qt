#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
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
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QTreeWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    void init();
    void updateParentItem(QTreeWidgetItem*item);
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
public slots:
    void treeItemChanged(QTreeWidgetItem* item,int column);
};
#endif // WIDGET_H

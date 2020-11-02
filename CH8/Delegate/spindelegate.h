#ifndef SPINDELEGATE_H
#define SPINDELEGATE_H

#include<QItemDelegate>

class SpinDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    SpinDelegate();
    QWidget * createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

#endif // SPINDELEGATE_H

#ifndef WIDGET_H
#define WIDGET_H
#include<QComboBox>
#include<QLabel>
#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void changeLang(int index);
private:
    void createScreen();
    void changeTr(const QString& langCode);
    void refreshLabel();
    QComboBox *combo;
    QLabel *label;
};
#endif // WIDGET_H

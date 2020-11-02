#ifndef DETAIL_H
#define DETAIL_H

#include <QWidget>
#include<QComboBox>
#include<QLineEdit>
#include<QTextEdit>
#include<QGridLayout>
#include<QLabel>

class Detail : public QWidget
{
    Q_OBJECT
public:
    explicit Detail(QWidget *parent = nullptr);

signals:
public slots:
private:
    QLabel *NationalLabel;
    QComboBox *NationalComboBox;
    QLabel *ProvinceLabel;
    QComboBox *ProvinceComboBox;
    QLabel *CityLabel;
    QLineEdit *CityLineEdit;
    QLabel *IntroductLabel;
    QTextEdit *IntroductTextEdit;
    QGridLayout *mainLayout;

};

#endif // DETAIL_H

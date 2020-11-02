#ifndef NETWORKINFORMATION_H
#define NETWORKINFORMATION_H

#include <QWidget>
#include<QLabel>
#include<QPushButton>
#include<QLineEdit>
#include<QGridLayout>
#include<QMessageBox>

class NetworkInformation : public QWidget
{
    Q_OBJECT

public:
    NetworkInformation(QWidget *parent = nullptr);
    ~NetworkInformation();
    void getHostInfomation();
private:
    QLabel *hostLabel;
    QLineEdit *LineEditLocalHostName;
    QLabel *ipLabel;
    QLineEdit *LineEditAddress;
    QPushButton *detailBtn;
    QGridLayout *mainLayout;
public slots:
    void slotDetail();
};
#endif // NETWORKINFORMATION_H

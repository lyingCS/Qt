/********************************************************************************
** Form generated from reading UI file 'connectdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTDLG_H
#define UI_CONNECTDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_QSqlConnectionDialogUi
{
public:
    QLabel *status_label;
    QGroupBox *connGroupBox;
    QLabel *textLabel2;
    QLabel *textLabel3;
    QComboBox *comboDriver;
    QLineEdit *editDatabase;
    QLineEdit *editUsername;
    QLineEdit *editPassword;
    QLineEdit *editHostname;
    QSpinBox *portSpinBox;
    QLabel *textLabel4;
    QLabel *textLabel4_2;
    QLabel *textLabel5;
    QLabel *textLabel5_2;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *QSqlConnectionDialogUi)
    {
        if (QSqlConnectionDialogUi->objectName().isEmpty())
            QSqlConnectionDialogUi->setObjectName(QString::fromUtf8("QSqlConnectionDialogUi"));
        QSqlConnectionDialogUi->resize(767, 529);
        status_label = new QLabel(QSqlConnectionDialogUi);
        status_label->setObjectName(QString::fromUtf8("status_label"));
        status_label->setGeometry(QRect(20, 370, 731, 71));
        connGroupBox = new QGroupBox(QSqlConnectionDialogUi);
        connGroupBox->setObjectName(QString::fromUtf8("connGroupBox"));
        connGroupBox->setGeometry(QRect(10, 10, 749, 341));
        textLabel2 = new QLabel(connGroupBox);
        textLabel2->setObjectName(QString::fromUtf8("textLabel2"));
        textLabel2->setGeometry(QRect(40, 30, 211, 31));
        textLabel3 = new QLabel(connGroupBox);
        textLabel3->setObjectName(QString::fromUtf8("textLabel3"));
        textLabel3->setGeometry(QRect(40, 130, 211, 31));
        comboDriver = new QComboBox(connGroupBox);
        comboDriver->setObjectName(QString::fromUtf8("comboDriver"));
        comboDriver->setGeometry(QRect(320, 31, 351, 31));
        editDatabase = new QLineEdit(connGroupBox);
        editDatabase->setObjectName(QString::fromUtf8("editDatabase"));
        editDatabase->setEnabled(false);
        editDatabase->setGeometry(QRect(320, 80, 351, 31));
        editUsername = new QLineEdit(connGroupBox);
        editUsername->setObjectName(QString::fromUtf8("editUsername"));
        editUsername->setEnabled(false);
        editUsername->setGeometry(QRect(320, 130, 351, 31));
        editPassword = new QLineEdit(connGroupBox);
        editPassword->setObjectName(QString::fromUtf8("editPassword"));
        editPassword->setEnabled(false);
        editPassword->setGeometry(QRect(320, 180, 351, 31));
        editHostname = new QLineEdit(connGroupBox);
        editHostname->setObjectName(QString::fromUtf8("editHostname"));
        editHostname->setEnabled(false);
        editHostname->setGeometry(QRect(320, 230, 351, 31));
        portSpinBox = new QSpinBox(connGroupBox);
        portSpinBox->setObjectName(QString::fromUtf8("portSpinBox"));
        portSpinBox->setEnabled(false);
        portSpinBox->setGeometry(QRect(320, 280, 351, 31));
        textLabel4 = new QLabel(connGroupBox);
        textLabel4->setObjectName(QString::fromUtf8("textLabel4"));
        textLabel4->setGeometry(QRect(40, 180, 211, 31));
        textLabel4_2 = new QLabel(connGroupBox);
        textLabel4_2->setObjectName(QString::fromUtf8("textLabel4_2"));
        textLabel4_2->setGeometry(QRect(40, 230, 211, 31));
        textLabel5 = new QLabel(connGroupBox);
        textLabel5->setObjectName(QString::fromUtf8("textLabel5"));
        textLabel5->setGeometry(QRect(40, 80, 211, 31));
        textLabel5_2 = new QLabel(connGroupBox);
        textLabel5_2->setObjectName(QString::fromUtf8("textLabel5_2"));
        textLabel5_2->setGeometry(QRect(40, 280, 211, 31));
        okButton = new QPushButton(QSqlConnectionDialogUi);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(280, 460, 191, 51));
        cancelButton = new QPushButton(QSqlConnectionDialogUi);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(540, 460, 181, 51));

        retranslateUi(QSqlConnectionDialogUi);

        QMetaObject::connectSlotsByName(QSqlConnectionDialogUi);
    } // setupUi

    void retranslateUi(QDialog *QSqlConnectionDialogUi)
    {
        QSqlConnectionDialogUi->setWindowTitle(QCoreApplication::translate("QSqlConnectionDialogUi", "Dialog", nullptr));
        status_label->setText(QCoreApplication::translate("QSqlConnectionDialogUi", "status: ", nullptr));
        connGroupBox->setTitle(QCoreApplication::translate("QSqlConnectionDialogUi", "connect setting", nullptr));
        textLabel2->setText(QCoreApplication::translate("QSqlConnectionDialogUi", "driver: ", nullptr));
        textLabel3->setText(QCoreApplication::translate("QSqlConnectionDialogUi", "database name: ", nullptr));
        textLabel4->setText(QCoreApplication::translate("QSqlConnectionDialogUi", "user name: ", nullptr));
        textLabel4_2->setText(QCoreApplication::translate("QSqlConnectionDialogUi", "password: ", nullptr));
        textLabel5->setText(QCoreApplication::translate("QSqlConnectionDialogUi", "host name: ", nullptr));
        textLabel5_2->setText(QCoreApplication::translate("QSqlConnectionDialogUi", "port: ", nullptr));
        okButton->setText(QCoreApplication::translate("QSqlConnectionDialogUi", "connect", nullptr));
        cancelButton->setText(QCoreApplication::translate("QSqlConnectionDialogUi", "quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QSqlConnectionDialogUi: public Ui_QSqlConnectionDialogUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTDLG_H

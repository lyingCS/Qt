/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *InExcelLineEdit;
    QLineEdit *InWordLineEdit;
    QPushButton *writeExcelPushButton;
    QPushButton *writeWordPushButton;
    QLabel *OutExcelLabel;
    QLabel *OutWordLabel;
    QPushButton *readExcelPushButton;
    QPushButton *readWordPushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(721, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 121, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 280, 121, 51));
        label_2->setFont(font);
        InExcelLineEdit = new QLineEdit(centralwidget);
        InExcelLineEdit->setObjectName(QString::fromUtf8("InExcelLineEdit"));
        InExcelLineEdit->setGeometry(QRect(50, 120, 201, 71));
        InWordLineEdit = new QLineEdit(centralwidget);
        InWordLineEdit->setObjectName(QString::fromUtf8("InWordLineEdit"));
        InWordLineEdit->setGeometry(QRect(50, 360, 201, 81));
        writeExcelPushButton = new QPushButton(centralwidget);
        writeExcelPushButton->setObjectName(QString::fromUtf8("writeExcelPushButton"));
        writeExcelPushButton->setGeometry(QRect(160, 210, 91, 41));
        writeWordPushButton = new QPushButton(centralwidget);
        writeWordPushButton->setObjectName(QString::fromUtf8("writeWordPushButton"));
        writeWordPushButton->setGeometry(QRect(160, 459, 80, 41));
        OutExcelLabel = new QLabel(centralwidget);
        OutExcelLabel->setObjectName(QString::fromUtf8("OutExcelLabel"));
        OutExcelLabel->setGeometry(QRect(380, 160, 321, 81));
        OutExcelLabel->setFrameShape(QFrame::Panel);
        OutWordLabel = new QLabel(centralwidget);
        OutWordLabel->setObjectName(QString::fromUtf8("OutWordLabel"));
        OutWordLabel->setGeometry(QRect(380, 410, 321, 81));
        OutWordLabel->setFrameShape(QFrame::Panel);
        readExcelPushButton = new QPushButton(centralwidget);
        readExcelPushButton->setObjectName(QString::fromUtf8("readExcelPushButton"));
        readExcelPushButton->setEnabled(false);
        readExcelPushButton->setGeometry(QRect(370, 80, 101, 41));
        readWordPushButton = new QPushButton(centralwidget);
        readWordPushButton->setObjectName(QString::fromUtf8("readWordPushButton"));
        readWordPushButton->setEnabled(false);
        readWordPushButton->setGeometry(QRect(370, 320, 111, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 721, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Excel\350\257\273\345\206\231", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Word\350\257\273\345\206\231", nullptr));
        InExcelLineEdit->setText(QCoreApplication::translate("MainWindow", "\346\210\221\346\234\200\347\210\261\347\232\204 Qt 5.11", nullptr));
        InWordLineEdit->setText(QCoreApplication::translate("MainWindow", "\346\210\221\346\234\200\347\210\261\347\232\204 Qt 5.11", nullptr));
        writeExcelPushButton->setText(QCoreApplication::translate("MainWindow", "\345\206\231\345\205\245", nullptr));
        writeWordPushButton->setText(QCoreApplication::translate("MainWindow", "\345\206\231\345\205\245", nullptr));
        OutExcelLabel->setText(QString());
        OutWordLabel->setText(QString());
        readExcelPushButton->setText(QCoreApplication::translate("MainWindow", "\350\257\273\345\207\272", nullptr));
        readWordPushButton->setText(QCoreApplication::translate("MainWindow", "\350\257\273\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QLineEdit>
#include<QGridLayout>
#include"inputdlg.h"
#include"msgboxdlg.h"

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
private:
    QPushButton *fileBtn;
    QLineEdit *fileLIneEdit;
    QGridLayout *mainLayout;

    QPushButton *colorBtn;
    QFrame *colorFrame;

    QPushButton *fontBtn;
    QLineEdit *fontLineEdit;

    QPushButton *inputBtn;
    Inputdlg *inputDlg;

    QPushButton *MsgBtn;
    MsgBoxDlg *msgDlg;

    QPushButton *CustomBtn;
    QLabel *label;
private slots:
    void showFile();
    void showColor();
    void showFont();
    void showInputDig();
    void showMsgDlg();
    void showCustomDlg();
};
#endif // DIALOG_H

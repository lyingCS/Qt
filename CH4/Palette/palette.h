#ifndef PALETTE_H
#define PALETTE_H

#include <QMainWindow>
#include<QDialog>
#include <QApplication>
#include<QComboBox>
#include<QLabel>
#include<QTextEdit>
#include<QPushButton>
#include<QLineEdit>


class Palette : public QDialog
{
    Q_OBJECT

public:
    Palette(QWidget *parent = nullptr);
    ~Palette();
    void createCtrlFrame();
    void createContentFrame();
    void fillColorList(QComboBox *);
private slots:
    void ShowWindow();
    void ShowWindowText();
    void ShowButton();
    void ShowButtonText();
    void ShowBase();
private:
    QFrame* ctrlFrame;
    QLabel* windowLabel;
    QComboBox* windowComboBox;
    QLabel *windowTextLabel;
    QComboBox* windowTextComboBox;
    QLabel* buttonLabel;
    QComboBox* buttonComboBox;
    QLabel* buttonTextLabel;
    QComboBox* buttonTextComboBox;
    QLabel* baseLabel;
    QComboBox* baseComboBox;
    QLabel* label1;
    QFrame *contentFrame;
    QComboBox *comboBox1;
    QLabel *label2;
    QLineEdit*lineEdit2;
    QTextEdit*textEdit;
    QPushButton*OkBtn;
    QPushButton*CancelBtn;
};
























#endif // PALETTE_H

#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QLabel>
#include<QLineEdit>
#include<QComboBox>
#include<QTextEdit>
#include<QGridLayout>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
private:
    QLabel *UserNameLabel;
    QLabel *Namelabel;
    QLabel *SexLabel;
    QLabel *DepartmentLabel;
    QLabel *AgeLabel;
    QLabel *OtherLabel;
    QLineEdit *UserNameLineEdit;
    QLineEdit *NameLineEdit;
    QComboBox *SexComBox;
    QTextEdit *DepartmentTextEdit;
    QLineEdit *AgeLineEdit;
    QGridLayout *LeftLayout;

    QLabel *HeadLabel;
    QLabel *HeadIconLabel;
    QPushButton *UpdateHeadBtn;
    QHBoxLayout *TopRightLayout;
    QLabel *IntroductionLabel;
    QTextEdit *IntroductionTextEdit;
    QVBoxLayout *RightLayout;

    QPushButton *OkBtn;
    QPushButton *CancelBtn;
    QHBoxLayout *ButtonLayout;
};
#endif // DIALOG_H

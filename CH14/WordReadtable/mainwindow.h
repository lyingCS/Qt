#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMessageBox>
#include<QAxObject>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_queryPushButton_clicked();

private:
    Ui::MainWindow *ui;
    QAxObject *myword;
    QAxObject *mydocs;
    QAxObject *document;
    QAxObject *mytable;

};
#endif // MAINWINDOW_H

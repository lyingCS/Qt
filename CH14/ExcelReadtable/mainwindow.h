#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMessageBox>
#include<QAxObject>
#include<QAxWidget>
#include<QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void closeExcel();

private slots:
    void on_openPushButton_clicked();
    void view_Excel(QString &filename);
    void on_countPushButton_clicked();

private:
    Ui::MainWindow *ui;
    QAxObject *myexcel;
    QAxObject *myworks;
    QAxObject *workbook;
    QAxObject *mysheets;
    QAxWidget *mywidget;
};
#endif // MAINWINDOW_H

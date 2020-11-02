#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMessageBox>
#include<QAxObject>
#include<QAxWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

typedef struct record{
    QString year;
    QString total;
    QString admit;
    QString rate;
} Record;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_writeTablePushButton_clicked();
    void view_Word(QString& filename);

private:
    Ui::MainWindow *ui;
    QAxObject *myword;
    QAxObject *mydocs;
    QAxObject *document;
    QAxObject *mytable;
    QAxWidget *mywidget;
    QList<Record> myrecord;
};
#endif // MAINWINDOW_H

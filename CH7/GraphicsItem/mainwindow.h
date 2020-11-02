#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QMenuBar>
#include<QGraphicsEllipseItem>
#include"flashitem.h"
#include"startitem.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initScene();
    void createActions();
    void createMenus();
public slots:
    void slotNew();
    void slotAddEllipseItem();
    void slotClear();
    void slotAddPolygonItem();
    void slotAddTextItem();
    void slotAddRectItem();
    void slotAddAlphaItem();
    void slotAddFlashItem();
    void slotAddAnimationItem();
private:
    QGraphicsScene *scene;
    QAction *newAct;
    QAction *clearAct;
    QAction *exitAct;
    QAction *addEllipseItemAct;
    QAction *addPolygonItemAct;
    QAction *addTextItemAct;
    QAction *addRectItemAct;
    QAction *addAlphaItemAct;
    QAction *addFlashItemAct;
    QAction *addAnimItemAct;
};
#endif // MAINWINDOW_H

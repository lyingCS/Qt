#include "mouseevent.h"

MouseEvent::MouseEvent(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Mouse event");
    statusLabel=new QLabel;
    statusLabel->setText("Current location: ");
    statusLabel->setFixedWidth(200);
    MousePosLabel=new QLabel;
    MousePosLabel->setText("");
    MousePosLabel->setFixedWidth(200);
    statusBar()->addPermanentWidget(statusLabel);
    statusBar()->addPermanentWidget(MousePosLabel);
    this->setMouseTracking(true);
    resize(800,400);
}

MouseEvent::~MouseEvent()
{
}

void MouseEvent::mousePressEvent(QMouseEvent *e)
{
    QString str="("+QString::number(e->x())+","+QString::number(e->y())+")";
    if(e->button()==Qt::LeftButton)
    {
        statusBar()->showMessage("Left button: "+str);
    }
    else if(e->button()==Qt::RightButton)
    {
        statusBar()->showMessage("Right button: "+str);
    }
    else if(e->button()==Qt::MidButton)
    {
        statusBar()->showMessage("Mid button: "+str);
    }
}

void MouseEvent::mouseMoveEvent(QMouseEvent *e)
{
    MousePosLabel->setText("("+QString::number(e->x())+","+QString::number(e->y())+")");
}

void MouseEvent::mouseReleaseEvent(QMouseEvent *e)
{
    QString str="("+QString::number(e->x())+","+QString::number(e->y())+")";
    statusBar()->showMessage("Release: "+str,3000);
}

void MouseEvent::mouseDoubleClicked(QMouseEvent *e)
{

}



































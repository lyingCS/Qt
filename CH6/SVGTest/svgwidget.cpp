#include "svgwidget.h"
#include<QtSvg/QtSvg>
#include<QtSvg/QSvgWidget>
#include<QtSvg/QSvgRenderer>
#include<QDebug>

SvgWidget::SvgWidget(QWidget *parent):QSvgWidget(parent)
{
    render=renderer();
}

void SvgWidget::wheelEvent(QWheelEvent *e)
{
    const double diff=0.1;
    QSize size=render->defaultSize();
    int width=size.width();
    int height=size.height();
    qDebug()<<"1";
    if(e->delta()>0)
    {
        width=int(this->width()+this->width()*diff);
        height=int(this->height()+this->height()*diff);
    }
    else
    {
        width=int(this->width()-this->width()*diff);
        height=int(this->height()-this->height()*diff);
    }
    resize(width,height);
}

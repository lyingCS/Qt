#ifndef SVGWINDOW_H
#define SVGWINDOW_H

#include<QtSvg/QtSvg>
#include<QtSvg/QSvgWidget>
#include<QtSvg/QSvgRenderer>

class SvgWindow : public QScrollArea
{
    Q_OBJECT
public:
    SvgWindow(QWidget *parent=0);
    void setFile(QString);
    void mousePressEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
private:
    QSvgWidget *svgWidget;
    QPoint mousePressPos;
    QPoint scrollBarValueOnMousePress;
};

#endif // SVGWINDOW_H

#ifndef BUTTERFLY_H
#define BUTTERFLY_H

#include <QObject>
#include<QGraphicsItem>
#include<QPainter>
#include<QGraphicsScene>
#include<QGraphicsView>

class Butterfly : public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Butterfly(QObject *parent = nullptr);
    void timerEvent(QTimerEvent*);
    QRectF boundingRect() const;

signals:
public slots:
protected:
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
private:
    bool up;
    QPixmap pix_up;
    QPixmap pix_down;
    qreal angle;

};

#endif // BUTTERFLY_H

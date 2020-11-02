#ifndef KEYEVENT_H
#define KEYEVENT_H

#include <QMainWindow>
#include<QPaintEvent>
#include<QKeyEvent>

class KeyEvent : public QMainWindow
{
    Q_OBJECT

public:
    KeyEvent(QWidget *parent = nullptr);
    ~KeyEvent();
    void drawPix();
    void keyPressEvent(QKeyEvent*);
    void paintEvent(QPaintEvent*);
private:
    QPixmap *pix;
    QImage image;
    int startX;
    int startY;
    int width;
    int height;
    int step;
};
#endif // KEYEVENT_H

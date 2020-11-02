#ifndef PRODUCER_H
#define PRODUCER_H

#include <QCoreApplication>
#include<QSemaphore>
#include<QThread>
#include<stdio.h>

const int DataSize=1000;
const int BufferSize=80;
extern int buffer[BufferSize];
extern QSemaphore freeBytes;
extern QSemaphore usedBytes;

class Producer : public QThread
{
    Q_OBJECT
public:
    Producer();
    void run() override;
};

#endif // PRODUCER_H

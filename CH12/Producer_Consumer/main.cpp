#include <QCoreApplication>
#include"head.h"
#include"consumer.h"
#include"producer.h"

int buffer[BufferSize];
QWaitCondition bufferEmpty;
QWaitCondition bufferFull;
QMutex mutex;
int numUsedBytes=0;
int rIndex=0;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Producer producer;
    Consumer consumerA,consumerB;
    producer.start();
    consumerA.start();
    consumerB.start();
    producer.wait();
    consumerA.wait();
    consumerB.wait();
    return a.exec();
}

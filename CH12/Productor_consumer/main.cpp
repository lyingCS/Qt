#include"consumer.h"

QSemaphore freeBytes(80);
QSemaphore usedBytes(0);
int buffer[BufferSize];

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Producer producer;
    Consumer consumer;
    producer.start();
    consumer.start();
    producer.wait();
    consumer.wait();
    return a.exec();
}

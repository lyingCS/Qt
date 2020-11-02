#ifndef CONSUMER_H
#define CONSUMER_H

#include"head.h"

class Consumer : public QThread
{
    Q_OBJECT
public:
    Consumer();
    void run() override;
};

#endif // CONSUMER_H

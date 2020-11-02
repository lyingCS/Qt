#ifndef PRODUCER_H
#define PRODUCER_H

#include"head.h"

class Producer : public QThread
{
    Q_OBJECT
public:
    Producer();
    void run() override;
};

#endif // PRODUCER_H

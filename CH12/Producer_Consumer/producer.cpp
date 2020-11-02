#include "producer.h"

Producer::Producer()
{

}

void Producer::run()
{
    for(int i=0;i<DataSize;i++)
    {
        mutex.lock();
        if(numUsedBytes==BufferSize)
            bufferEmpty.wait(&mutex);
        buffer[i%BufferSize]=i%BufferSize;
        //printf("%d\n",i);
        ++numUsedBytes;
        bufferFull.wakeOne();
        mutex.unlock();
    }
}

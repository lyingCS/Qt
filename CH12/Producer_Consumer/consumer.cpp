#include "consumer.h"

Consumer::Consumer()
{

}

void Consumer::run()
{
    forever
    {
        mutex.lock();
        if(numUsedBytes==0)
            bufferFull.wait(&mutex);
        printf("%ld::[%d]=%d\n",currentThreadId(),rIndex,buffer[rIndex]);
        rIndex=(1+rIndex)%BufferSize;
        --numUsedBytes;
        bufferEmpty.wakeAll();
        mutex.unlock();
    }
}

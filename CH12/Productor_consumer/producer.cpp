#include "producer.h"

Producer::Producer()
{
}

void Producer::run()
{
    for(int i=0;i<DataSize;i++)
    {
        freeBytes.acquire();
        buffer[i%BufferSize]=i%BufferSize;
        usedBytes.release();
    }
}

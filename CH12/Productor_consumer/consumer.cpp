#include "consumer.h"

Consumer::Consumer()
{

}

void Consumer::run()
{
    for(int i=0;i<DataSize;i++)
    {
        usedBytes.acquire();
        fprintf(stderr,"%d",buffer[i%BufferSize]);
        if(i%16==0&&i!=0)
            fprintf(stderr,"\n");
        freeBytes.release();
    }
}

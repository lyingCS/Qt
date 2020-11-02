#ifndef HEAD_H
#define HEAD_H

#include<QCoreApplication>
#include<QWaitCondition>
#include<QMutex>
#include<QThread>
#include<stdio.h>

const int DataSize=1000;
const int BufferSize=80;
extern int buffer[BufferSize];
extern QWaitCondition bufferEmpty;
extern QWaitCondition bufferFull;
extern QMutex mutex;
extern int numUsedBytes;
extern int rIndex;

#endif // HEAD_H

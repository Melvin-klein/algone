#ifndef __ALG_NETWORK_H__
#define __ALG_NETWORK_H__

#include "stdlib.h"

#include "./Layer.h"

typedef struct
{
    Layer **_layers;
    double learningRate;
    size_t _size;
} Network;

Network *ALG_NetworkCreate(int inputSize, double learningRate);
void ALG_NetworkAddLayer(Network *n, size_t size);
void ALG_NetworkDebug(Network *n);
void ALG_NetworkDestroy(Network *n);

#endif

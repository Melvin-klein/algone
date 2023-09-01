#ifndef __ALG_NETWORK_H__
#define __ALG_NETWORK_H__

#include "stdlib.h"

#include "./Layer.h"

typedef struct
{
    ALG_Layer **_layers;
    double learningRate;
    size_t _size;
} ALG_Network;

ALG_Network *ALG_NetworkCreate(int inputSize, double learningRate);
void ALG_NetworkAddLayer(ALG_Network *n, size_t size);
void ALG_NetworkDebug(ALG_Network *n);
void ALG_NetworkDestroy(ALG_Network *n);

#endif

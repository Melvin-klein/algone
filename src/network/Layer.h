#ifndef __ALG_LAYER_H__
#define __ALG_LAYER_H__

#include "./Unit.h"

typedef struct {
    ALG_Unit **units; // Array of units
    size_t size;
} ALG_Layer;

ALG_Layer *ALG_LayerCreate(size_t size, ALG_Layer *previousLayer);
void ALG_LayerDestroy(ALG_Layer* l);
static void _ALG_LayerAddUnit(ALG_Layer *l, size_t size);

#endif

#ifndef __ALG_LAYER_H__
#define __ALG_LAYER_H__

#include "./Unit.h"

typedef struct {
    Unit **units; // Array of units
    size_t size;
} Layer;

Layer *ALG_LayerCreate(size_t size, Layer *previousLayer);
void ALG_LayerDestroy(Layer* l);
static void _ALG_LayerAddUnit(Layer *l, size_t size);

#endif

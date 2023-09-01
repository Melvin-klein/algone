#include "stdlib.h"

#include "./Layer.h"
#include "../error/error.h"

ALG_Layer *ALG_LayerCreate(size_t size, ALG_Layer *previousLayer)
{
    ALG_Layer *l = malloc(sizeof(*l));

    ALG_AssertMemoryAlloc(l, __FILE__, __LINE__);

    l->_size = size;
    l->_units = calloc(l->_size, sizeof(*(l->_units)));

    if (previousLayer != NULL) {
        _ALG_LayerAddUnit(l, previousLayer->_size);
    } else {
        _ALG_LayerAddUnit(l, 0);
    }

    ALG_AssertMemoryAlloc(l->_units, __FILE__, __LINE__);

    return l;
}

void ALG_LayerDestroy(ALG_Layer *l)
{
    for (int i = 0; i < l->_size; i++) {
        ALG_UnitDestroy(l->_units[i]);
    }

    free(l->_units);
    free(l);
}

static void _ALG_LayerAddUnit(ALG_Layer *l, size_t size)
{
    for (int i = 0; i < l->_size; i++) {
        l->_units[i] = ALG_UnitCreate(size);
    }
}

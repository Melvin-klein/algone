#include "stdlib.h"

#include "./Layer.h"
#include "../error/error.h"

ALG_Layer *ALG_CreateLayer(size_t size, ALG_Layer *previousLayer)
{
    ALG_Layer *l = malloc(sizeof(*l));

    ALG_AssertMemoryAlloc(l, __FILE__, __LINE__);

    l->_nbUnits = size;
    l->_units = malloc(sizeof(**l->_units) * l->_nbUnits);

    ALG_AssertMemoryAlloc(l->_units, __FILE__, __LINE__);

    if (previousLayer != NULL) {
        ALG_AddUnitToLayer(l, previousLayer->_nbUnits);
    } else {
        ALG_AddUnitToLayer(l, 0);
    }

    return l;
}

void ALG_DestroyLayer(ALG_Layer *l)
{
    for (int i = 0; i < l->_nbUnits; i++) {
        ALG_DestroyUnit(l->_units[i]);
    }

    free(l->_units);
    free(l);
}

void ALG_AddUnitToLayer(ALG_Layer *l, size_t size)
{
    for (int i = 0; i < l->_nbUnits; i++) {
        l->_units[i] = ALG_CreateUnit(size);
    }
}

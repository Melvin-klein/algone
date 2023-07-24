#include "stdlib.h"

#include "./Layer.h"
#include "../error/error.h"

Layer *ALG_LayerCreate(size_t size, Layer *previousLayer)
{
    Layer *l = malloc(sizeof(*l));

    ALG_AssertMemoryAlloc(l, __FILE__, __LINE__);

    l->size = size;
    l->units = calloc(l->size, sizeof(*(l->units)));

    if (previousLayer != NULL) {
        _ALG_LayerAddUnit(l, previousLayer->size);
    } else {
        _ALG_LayerAddUnit(l, 0);
    }

    ALG_AssertMemoryAlloc(l->units, __FILE__, __LINE__);

    return l;
}

void ALG_LayerDestroy(Layer *l)
{
    for (int i = 0; i < l->size; i++) {
        ALG_UnitDestroy(l->units[i]);
    }

    free(l->units);
    free(l);
}

/**
 * @brief Instanciate layer's units 
 * 
 * @param l The layer to fill with units
 * @param size The size of unit weights array
 */
static void _ALG_LayerAddUnit(Layer *l, size_t size)
{
    for (int i = 0; i < l->size; i++) {
        l->units[i] = ALG_UnitCreate(size);
    }
}

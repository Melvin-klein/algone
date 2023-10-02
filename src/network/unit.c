#include "stdlib.h"
#include "stdio.h"

#include "./unit.h"
#include "../error/error.h"

ALG_Unit *ALG_CreateUnit(size_t size)
{
    ALG_Unit *u = malloc(sizeof(*u));

    if (u == NULL) {
        ALG_SetError(ALG_MEMORY_ALLOCATION_ERROR, "Could not allocate memory", __FILE__, __LINE__);

        return NULL;
    }

    u->_nbWeights = size;
    u->_weights = NULL;
    u->_bias = 0;

    // Input units does not have weights
    if (u->_nbWeights > 0) {
        u->_weights = calloc(u->_nbWeights, sizeof(*(u->_weights)));

        if (u->_weights == NULL) {
            ALG_SetError(ALG_MEMORY_ALLOCATION_ERROR, "Could not allocate memory", __FILE__, __LINE__);

            return NULL;
        }
    }

    return u;
}

void ALG_CreateUnitInLayer(ALG_Layer *l, size_t size)
{
    for (int i = 0; i < l->_nbUnits; i++) {
        l->_units[i] = ALG_CreateUnit(size);
    }
}

void ALG_DestroyUnit(ALG_Unit *u)
{
    free(u->_weights);
    
    free(u);
}

#include "stdlib.h"
#include "stdio.h"

#include "./Unit.h"
#include "../error/error.h"

ALG_Unit *ALG_UnitCreate(size_t size)
{
    ALG_Unit *u = malloc(sizeof(*u));

    ALG_AssertMemoryAlloc(u, __FILE__, __LINE__);

    u->_size = size;
    u->_weights = NULL;

    // Input units does not have weights
    if (u->_size > 0) {
        u->_weights = calloc(u->_size, sizeof(*(u->_weights)));

        ALG_AssertMemoryAlloc(u->_weights, __FILE__, __LINE__);
    }

    return u;
}

void ALG_UnitDestroy(ALG_Unit *u)
{
    free(u->_weights);
    
    free(u);
}

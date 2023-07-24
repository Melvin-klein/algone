#include "stdlib.h"
#include "stdio.h"

#include "./Unit.h"
#include "../error/error.h"

Unit *ALG_UnitCreate(size_t size)
{
    Unit *u = malloc(sizeof(*u));

    ALG_AssertMemoryAlloc(u, __FILE__, __LINE__);

    u->size = size;

    // Input units does not have weights
    if (u->size > 0) {
        u->_weights = calloc(u->size, sizeof(*(u->_weights)));

        ALG_AssertMemoryAlloc(u->_weights, __FILE__, __LINE__);
    }

    return u;
}

void ALG_UnitDestroy(Unit *u)
{
    free(u->_weights);
    
    free(u);
}

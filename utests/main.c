#include "stdlib.h"
#include "stdio.h"

#include "../src/algone.h"

int main()
{
    ALG_SetError(ALG_MATH_ERROR, "This is a Gaston Error.", __FILE__, __LINE__);

    if (ALG_HasError()) {
        ALG_PrintError();
    }

    return EXIT_SUCCESS;
}

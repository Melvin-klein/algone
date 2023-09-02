#include "stdlib.h"

#include "../src/algone.h"

int main()
{
    ALG_Network* n = ALG_NetworkCreate(10);
    ALG_NetworkDebug(n);
    ALG_NetworkAddLayer(n, 10);
    ALG_NetworkDebug(n);
    ALG_NetworkAddLayer(n, 50);
    ALG_NetworkDebug(n);

    return EXIT_SUCCESS;
}

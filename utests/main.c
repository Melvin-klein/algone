#include "stdio.h"
#include "stdlib.h"

#include "../src/algone.h"

int main()
{
    ALG_Network* n = ALG_NetworkCreate(10, 0.1);

    ALG_NetworkAddLayer(n, 50);
    ALG_NetworkAddLayer(n, 50);
    ALG_NetworkDebug(n);
    ALG_NetworkDestroy(n);

    Matrix *m = ALG_MatrixCreate(3, 3, 0);
    ALG_MatrixDebug(m);
    ALG_MatrixFill(m, 1);
    ALG_MatrixDebug(m);
    ALG_MatrixDestroy(m);

    return EXIT_SUCCESS;
}

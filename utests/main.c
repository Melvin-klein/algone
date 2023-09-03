#include "stdlib.h"
#include "stdio.h"

#include "../src/algone.h"

int main()
{
    ALG_Network* n = ALG_NetworkCreate(10);
    ALG_NetworkDebug(n);
    ALG_NetworkAddLayer(n, 10);
    ALG_NetworkDebug(n);
    ALG_NetworkAddLayer(n, 50);
    ALG_NetworkDebug(n);

    double yTrue[5] = {3.43, 2.67, 0.47, -1.34, -0.21};
    double yPred[5] = {2, 5, -2, 3, 0};

    double r = ALG_MeanSquaredError(yPred, yTrue, 5);

    printf("The result is : %f\n", r);

    return EXIT_SUCCESS;
}

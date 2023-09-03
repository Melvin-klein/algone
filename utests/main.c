#include "stdlib.h"
#include "stdio.h"

#include "../src/algone.h"

int main()
{
    ALG_Network* n = ALG_CreateNetwork(10);
    ALG_DebugNetwork(n);
    ALG_AddLayerToNetwork(n, 10);
    ALG_DebugNetwork(n);

    double yTrue[5] = {3.43, 2.67, 0.47, -1.34, -0.21};
    double yPred[5] = {2, 5, -2, 3, 0};

    double r = ALG_MeanSquaredError(yPred, yTrue, 5);

    printf("The result is : %f\n", r);

    return EXIT_SUCCESS;
}

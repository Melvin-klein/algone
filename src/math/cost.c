#include "stdlib.h"
#include "math.h"

#include "cost.h"

double ALG_MeanSquareError(double predictions[], double targets[], size_t batchSize)
{
    double sum = 0;

    for (int i = 0; i < batchSize; i++) {
        sum += pow(predictions[i] - targets[i], 2);
    }

    return (1. / (double) batchSize) * sum;
}

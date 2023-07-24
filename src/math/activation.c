#include "math.h"

#include "activation.h"

double ALG_Sigmoid(double x, double lambda)
{
    return 1 / (1 + exp(- lambda * x));
}

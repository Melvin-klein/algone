#include "gradient.h"

double ALG_ComputeBiasGradient(double predictionGradient, double activationGradient)
{
    return predictionGradient * activationGradient * 1;
}

double ALG_ComputeWeightGradient(double predictionGradient, double activationGradient)
{
    return predictionGradient * activationGradient;
}
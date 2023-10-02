#ifndef ALGONE_GRADIENT_H
#define ALGONE_GRADIENT_H

/**
 * @brief Compute biais gradient.
 *
 * @param predictionGradient The gradient of the loss function.
 * @param activationGradient The gradient of the activation function.
 * @return The computed value.
 */
double ALG_ComputeBiasGradient(double predictionGradient, double activationGradient);

/**
 * @brief Compute weight gradient.
 *
 * @param dPrediction
 * @param dActivation
 * @return The computed value.
 */
double ALG_ComputeWeightGradient(double predictionGradient, double activationGradient);

#endif //ALGONE_GRADIENT_H

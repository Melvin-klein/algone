#ifndef ALGONE_COST_H
#define ALGONE_COST_H

/**
 * @brief The mean square error.
 *
 * @param predictions An array of prediction values given by the network.
 * @param targets The target values to compare with predictions.
 * @param batchSize The size of predictions and targets arrays.
 * @return
 */
double ALG_MeanSquaredError(double predictions[], double targets[], size_t batchSize);

#endif

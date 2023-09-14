#ifndef ALGONE_NETWORK_H
#define ALGONE_NETWORK_H

#include "stdlib.h"
#include "stdio.h"

#include "network_types.h"
#include "../math/math_types.h"

/**
 * @brief Create a network.
 *
 * @param inputSize The first layer size.
 * @return A pointer to the new network.
 */
ALG_Network* ALG_CreateNetwork(int inputSize, int nbLayers);

/**
 * @brief Create a network without layers except the input layer.
 *
 * @param inputSize The size of the input
 * @return A pointer to the new network.
 */
ALG_Network* ALG_CreateBareNetwork(int inputSize);

/**
 * @brief Create a network based on a .alg file.
 *
 * @param filename The name of the .alg file to use.
 * @return A pointer to the new network.
 */
ALG_Network* ALG_CreateNetworkFromFile(FILE *file);

/**
 * @brief Print all network information in the console.
 *
 * @param n The network to debug.
 */
void ALG_DebugNetwork(ALG_Network *n);

/**
 * @brief Destroy a network.
 *
 * @param n The network to destroy.
 */
void ALG_DestroyNetwork(ALG_Network *n);

/**
 * @brief Add a vector of input into the output of first network layer.
 *
 * @param n The network to fill.
 * @param inputs The inputs to use.
 */
void ALG_FillNetworkInputs(ALG_Network *n, const ALG_Vector *inputs);

/**
 * @brief Compute the network output in function of inputs.
 *
 * @param n The network to use for prediction.
 * @param inputs The input values as a vector.
 * @return The computed values.
 */
void ALG_Forward(ALG_Network *n, const ALG_Vector *inputs);

// ALG_Vector* ALG_Predict(ALG_Network *n, const double inputs[]);

#endif

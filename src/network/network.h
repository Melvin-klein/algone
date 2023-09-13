#ifndef ALGONE_NETWORK_H
#define ALGONE_NETWORK_H

#include "stdlib.h"

#include "network_types.h"

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
ALG_Network* ALG_CreateNetworkFromFile(const char filename[]);

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
 * @brief Compute the network output in function of inputs.
 *
 * @param n The network to use for prediction.
 * @param inputs The input values.
 * @return The computed values.
 */
void ALG_Forward(ALG_Network *n, const double inputs[]);

// ALG_Vector* ALG_Predict(ALG_Network *n, const double inputs[]);

#endif

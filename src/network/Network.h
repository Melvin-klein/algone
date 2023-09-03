#ifndef ALGONE_NETWORK_H
#define ALGONE_NETWORK_H

#include "stdlib.h"

#include "./Layer.h"

/**
 * @struct ALG_Network
 *
 * @var _layers READONLY The layers.
 * @var _size READONLY The number of layers.
 */
typedef struct
{
    ALG_Layer **_layers;
    size_t _nbLayers;
} ALG_Network;

/**
 * @brief Create a network.
 *
 * @param inputSize The first layer size.
 * @return A pointer to the new network.
 */
ALG_Network *ALG_CreateNetwork(int inputSize);

/**
 * @brief Append a layer to a network.
 *
 * @param n The network.
 * @param size The number of layer to add.
 */
void ALG_AddLayerToNetwork(ALG_Network *n, size_t size);

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

#endif

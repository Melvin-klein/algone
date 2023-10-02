#ifndef ALGONE_LAYER_H
#define ALGONE_LAYER_H

#include "network_types.h"
#include "../math/math_types.h"

/**
 * @brief Create a network layer.
 *
 * @param size The layer's size.
 * @param nbWeights The number of weights of each units.
 * @return A pointer to the new layer.
 */
ALG_Layer *ALG_CreateLayer(size_t size, int nbWeights);

// TODO: Faire une fonction create bare layer

/**
 * @brief Append a layer to a network.
 *
 * @param n The network.
 * @param size The number of units to add to the new layer.
 */
void ALG_CreateLayerInNetwork(ALG_Network *n, size_t size);

/**
 * @brief Create a layer based on a vector.
 * @param v The vector.
 * @param nbUnits The number of units to create in the layer.
 * @return A pointer to the new layer.
 */
ALG_Layer* ALG_CreateLayerFromVector(ALG_Vector *v, int nbUnits);

/**
 * @brief Append a layer to a network.
 *
 * @param l The layer to append.
 * @param n The network to be updated.
 */
void ALG_AppendLayerToNetwork(ALG_Layer *l, ALG_Network *n);

/**
 * @brief Create a new layer and add it to the network N.
 *
 * @param n The network to update.
 * @param v The base vector for the layer.
 */
void ALG_CreateLayerFromVectorInNetwork(ALG_Network *n, ALG_Vector *v);

/**
 * @brief Destroy a layer.
 *
 * @param l The layer to destroy.
 */
void ALG_DestroyLayer(ALG_Layer* l);

#endif

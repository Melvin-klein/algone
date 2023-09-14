#ifndef ALGONE_NETWORK_TYPES_H
#define ALGONE_NETWORK_TYPES_H

#include "stdlib.h"

/**
 * @struct ALG_Unit
 * @brief Represent a single artificial neuron.
 *
 * @var size The number of weight.
 * @var output The computed output.
 * @var _weights READONLY The weights values.
 * @var _bias READONLY The computed bias.
 */
typedef struct {
    double *_weights;  // Array of weights
    size_t _nbWeights; // Number of weight
    double output;     // Computed output
    double _bias;      // Bias
} ALG_Unit;

/**
 * @struct ALG_Layer
 * @brief Represent a network layer.
 *
 * @var _units READONLY The units which compose the layer.
 * @var _size READONLY The number of units.
 */
typedef struct {
    ALG_Unit **_units; // Array of units
    size_t _nbUnits;
} ALG_Layer;

/**
 * @struct ALG_Network
 *
 * @var _layers READONLY The layers.
 * @var _size READONLY The number of layers.
 */
typedef struct
{
    ALG_Layer **_layers;
    ALG_Layer *_lastLayer;
    size_t _nbLayers;
    size_t _nbMaxLayer;
} ALG_Network;

#endif
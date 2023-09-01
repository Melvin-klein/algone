#ifndef __ALG_LAYER_H__
#define __ALG_LAYER_H__

#include "./Unit.h"

/**
 * @struct ALG_Layer
 * @brief Represent a network layer.
 *
 * @var _units READONLY The units which compose the layer.
 * @var _size READONLY The number of units.
 */
typedef struct {
    ALG_Unit **_units; // Array of units
    size_t _size;
} ALG_Layer;

/**
 * @brief Create a network layer.
 *
 * @param size The layer's size.
 * @param previousLayer The layer that is before this one.
 * @return A pointer to the new layer.
 */
ALG_Layer *ALG_LayerCreate(size_t size, ALG_Layer *previousLayer);

/**
 * @brief Destroy a layer.
 *
 * @param l The layer to destroy.
 */
void ALG_LayerDestroy(ALG_Layer* l);

/**
 * @brief Add a unit to a layer.
 * @param l The layer.
 * @param size The number of units to create.
 */
static void _ALG_LayerAddUnit(ALG_Layer *l, size_t size);

#endif

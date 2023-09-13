#ifndef ALGONE_UNIT_H
#define ALGONE_UNIT_H

#include "network_types.h"

/**
 * @brief Create a unit.
 *
 * @param size The number of weights.
 * @return The new unit.
 */
ALG_Unit *ALG_CreateUnit(size_t size);

/**
 * @brief Add a unit to a layer.
 * @param l The layer.
 * @param size The number of units to create.
 */
void ALG_CreateUnitInLayer(ALG_Layer *l, size_t size);

/**
 * @brief Destroy a unit.
 * @param u The unit to destroy.
 */
void ALG_DestroyUnit(ALG_Unit *u);

#endif

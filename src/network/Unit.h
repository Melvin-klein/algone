#ifndef __ALG_UNIT_H__
#define __ALG_UNIT_H__

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
    double *_weights; // Array of weights
    size_t size;      // Number of weight
    double output;    // Computed output
    double _bias;     // Bias
} ALG_Unit;

/**
 * @brief Create a unit.
 *
 * @param size The number of weights.
 * @return The new unit.
 */
ALG_Unit *ALG_UnitCreate(size_t size);

/**
 * @brief Destroy a unit.
 * @param u The unit to destroy.
 */
void ALG_UnitDestroy(ALG_Unit *u);

#endif

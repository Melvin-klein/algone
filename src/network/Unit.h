#ifndef __ALG_UNIT_H__
#define __ALG_UNIT_H__

/**
 * @brief Unit structure
 * 
 * It represent a single artificial neuron
 */
typedef struct {
    double *_weights; // Array of weights
    size_t size;      // Number of weight
    double output;    // Computed output
    double _bias;     // Bias
} Unit;

Unit *ALG_UnitCreate(size_t size);
void ALG_UnitDestroy(Unit *u);

#endif

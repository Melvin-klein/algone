#include "stdlib.h"

#include "layer.h"
#include "unit.h"
#include "../error/error.h"
#include "../math/vector.h"

ALG_Layer *ALG_CreateLayer(size_t size, int nbWeights)
{
    ALG_Layer *l = malloc(sizeof(*l));

    if (l == NULL) {
        ALG_SetError(ALG_MEMORY_ALLOCATION_ERROR, "Could not allocate memory", __FILE__, __LINE__);

        return NULL;
    }

    l->_nbUnits = size;
    l->_units = malloc(sizeof(**l->_units) * l->_nbUnits);

    if (l->_units == NULL) {
        ALG_SetError(ALG_MEMORY_ALLOCATION_ERROR, "Could not allocate memory", __FILE__, __LINE__);

        return NULL;
    }

    ALG_CreateUnitInLayer(l, nbWeights);

    return l;
}

void ALG_CreateLayerInNetwork(ALG_Network *n, size_t size)
{
    ALG_Layer* l;
    n->_nbLayers++;

    if (n->_nbLayers > n->_nbMaxLayer) {
        n->_nbMaxLayer++;
    }

    ALG_Layer** ptr = realloc(n->_layers, sizeof(ALG_Layer*) * n->_nbLayers);

    if (ptr == NULL) {
        ALG_SetError(ALG_MEMORY_ALLOCATION_ERROR, "Could not allocate memory", __FILE__, __LINE__);
    }

    n->_layers = ptr;

    // If the new layer is the input layer, i.e. the first layer
    if (n->_nbLayers == 1) {
        l = ALG_CreateLayer(size, 0);
    } else {
        l = ALG_CreateLayer(size, n->_layers[n->_nbLayers - 2]->_nbUnits);
    }

    n->_layers[n->_nbLayers - 1] = l;
}

ALG_Layer* ALG_CreateLayerFromVector(ALG_Vector *v, int nbUnits)
{
    int nbWeights = (int) v->size / nbUnits;

    ALG_Layer *l = ALG_CreateLayer(nbUnits, nbWeights);

    if (v->size % nbUnits != 0) {
        ALG_SetError(ALG_INCOMPATIBLE_ERROR, "Can't create a layer from vector that its size is not a multiple of the number of requested units", __FILE__, __LINE__);

        return NULL;
    }

    for (int i = 0; i < nbUnits; i++) {
        for (int j = 0; j < nbWeights; j++) {
            l->_units[i]->_weights[j] = ALG_GetVectorValueAt(v, i * nbWeights + j);
        }
    }

    return l;
}

void ALG_AppendLayerToNetwork(ALG_Layer *l, ALG_Network *n)
{
    for (int i = 0; i < l->_nbUnits; i++) {
        if (n->_layers[n->_nbLayers - 1]->_nbUnits != l->_units[i]->_nbWeights) {
            ALG_SetError(ALG_INCOMPATIBLE_ERROR, "The layer and the network are not compatible for the append operation", __FILE__, __LINE__);
        }
    }

    // If the network is full of layers, re-alloc to add one.
    if (n->_nbMaxLayer == n->_nbLayers) {
        n->_nbMaxLayer++;
        ALG_Layer **ptr = realloc(n->_layers, sizeof(ALG_Layer) * n->_nbMaxLayer);

        if (ptr == NULL) {
            ALG_SetError(ALG_MEMORY_ALLOCATION_ERROR, "Could not allocate memory", __FILE__, __LINE__);

            return;
        }

        n->_layers = ptr;
    }

    n->_nbLayers++;
    n->_layers[n->_nbLayers - 1] = l;
}

void ALG_CreateLayerFromVectorInNetwork(ALG_Network *n, ALG_Vector *v)
{
    size_t nbPreviousLayerUnits = n->_layers[n->_nbLayers - 1]->_nbUnits;

    if (v->size % nbPreviousLayerUnits != 0) {
        ALG_SetError(ALG_INCOMPATIBLE_ERROR, "Can't create a layer from vector that its size is not a multiple of the number of requested units", __FILE__, __LINE__);
    }

    int nbUnits = v->size / (int) nbPreviousLayerUnits;

    ALG_Layer *l = ALG_CreateLayerFromVector(v, nbUnits);
    ALG_AppendLayerToNetwork(l, n);
}

void ALG_DestroyLayer(ALG_Layer *l)
{
    for (int i = 0; i < l->_nbUnits; i++) {
        ALG_DestroyUnit(l->_units[i]);
    }

    free(l->_units);
    free(l);
}

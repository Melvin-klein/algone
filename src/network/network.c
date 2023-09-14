#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#include "network.h"
#include "layer.h"
#include "../error/error.h"
#include "../debug/debug.h"
#include "../math/activation.h"
#include "../file/file_tools.h"

ALG_Network* ALG_CreateNetwork(int inputSize, int nbLayers)
{
    ALG_Network *n = ALG_CreateBareNetwork(inputSize);

    // +1 is for the input layer
    nbLayers += 1;

    ALG_Layer **ptr = realloc(n->_layers, sizeof(ALG_Layer) * nbLayers);

    if (ptr == NULL) {
        ALG_SetError(ALG_MEMORY_ALLOCATION_ERROR, "Could not allocate memory", __FILE__, __LINE__);

        return NULL;
    }

    n->_layers = ptr;
    n->_nbMaxLayer = nbLayers;
    n->_lastLayer = n->_layers[1];

    return n;
}

ALG_Network* ALG_CreateBareNetwork(int inputSize)
{
    ALG_Network* n = malloc(sizeof(*n));

    if (n == NULL) {
        ALG_SetError(ALG_MEMORY_ALLOCATION_ERROR, "Could not allocate memory", __FILE__, __LINE__);

        return NULL;
    }

    n->_nbLayers = 0;
    n->_nbMaxLayer = 0;
    n->_layers = NULL;
    n->_lastLayer = NULL;
    ALG_CreateLayerInNetwork(n, inputSize);

    return n;
}

ALG_Network* ALG_CreateNetworkFromFile(FILE *file)
{
    ALG_FileMetadata *meta = ALG_ReadMetadataFromFile(file);

    ALG_Network *n = ALG_CreateNetwork(meta->inputSize, meta->nbLayers);

    ALG_Vector *v = NULL;

    while ((v = ALG_CreateVectorFromFile(file)) != NULL) {
        ALG_CreateLayerFromVectorInNetwork(n, v);
    }

    return n;
}

void ALG_DebugNetwork(ALG_Network *n)
{
    ALG_DebugHeader("NETWORK");

    printf("Layers : %d\n", (int) n->_nbLayers);

    ALG_DebugFooter();
}

void ALG_DestroyNetwork(ALG_Network *n)
{
    for (int j = 0; j < n->_nbLayers; j++) {
        ALG_DestroyLayer(n->_layers[j]);
    }

    free(n->_layers);
    free(n);
}

void ALG_FillNetworkInputs(ALG_Network *n, const ALG_Vector *inputs)
{
    if (inputs->size != n->_layers[0]->_nbUnits) {
        ALG_SetError(ALG_INCOMPATIBLE_ERROR, "The number of inputs must be equals to the number of input units of the network", __FILE__, __LINE__);

        return;
    }

    for (int i = 0; i < n->_layers[0]->_nbUnits; i++) {
        n->_layers[0]->_units[i]->output = ALG_GetVectorValueAt(inputs, i);
    }
}

void ALG_Forward(ALG_Network *n, const ALG_Vector *inputs)
{
    if (inputs->size != n->_layers[0]->_nbUnits) {
        ALG_SetError(ALG_INCOMPATIBLE_ERROR, "Input size must be equal to network input layer size", __FILE__, __LINE__);

        return;
    }

    ALG_FillNetworkInputs(n, inputs);

    for (int i = 1; i < n->_nbLayers; i++) {
        for (int j = 0; j < n->_layers[i]->_nbUnits; j++) {
            double z = 0;

            for (int k = 0; k < n->_layers[i-1]->_nbUnits; k++) {
                z += n->_layers[i]->_units[j]->_weights[k] * n->_layers[i-1]->_units[k]->output;
            }

            z += n->_layers[i]->_units[j]->_bias;

            n->_layers[i]->_units[j]->output = ALG_Sigmoid(z, 1.);
        }
    }
}

// /!\ Penser à initialiser tout le réseau de manière aléatoire

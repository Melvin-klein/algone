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

    n->_layers = malloc(sizeof(ALG_Layer) * nbLayers);
    n->_nbMaxLayer = nbLayers;

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
    ALG_CreateLayerInNetwork(n, inputSize);

    return n;
}

ALG_Network* ALG_CreateNetworkFromFile(const char filename[])
{
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        char message[300] = "Can't load file : ";
        strcat(message, filename);

        ALG_SetError(ALG_FILE_ERROR, message, __FILE__, __LINE__);

        return NULL;
    }

    ALG_FileMetadata *meta = ALG_ReadMetadataFromFile(file);

    ALG_Network *n = ALG_CreateNetwork(meta->inputSize, meta->nbLayers);

    ALG_Vector *v = NULL;

    while ((v = ALG_CreateVectorFromFile(file)) != NULL) {
        ALG_CreateLayerFromVectorInNetwork(n, v);
    }

    fclose(file);

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

void ALG_Forward(ALG_Network *n, const double inputs[])
{
    for (int i = 0; i < n->_layers[0]->_nbUnits; i++) {
        n->_layers[0]->_units[i]->output = inputs[i];
    }

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

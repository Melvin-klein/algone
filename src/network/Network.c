#include "stdlib.h"
#include "stdio.h"

#include "./Network.h"
#include "./Layer.h"
#include "../error/error.h"
#include "../debug/debug.h"
#include "../math/activation.h"

ALG_Network *ALG_CreateNetwork(int inputSize)
{
    ALG_Network* n = malloc(sizeof(*n));
    ALG_AssertMemoryAlloc(n, __FILE__, __LINE__);

    n->_nbLayers = 0;
    n->_layers = NULL;
    ALG_AddLayerToNetwork(n, inputSize);

    return n;
}

void ALG_AddLayerToNetwork(ALG_Network *n, size_t size)
{
    ALG_Layer* l;
    n->_nbLayers++;
    ALG_Layer** tmp = realloc(n->_layers, sizeof(ALG_Layer*) * n->_nbLayers);
    ALG_AssertMemoryAlloc(tmp, __FILE__, __LINE__);
    n->_layers = tmp;

    // If the new layer is the input layer, i.e. the first layer
    if (n->_nbLayers == 1) {
        l = ALG_CreateLayer(size, NULL);
    } else {
        l = ALG_CreateLayer(size, n->_layers[n->_nbLayers - 2]);
    }

    n->_layers[n->_nbLayers - 1] = l;
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

/*void ALG_FitNetwork(Network *n, )
{

}*/

// /!\ Penser à initialiser tout le réseau de manière aléatoire

static void ALG_NetworkForward(ALG_Network *n, double input[])
{
    for (int i = 0; i < n->_layers[0]->_nbUnits; i++) {
        n->_layers[0]->_units[i]->output = input[i];
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

/*static void _ALG_BackPropagation(Network *n)
{

}

static void _ALG_UpdateWeights(Network *n, double *weights)
{
    
}*/

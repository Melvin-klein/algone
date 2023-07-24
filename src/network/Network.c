#include "stdlib.h"
#include "stdio.h"

#include "./Network.h"
#include "./Layer.h"
#include "../error/error.h"
#include "../debug/debug.h"
#include "../math/activation.h"

Network *ALG_NetworkCreate(int inputSize, double learningRate)
{
    Network* n = malloc(sizeof(*n));
    n->learningRate = learningRate;
    n->_size = 0;

    ALG_AssertMemoryAlloc(n, __FILE__, __LINE__);

    ALG_NetworkAddLayer(n, inputSize);

    return n;
}

void ALG_NetworkAddLayer(Network *n, size_t size)
{
    n->_size++;
    n->_layers = realloc(n->_layers, sizeof(*(n->_layers)) * n->_size);

    ALG_AssertMemoryAlloc(n->_layers, __FILE__, __LINE__);

    Layer* l = ALG_LayerCreate(size, n->_layers[n->_size - 2]);

    n->_layers[n->_size - 1] = l;
}

void ALG_NetworkDebug(Network *n)
{
    ALG_DebugHeader("NETWORK");

    printf("Layers : %d\n", (int) n->_size);

    ALG_DebugFooter();
}

void ALG_NetworkDestroy(Network *n)
{
    for (int j = 0; j < n->_size; j++) {
        ALG_LayerDestroy(n->_layers[j]);
    }

    free(n->_layers);
    free(n);
}

/*void ALG_NetworkFit(Network *n, )
{

}*/

// /!\ Penser à initialiser tout le réseau de manière aléatoire

static void _ALG_NetworkForward(Network *n, double input[])
{
    for (int i = 0; i < n->_layers[0]->size; i++) {
        n->_layers[0]->units[i]->output = input[i];
    }

    for (int i = 1; i < n->_size; i++) {
        for (int j = 0; j < n->_layers[i]->size; j++) {
            double z = 0;

            for (int k = 0; k < n->_layers[i-1]->size; k++) {
                z += n->_layers[i]->units[j]->_weights[k] * n->_layers[i-1]->units[k]->output;
            }

            z += n->_layers[i]->units[j]->_bias;

            n->_layers[i]->units[j]->output = ALG_Sigmoid(z, 1.);
        }
    }
}

/**
 * @brief Compute gradients for all layers
 * 
 * @param n A pointer to the neural network
 */
/*static void _ALG_BackPropagation(Network *n)
{

}

static void _ALG_UpdateWeights(Network *n, double *weights)
{
    
}*/

#include "emscripten.h"
#include "../src/algone.h"

EMSCRIPTEN_KEEPALIVE
int getAlgoneVersion()
{
    return 28;
}

EMSCRIPTEN_KEEPALIVE
ALG_Network* alg_create_bare_network(int size) {
    return ALG_CreateBareNetwork(size);
}
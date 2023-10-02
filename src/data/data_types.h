#ifndef ALGONE_DATA_TYPES_H
#define ALGONE_DATA_TYPES_H

#include "../math/math_types.h"

typedef struct {
    ALG_Matrix *features;
    ALG_Vector *target;
} Dataset;

#endif //ALGONE_DATA_TYPES_H

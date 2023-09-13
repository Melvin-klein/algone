#ifndef ALGONE_MATH_TYPES_H
#define ALGONE_MATH_TYPES_H

#include "stdlib.h"

/**
 * @struct ALG_Vector
 * @brief Represent a math vector
 *
 * @var values An array containing all the values
 * @var size The size of the vector. A.k.a the number of values.
 */
typedef struct {
    double *values;
    int size;
} ALG_Vector;

/**
 * @struct ALG_Matrix
 * @brief Define a Matrix.
 *
 * @var values The values of the Matrix.
 * @var _size READONLY The number of rows ans columns.
 */
typedef struct {
    size_t _size[2];
    double **values;
} ALG_Matrix;

#endif
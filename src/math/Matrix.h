#ifndef __ALG_MATRIX_H__
#define __ALG_MATRIX_H__

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

/**
 * @brief Create a Matrix.
 *
 * @param rows The number of rows.
 * @param columns The number of columns.
 * @param init The value to initialize all the matrix values.
 * @return A pointer to the created matrix.
 */
ALG_Matrix *ALG_CreateMatrix(size_t rows, size_t columns, double v);

/**
 * @brief Fill a matrix with a value.
 *
 * @param m The matrix to fill.
 * @param v The value to use.
 */
void ALG_FillMatrix(ALG_Matrix *m, double v);

/**
 * @brief Print a matrix in the console.
 *
 * @param m The matrix to debug.
 */
void ALG_DebugMatrix(ALG_Matrix *m);

/**
 * @brief Destroy a Matrix.
 *
 * @param m The matrix to destroy.
 */
void ALG_DestroyMatrix(ALG_Matrix *m);

#endif

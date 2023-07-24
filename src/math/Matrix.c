#include "stdlib.h"
#include "stdio.h"

#include "Matrix.h"
#include "../debug/debug.h"
#include "../error/error.h"

/**
 * @brief Create a matrix filled with 0
 * 
 * Create a matrix of size (rows, columns) filled with 
 * 
 * @param rows Number of rows
 * @param columns Number of columns
 * @param v Initial value to fill the matrix
 * 
 * @return Matrix* 
 */
Matrix *ALG_MatrixCreate(size_t rows, size_t columns, double v)
{
    Matrix *m = malloc(sizeof(*m));

    m->_size[0] = rows;
    m->_size[1] = columns;
    m->values = calloc(m->_size[0], sizeof(*(m->values)));

    ALG_AssertMemoryAlloc(m, __FILE__, __LINE__);

    for (int i = 0; i < m->_size[0]; i++) {
        m->values[i] = calloc(m->_size[1], sizeof(m->values[i]));

        ALG_AssertMemoryAlloc(m->values[i], __FILE__, __LINE__);
    }

    ALG_MatrixFill(m, v);

    return m;
}

/**
 * @brief Fill a matrix with value v
 * 
 * @param m The matrix to fill
 * @param v The value
 */
void ALG_MatrixFill(Matrix *m, double v)
{
    for (int i = 0; i < m->_size[0]; i++) {
        for (int j = 0; j < m->_size[1]; j++) {
            m->values[i][j] = v;
        }
    }
}

/**
 * @brief Print debug information of matrix m
 * 
 * @param m The matrix to debug
 */
void ALG_MatrixDebug(Matrix *m)
{
    ALG_DebugHeader("MATRIX");

    for (int i = 0; i < m->_size[0]; i++) {
        printf("| ");

        for (int j = 0; j < m->_size[1]; j++) {
            printf("%f ", m->values[i][j]);
        }

        printf("| \n");
    }

    ALG_DebugFooter();
}

/**
 * @brief Free all matrix allocations
 * 
 * @param m The matrix to free
 */
void ALG_MatrixDestroy(Matrix *m)
{
    for (int i = 0; i < m->_size[0]; i++) {
        free(m->values[i]);
    }

    free(m->values);
    free(m);
}

#include "stdlib.h"
#include "stdio.h"

#include "Matrix.h"
#include "../debug/debug.h"
#include "../error/error.h"

ALG_Matrix *ALG_MatrixCreate(size_t rows, size_t columns, double v)
{
    ALG_Matrix *m = malloc(sizeof(*m));

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

void ALG_MatrixFill(ALG_Matrix *m, double v)
{
    for (int i = 0; i < m->_size[0]; i++) {
        for (int j = 0; j < m->_size[1]; j++) {
            m->values[i][j] = v;
        }
    }
}

void ALG_MatrixDebug(ALG_Matrix *m)
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

void ALG_MatrixDestroy(ALG_Matrix *m)
{
    for (int i = 0; i < m->_size[0]; i++) {
        free(m->values[i]);
    }

    free(m->values);
    free(m);
}

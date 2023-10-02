#include "stdlib.h"
#include "stdio.h"

#include "matrix.h"
#include "../debug/debug.h"
#include "../error/error.h"

ALG_Matrix *ALG_CreateMatrix(size_t rows, size_t columns, double v)
{
    ALG_Matrix *m = malloc(sizeof(*m));

    m->_size[0] = rows;
    m->_size[1] = columns;
    m->values = calloc(m->_size[0], sizeof(*(m->values)));

    if (m->values == NULL) {
        ALG_SetError(ALG_MEMORY_ALLOCATION_ERROR, "Could not allocate memory", __FILE__, __LINE__);

        return NULL;
    }

    for (int i = 0; i < m->_size[0]; i++) {
        m->values[i] = calloc(m->_size[1], sizeof(m->values[i]));

        if (m->values[i] == NULL) {
            ALG_SetError(ALG_MEMORY_ALLOCATION_ERROR, "Could not allocate memory", __FILE__, __LINE__);

            return NULL;
        }
    }

    ALG_FillMatrix(m, v);

    return m;
}

void ALG_FillMatrix(ALG_Matrix *m, double v)
{
    for (int i = 0; i < m->_size[0]; i++) {
        for (int j = 0; j < m->_size[1]; j++) {
            m->values[i][j] = v;
        }
    }
}

void ALG_DebugMatrix(ALG_Matrix *m)
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

void ALG_DestroyMatrix(ALG_Matrix *m)
{
    for (int i = 0; i < m->_size[0]; i++) {
        free(m->values[i]);
    }

    free(m->values);
    free(m);
}

#ifndef __ALG_MATRIX_H__
#define __ALG_MATRIX_H__

typedef struct {
    size_t _size[2];
    double **values;
} Matrix;

Matrix *ALG_MatrixCreate(size_t rows, size_t columns, double init);
void ALG_MatrixFill(Matrix *m, double v);
void ALG_MatrixDebug(Matrix *m);
void ALG_MatrixDestroy(Matrix *m);

#endif

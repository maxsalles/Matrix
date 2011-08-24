/*
** $ Herond Robaina Salles
*/

#ifndef _MTX_IMP
#define _MTX_IMP

#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

/* ========================================================================== */

struct MTXMatrix_ST {
    unsigned rows, columns;
    double **rep_p;
};

/* ========================================================================== */

MTXMatrix mtxNew (unsigned rows, unsigned columns) {
    int i, j;
    MTXMatrix mtx_return = (MTXMatrix) malloc(sizeof(struct MTXMatrix_ST));
    double* data_p = (double*) malloc(sizeof(double) * rows * columns);
    double** rep_p = (double**) malloc(sizeof(double*) * rows);

    mtx_return->rows = rows;
    mtx_return->columns = columns;
    mtx_return->rep_p = rep_p;

    for (i = 0; i < rows; i ++) rep_p[i] = data_p + i * rows;
    for (i = 0; i < rows; i ++)
        for (j = 0; j < columns; j ++)
            rep_p[i][j] = (i == j) ? 1.0 : 0.0;

    return mtx_return;
}

void mtxPrint (const MTXMatrix self) {
    int i, j;

    for (i = 0; i < self->rows; i ++) {
        for (j = 0; j < self->columns; j ++) printf("%f ", self->rep_p[i][j]);
        puts("");
    }
}

/* ========================================================================== */

#endif


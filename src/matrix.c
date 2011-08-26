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

static double** _allocRep (unsigned rows, unsigned columns) {
    int i;
    double* data_p = (double*) malloc(sizeof(double) * rows * columns);
    double** rep_p = (double**) malloc(sizeof(double*) * rows);

    for (i = 0; i < rows; i ++) rep_p[i] = data_p + i * rows;

    return rep_p;
}

static MTXMatrix _alloc (unsigned rows, unsigned columns) {
    MTXMatrix mtx_return = (MTXMatrix) malloc(sizeof(struct MTXMatrix_ST));

    mtx_return->rows = rows;
    mtx_return->columns = columns;
    mtx_return->rep_p = _allocRep(rows, columns);

    return mtx_return;
}

/* ========================================================================== */

MTXMatrix mtxNew (unsigned rows, unsigned columns) {
    int i, j;
    MTXMatrix mtx_return = _alloc(rows, columns);

    for (i = 0; i < rows; i ++)
        for (j = 0; j < columns; j ++)
            mtx_return->rep_p[i][j] = (i == j) ? 1.0 : 0.0;

    return mtx_return;
}

MTXMatrix mtxCopy (const MTXMatrix self) {
    int i, j;
    MTXMatrix mtx_return = _alloc(self->rows, self->columns);

    for (i = 0; i < self->rows; i ++)
        for (j = 0; j < self->columns; j ++)
            mtx_return->rep_p[i][j] = self->rep_p[i][j];

    return mtx_return;
}

void mtxDestroy (MTXMatrix* self_p) {
    free((*self_p)->rep_p[0]);
    free((*self_p)->rep_p);
    free(*self_p);
    *self_p = NULL;
}

double mtxGetElement (const MTXMatrix self, unsigned i, unsigned j) {
    return self->rep_p[i][j];
}

MTXMatrix mtxGetRow (const MTXMatrix self, unsigned i) {
    int j;
    MTXMatrix line_return = _alloc(1, self->columns);

    for (j = 0; j < self->columns; j ++)
        line_return->rep_p[0][j] = self->rep_p[i][j];

    return line_return;
}

MTXMatrix mtxGetColumn (const MTXMatrix self, unsigned j) {
    int i;
    MTXMatrix line_return = _alloc(self->rows, 1);

    for (i = 0; i < self->rows; i ++)
        line_return->rep_p[i][0] = self->rep_p[i][j];

    return line_return;
}

void mtxSetElement (MTXMatrix self, unsigned i, unsigned j, double num) {
    self->rep_p[i][j] = num;
}

void mtxTranspose (MTXMatrix self) {
    unsigned aux;
    int i, j;
    double** new_rep_p = _allocRep(self->columns, self->rows);

    for (i = 0; i < self->columns; i ++)
        new_rep_p[i] = self->rep_p[0] + i * self->columns;

    for (i = 0; i < self->rows; i ++)
        for (j = 0; j < self->columns; j ++) {
            new_rep_p[j][i] = self->rep_p[i][j];
        }

/*    free(self->rep_p);*/
    aux = self->rows;
    self->rows = self->columns;
    self->columns = aux;
    self->rep_p = new_rep_p;
}

void mtxScalarMul (MTXMatrix self, double num) {
    int i, j;

    for (i = 0; i < self->rows; i ++)
        for (j = 0; j < self->columns; j ++)
            self->rep_p[i][j] *= num;
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


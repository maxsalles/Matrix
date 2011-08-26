/*
** $ Herond Robaina Salles
*/

#ifndef _MTX_IMP
#define _MTX_IMP

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

    for (i = 0; i < rows; i ++) rep_p[i] = data_p + i * columns;

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
    MTXMatrix row_return = _alloc(1, self->columns);

    for (j = 0; j < self->columns; j ++)
        row_return->rep_p[0][j] = self->rep_p[i][j];

    return row_return;
}

MTXMatrix mtxGetColumn (const MTXMatrix self, unsigned j) {
    int i;
    MTXMatrix column_return = _alloc(self->rows, 1);

    for (i = 0; i < self->rows; i ++)
        column_return->rep_p[i][0] = self->rep_p[i][j];

    return column_return;
}

void mtxSetElement (MTXMatrix self, unsigned i, unsigned j, double num) {
    self->rep_p[i][j] = num;
}

MTXMatrix mtxTranspose (MTXMatrix self) {
    int i, j, aux;
    double** new_rep_p = _allocRep(self->columns, self->rows);

    for (i = 0; i < self->rows; i ++)
        for (j = 0; j < self->columns; j ++)
            new_rep_p[j][i] = self->rep_p[i][j];

    free(self->rep_p[0]);
    free(self->rep_p);
    aux = self->rows;
    self->rows = self->columns;
    self->columns = aux;
    self->rep_p = new_rep_p;

    return self;

/*    int i, j, aux;*/
/*    double aux_element;*/
/*    double** new_rep_p = (double**) malloc(sizeof(double*) * self->columns);*/

/*    for (j = 0; j < self->columns; j ++)*/
/*        new_rep_p[j] = self->rep_p[0] + j * self->rows;*/

/*    for (i = 0; i < self->rows; i ++)*/
/*        for (j = i + 1; j < self->columns; j ++) {*/
/*            aux_element = new_rep_p[j][i];*/
/*            new_rep_p[j][i] = self->rep_p[i][j];*/
/*            self->rep_p[i][j] = aux_element;*/
/*        }*/

/*    free(self->rep_p);*/
/*    aux = self->rows;*/
/*    self->rows = self->columns;*/
/*    self->columns = aux;*/
/*    self->rep_p = new_rep_p;*/
}

void mtxScalarMul (MTXMatrix self, double num) {
    int i, j;

    for (i = 0; i < self->rows; i ++)
        for (j = 0; j < self->columns; j ++)
            self->rep_p[i][j] *= num;
}

void mtxAdd (MTXMatrix self, const MTXMatrix matrix) {
    if (self->rows == matrix->rows && self->columns == matrix->columns) {
        int i, j;

        for (i = 0; i < self->rows; i ++)
            for (j = 0; j < self->columns; j ++)
                self->rep_p[i][j] += matrix->rep_p[i][j];
    }
}

void mtxSub (MTXMatrix self, const MTXMatrix matrix) {
    if (self->rows == matrix->rows && self->columns == matrix->columns) {
        int i, j;

        for (i = 0; i < self->rows; i ++)
            for (j = 0; j < self->columns; j ++)
                self->rep_p[i][j] -= matrix->rep_p[i][j];
    }
}

MTXMatrix mtxMul (const MTXMatrix matrix1, const MTXMatrix matrix2) {
    int i, j, k;
    MTXMatrix matrix_return = mtxNew(matrix1->rows, matrix2->columns);

    for (i = 0; i < matrix_return->rows; i ++)
        for (j = 0; j < matrix_return->columns; j ++) {
            double aux = 0.0;

            for (k = 0; k < matrix1->columns; k ++)
                aux += matrix1->rep_p[i][k] * matrix2->rep_p[k][j];

            matrix_return->rep_p[i][j] = aux;
        }

    return matrix_return;
}

void mtxChangedRows (MTXMatrix self, unsigned i0, unsigned i1) {

}

MTXMatrix mtxGetRotationMatrix(MTXMatrix self, unsigned i, unsigned j) {
    if (self->rows == self->columns) {
        MTXMatrix matrix_return = mtxNew(self->rows, self->columns);
        double cos, sin;

        if (!self->rep_p[i][j]) return matrix_return;

        cos = self->rep_p[j][j] / sqrt(
            pow(self->rep_p[j][j], 2) + pow(self->rep_p[i][j], 2)
        );
        sin = self->rep_p[i][j] / sqrt(
            pow(self->rep_p[j][j], 2) + pow(self->rep_p[i][j], 2)
        );

        matrix_return->rep_p[i][i] = cos;
        matrix_return->rep_p[j][j] = cos;
        matrix_return->rep_p[i][j] = -1.0 * sin;
        matrix_return->rep_p[j][i] = sin;

        return matrix_return;
    }

    return NULL;
}

MTXMatrix mtxGetEigenvalues (MTXMatrix self) {
    int i, j, n = 0;
    MTXMatrix aux = NULL, Q = NULL, R = NULL;
    MTXMatrix rotation_matrices[((int) pow(self->rows, 2) - self->rows) / 2];

    /*
    ** Begin calculate R matrix
    */
    for (i = 0; i < self->rows; i ++)
        for (j = 0; j < self->columns; j ++)
            if (j < i) {
                rotation_matrices[n] = mtxGetRotationMatrix(self, i, j);
                n ++;
            }

    R = mtxNew(self->rows, self->columns);
    for (i = 0; i < n; i ++) {
        aux = R;
        R = mtxMul(R, rotation_matrices[i]);
        mtxDestroy(&aux);
    }
    aux = R;
    R = mtxMul(R, self);
    mtxDestroy(&aux);

    /*
    ** Begin calculate Q matrix
    */
    Q = mtxNew(self->rows, self->columns);
    for (i = 0; i < n; i ++) {
        printf("%i", i); getchar();
        aux = Q;
        Q = mtxMul(aux, mtxTranspose(rotation_matrices[i]));
        mtxDestroy(&aux);
    }



    return NULL;
}

void mtxPrint (MTXMatrix self) {
    int i, j;

    for (i = 0; i < self->rows; i ++) {
        for (j = 0; j < self->columns; j ++)
            printf("%f ", self->rep_p[i][j]);
        puts("");
    }
}

/* ========================================================================== */

#endif


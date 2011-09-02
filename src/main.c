#include <stdio.h>

#include "matrix.h"

int main (void) {
    double mtx_aux1[9] = {
        2.0, 0.0, 1.0,
        0.0, 1.0, 0.0,
        1.0, 0.0, 1.0
    };

    double mtx_aux2[9] = {
        0.0, -2.0, 2.0,
        1.0,  3.0, 3.0,
        2.0,  3.0, 1.0
    };

    double mtx_aux3[4] = {
        3.0, 1.0,
        1.0, 3.0
    };



    MTXMatrix matrix1 = mtxNew(3, 3), matrix2 = mtxNew(3, 3), matrix3 = mtxNew(2, 2);
    MTXMatrix eigenvalues1 = NULL, eigenvalues2 = NULL, eigenvalues3 = NULL;

    mtxInitd(matrix1, mtx_aux1);
    mtxPrint(matrix1);
    eigenvalues1 = mtxGetEigenvalues(matrix1, 0.001);

    printf("Eigenvalues:\n");
    mtxPrint(eigenvalues1);

    puts("=================================================");

    mtxInitd(matrix2, mtx_aux2);
    mtxPrint(matrix2);
    eigenvalues2 = mtxGetEigenvalues(matrix2, 0.001);

    printf("Eigenvalues:\n");
    mtxPrint(eigenvalues2);

    puts("=================================================");

    mtxInitd(matrix3, mtx_aux3);
    mtxPrint(matrix3);
    eigenvalues3 = mtxGetEigenvalues(matrix3, 0.001);

    printf("Eigenvalues:\n");
    mtxPrint(eigenvalues3);

    return 0;
}


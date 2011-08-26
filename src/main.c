#include <stdio.h>

#include "matrix.h"

int main (void) {
    int i, j;
    double mtx_aux[3][3] = {
        { 2.0, 0.0, 1.0 },
        { 0.0, 1.0, 0.0 },
        { 1.0, 0.0, 1.0 }
    };

    double mtx_aux1[3][3] = {
        { 4.0, -3.0, 2.0 },
        { 3.0, -3.0, 0.0 },
        { 5.0, -3.0, 1.0 }
    };

    double mtx_aux2[3][2] = {
        {  2.0,  3.0 },
        {  1.0, -4.0 },
        { -6.0,  1.0 }
    };

    MTXMatrix matrix = mtxNew(3, 3);
    MTXMatrix eigenvalues = NULL;

    MTXMatrix mtx1 = mtxNew(3, 3);
    MTXMatrix mtx2 = mtxNew(3, 2);

    for (i = 0; i < 3; i ++)
        for (j = 0; j < 3; j ++)
            mtxSetElement(mtx1, i, j, mtx_aux1[i][j]);

    for (i = 0; i < 3; i ++)
        for (j = 0; j < 2; j ++)
            mtxSetElement(mtx2, i, j, mtx_aux2[i][j]);

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            mtxSetElement(matrix, i, j, mtx_aux[i][j]);

    eigenvalues = mtxGetEigenvalues(matrix);
/*    mtxTranspose(mtx2);*/
/*    mtxPrint(mtx2);*/

/*    mtxPrint(mtxMul(mtx1, mtx2));*/

    return 0;
}


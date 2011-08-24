#include <stdio.h>

#include "matrix.h"

int main (void) {
    MTXMatrix mtx_3_3 = mtxNew(3, 3);
    MTXMatrix mtx_5_6 = mtxNew(5, 6);
    MTXMatrix row = NULL;
    MTXMatrix column = NULL;

    mtxPrint(mtx_3_3);
    mtxPrint(mtx_5_6);

    mtxDestroy(&mtx_3_3);
    printf("%p\n", mtx_3_3);

    printf("%f\n", mtxGetElement(mtx_5_6, 1, 1));

    row = mtxGetRow(mtx_5_6, 3);
    mtxPrint(row);

    column = mtxGetColumn(mtx_5_6, 3);
    mtxPrint(column);

    mtxSetElement(mtx_5_6, 0, 0, 10.0);
    mtxPrint(mtx_5_6);

    mtxScalarMul(mtx_5_6, 5.0);
    mtxPrint(mtx_5_6);

    return 0;
}


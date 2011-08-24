#include <stdio.h>

#include "matrix.h"

int main (void) {
    MTXMatrix mtx_3_3 = mtxNew(3, 3);
    MTXMatrix mtx_5_6 = mtxNew(5, 6);

    mtxPrint(mtx_3_3);
    mtxPrint(mtx_5_6);

    mtxDestroy(&mtx_3_3);
    printf("%p\n", mtx_3_3);

    printf("%f\n", mtxGetElement(mtx_5_6, 0, 1));

    return 0;
}


#include <stdio.h>

#include "matrix.h"

int main (void) {
    MTXMatrix mtx = mtxNew(2, 3);

    mtxPrint(mtx);
    mtxTranspose(mtx);
    mtxPrint(mtx);

    return 0;
}


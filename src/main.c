#include "matrix.h"

int main (void) {
    MTXMatrix mtx_3_3 = mtxNew(3, 3);
    MTXMatrix mtx_5_6 = mtxNew(5, 6);

    mtxPrint(mtx_3_3);
    mtxPrint(mtx_5_6);

    return 0;
}


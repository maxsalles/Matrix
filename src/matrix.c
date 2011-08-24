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
    double **elem_p;
};

/* ========================================================================== */

MTXMatrix mtxNew (unsigned rows, unsigned columns) {
    return NULL;
}

/* ========================================================================== */

#endif


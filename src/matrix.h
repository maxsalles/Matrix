/*
** $ Herond Robaina Salles
*/

#ifndef _MTX_LIB
#define _MTX_LIB

/* ========================================================================== */

struct MTXMatrix_ST;
typedef struct MTXMatrix_ST* MTXMatrix;

/* ========================================================================== */

MTXMatrix mtxNew (unsigned rows, unsigned columns);
MTXMatrix mtxCopy (const MTXMatrix matrix);
void mtxDestroy (MTXMatrix* self_p);

double mtxGetElement (const MTXMatrix self, unsigned i, unsigned j);
MTXMatrix mtxGetLine (const MTXMatrix self, unsigned i);
MTXMatrix mtxGetRow (const MTXMatrix self, unsigned j);
void mtxSetElement (MTXMatrix self, unsigned i, unsigned j);
void mtxTranspose (MTXMatrix self);
void mtxScalarMul (MTXMatrix self, double num);
void mtxAdd (MTXMatrix self, const MTXMatrix matrix);
void mtxSub (MTXMatrix self, const MTXMatrix matrix);

void mtxChangedRows (MTXMatrix self, unsigned i0, unsigned i1);
void mtxChangedColumns (MTXMatrix self, unsigned i0, unsigned i1);
void mtxScalarMulRow (MTXMatrix self, unsigned i, double num);
void mtxAddRow (MTXMatrix self, unsigned i0, unsigned i1);
void mtxSubRow (MTXMatrix self, unsigned i0, unsigned i1);

void mtxPrint (const MTXMatrix self);

/* ========================================================================== */

#endif


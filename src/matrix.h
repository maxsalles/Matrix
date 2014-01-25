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
void mtxIniti (MTXMatrix self, int vet[]);
void mtxInitf (MTXMatrix self, float vet[]);
void mtxInitd (MTXMatrix self, double vet[]);
void mtxDestroy (MTXMatrix* self_p);

double mtxGetElement (const MTXMatrix self, unsigned i, unsigned j);
MTXMatrix mtxGetRow (const MTXMatrix self, unsigned i);
MTXMatrix mtxGetColumn (const MTXMatrix self, unsigned j);
void mtxSetElement (MTXMatrix self, unsigned i, unsigned j, double num);
MTXMatrix mtxTranspose (MTXMatrix self);
void mtxScalarMul (MTXMatrix self, double num);
void mtxAdd (MTXMatrix self, const MTXMatrix matrix);
void mtxSub (MTXMatrix self, const MTXMatrix matrix);
MTXMatrix mtxMul (const MTXMatrix matrix1, const MTXMatrix matrix2);

void mtxChangedRows (MTXMatrix self, unsigned i0, unsigned i1);
void mtxChangedColumns (MTXMatrix self, unsigned i0, unsigned i1);
void mtxScalarMulRow (MTXMatrix self, unsigned i, double num);
void mtxAddRow (MTXMatrix self, unsigned i0, unsigned i1);
void mtxSubRow (MTXMatrix self, unsigned i0, unsigned i1);

MTXMatrix mtxGetRotationMatrix(MTXMatrix self, unsigned i, unsigned j);
MTXMatrix mtxGetEigenvalues (MTXMatrix self, double tolerance);

void mtxPrint (const MTXMatrix self);
unsigned int mtxGetRowNum(MTXMatrix self);
unsigned int mtxGetColNum(MTXMatrix self);

/* ========================================================================== */

#endif


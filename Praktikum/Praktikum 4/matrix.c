#include <stdio.h>
#include "boolean.h"
#include "matrix.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createMatrix(int nRows, int nCols, Matrix *m)
{
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
}

/* *** Selektor *** */

/* *** Selektor "Dunia Matrix" *** */
boolean isMatrixIdxValid(int i, int j)
{
    return (i >= 0) && (i < ROW_CAP) && (j >= 0) && (j < COL_CAP);
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(Matrix m)
{
    /* Mengirimkan Index baris terbesar m */
    return (ROW_EFF(m) - 1);
}
IdxType getLastIdxCol(Matrix m)
{
    /* Mengirimkan Index kolom terbesar m */
    return (COL_EFF(m) - 1);
}
boolean isIdxEff(Matrix m, IdxType i, IdxType j)
{
    /* Mengirimkan true jika i, j adalah Index efektif bagi m */
    return (i >= 0) && (i < ROW_EFF(m)) && (j >= 0) && (j < COL_EFF(m));
}
ElType getElmtDiagonal(Matrix m, IdxType i)
{
    /* Mengirimkan elemen m(i,i) */
    return ELMT(m, i, i);
}

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut)
{
    /* Melakukan assignment mOut <- mIn */
    ROW_EFF(*mOut) = ROW_EFF(mIn);
    COL_EFF(*mOut) = COL_EFF(mIn);

    *mOut = mIn;
}

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol)
{
    int i, j;
    ElType elm;

    createMatrix(nRow, nCol, m);

    for (i = 0; i < nRow; i++)
    {
        for (j = 0; j < nCol; j++)
        {
            scanf("%d", &elm);
            ELMT(*m, i, j) = elm;
        }
    }
}
void displayMatrix(Matrix m)
{
    int i, j;

    for (i = 0; i < ROW_EFF(m); i++)
    {
        for (j = 0; j < COL_EFF(m); j++)
        {
            printf("%d", ELMT(m, i, j));
            if (j != COL_EFF(m) - 1)
            {
                printf(" ");
            }
        }
        if (i != ROW_EFF(m) - 1)
        {
            printf("\n");
        }
    }
    printf("\n");
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2)
{
    Matrix m3;
    int i, j;

    createMatrix(ROW_EFF(m1), COL_EFF(m1), &m3);

    for (i = 0; i < ROW_EFF(m3); i++)
    {
        for (j = 0; j < COL_EFF(m3); j++)
        {
            ELMT(m3, i, j) = ELMT(m1, i, j) + ELMT(m2, i, j);
        }
    }
    return m3;
}
Matrix subtractMatrix(Matrix m1, Matrix m2)
{
    Matrix m3;
    int i, j;

    createMatrix(ROW_EFF(m1), COL_EFF(m1), &m3);

    for (i = 0; i < ROW_EFF(m3); i++)
    {
        for (j = 0; j < COL_EFF(m3); j++)
        {
            ELMT(m3, i, j) = ELMT(m1, i, j) - ELMT(m2, i, j);
        }
    }
    return m3;
}
Matrix multiplyMatrix(Matrix m1, Matrix m2)
{
    Matrix m3;
    int i, j, k;

    createMatrix(ROW_EFF(m1), COL_EFF(m2), &m3);

    for (i = 0; i < ROW_EFF(m3); i++)
    {
        for (j = 0; j < COL_EFF(m3); j++)
        {
            ELMT(m3, i, j) = 0;
            for (k = 0; k < COL_EFF(m1); k++)
            {
                ELMT(m3, i, j) += ELMT(m1, i, k) * ELMT(m2, k, j);
            }
        }
    }
    return m3;
}
Matrix multiplyByConst(Matrix m, ElType x)
{
    Matrix m3;
    int i, j;

    createMatrix(ROW_EFF(m), COL_EFF(m), &m3);

    for (i = 0; i < ROW_EFF(m3); i++)
    {
        for (j = 0; j < COL_EFF(m3); j++)
        {
            ELMT(m3, i, j) = ELMT(m, i, j) * x;
        }
    }
    return m3;
}
void pMultiplyByConst(Matrix *m, ElType k)
{
    int i, j;
 
    for (i = 0; i < ROW_EFF(*m); i++)
    {
        for (j = 0; j < COL_EFF(*m); j++)
        {
            ELMT(*m, i, j) = ELMT(*m, i, j) * k;
        }
    }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isMatrixEqual(Matrix m1, Matrix m2)
{
    int i, j;
    boolean e = true;

    i = 0;
    j = 0;

    if ((countElmt(m1) != countElmt(m2)))
    {
        e = false;
    }
    // Skema searching untuk mencari ketidaksamaan
    while ((e == true) && (i < ROW_EFF(m1)))
    {
        while ((e == true) && (j < COL_EFF(m1)))
        {
            if (ELMT(m1, i, j) != ELMT(m2, i, j))
            {
                e = false;
            }
            j++;
        }
        i++;
    }

    return e;
}
boolean isMatrixNotEqual(Matrix m1, Matrix m2)
{
    return !isMatrixEqual(m1, m2);
}
boolean isMatrixSizeEqual(Matrix m1, Matrix m2)
{
    return (ROW_EFF(m1) == ROW_EFF(m2)) && ((COL_EFF(m1) == COL_EFF(m2)));
}

/* ********** Operasi lain ********** */
int countElmt(Matrix m)
{
    return (ROW_EFF(m) * COL_EFF(m)) - (COL_EFF(m) - (getLastIdxCol(m) + 1));
}

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m)
{
    return ROW_EFF(m) == COL_EFF(m);
}
boolean isSymmetric(Matrix m)
{
    boolean sym = true;
    int i, j;

    i = 0;
    j = 0;
    if (isSquare(m) == true)
    {
        while ((i < ROW_EFF(m)) && (sym != false))
        {
            while ((j < COL_EFF(m)) && (sym != false))
            {
                if (ELMT(m, i, j) != ELMT(m, j, i))
                {
                    sym = false;
                }
                j++;
            }
            i++;
        }
    }
    else
    {
        sym = false;
    }

    return sym;
}
boolean isIdentity(Matrix m)
{
    boolean id = true;
    int i, j;

    i = 0;
    j = 0;
    if (isSquare(m) == true)
    {
        while ((i < ROW_EFF(m)) && (id != false))
        {
            while ((j < COL_EFF(m)) && (id != false))
            {
                if (i == j)
                {
                    if (ELMT(m, i, j) != 1)
                    {
                        id = false;
                    }
                }
                else
                {
                    if (ELMT(m, i, j) != 0)
                    {
                        id = false;
                    }
                }
                j++;
            }
            i++;
        }
    }
    else
    {
        id = false;
    }

    return id;
}
boolean isSparse(Matrix m)
{
    float max = (ROW_EFF(m) * COL_EFF(m)) * 0.05;
    max = (int)max; 
    int countNotZero = 0;
    int i, j;

    for (i = 0; i < ROW_EFF(m); i++)
    {
        for (j = 0; j < COL_EFF(m); j++)
        {
            if (ELMT(m, i, j) != 0)
            {
                countNotZero++;
            }
        }
    }

    return (countNotZero <= max);
}
Matrix negation(Matrix m)
{
    Matrix m3;
    int i, j;
    createMatrix(ROW_EFF(m), COL_EFF(m), &m3);

    for (i = 0; i < ROW_EFF(m3); i++)
    {
        for (j = 0; j < COL_EFF(m3); j++)
        {
            ELMT(m3, i, j) = ELMT(m, i, j) * (-1);
        }
    }
    return m3;
}
void pNegation(Matrix *m)
{
    int i, j;

    for (i = 0; i < ROW_EFF(*m); i++)
    {
        for (j = 0; j < COL_EFF(*m); j++)
        {
            ELMT(*m, i, j) = ELMT(*m, i, j) * (-1);
        }
    }
}

Matrix minor(Matrix m, int row, int col)
{
    Matrix temp;
    int i, j, x, y;

    createMatrix(ROW_EFF(m) - 1, COL_EFF(m) - 1, &temp);

    x = 0;
    for (i = 0; i < ROW_EFF(m); i++)
    {
        if (i != row)
        {
            y = 0;
            for (j = 0; j < COL_EFF(m); j++)
            {
                if (j != col)
                {
                    ELMT(temp, x, y) = ELMT(m, i, j);
                    y++;
                }
            }
            x++;
        }
    }
    return temp;
}

float determinant(Matrix m)
{
    int i, j;
    float det;
    int sign = 1;

    if (ROW_EFF(m) == 1)
    {
        return ELMT(m, 0, 0);
    }
    det = 0;

    for (i = 0; i < COL_EFF(m); i++)
    {
        det += sign * ELMT(m, 0, i) * determinant(minor(m, 0, i));
        sign *= (-1);
    }
    return det;
}
Matrix transpose(Matrix m)
{
    Matrix mhasil;
    int i, j;

    createMatrix(ROW_EFF(m), COL_EFF(m), &mhasil);

    for (i = 0; i < ROW_EFF(m); i++)
    {
        for (j = 0; j < COL_EFF(m); j++)
        {
            ELMT(mhasil, j, i) = ELMT(m, i, j);
        }
    }

    return mhasil;
}
void pTranspose(Matrix *m)
{
    Matrix mhasil;
    int i, j;

    createMatrix(ROW_EFF(*m), COL_EFF(*m), &mhasil);

    for (i = 0; i < ROW_EFF(*m); i++)
    {
        for (j = 0; j < COL_EFF(*m); j++)
        {
            ELMT(mhasil, j, i) = ELMT(*m, i, j);
        }
    }

    *m = mhasil;
}

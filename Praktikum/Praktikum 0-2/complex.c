#include "boolean.h"
#include "complex.h"
#include <stdio.h>
#include <math.h>
/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsCOMPLEXValid(float Re, float Im)
{
  return 1;
}

/* Mengirim true jika Re dan Im valid untuk membentuk COMPLEX */
/* Dalam konteks kompleks, semua bilangan real adalah valid */

/* *** Konstruktor: Membentuk sebuah COMPLEX dari komponen-komponennya *** */
void CreateComplex(COMPLEX *C, float Re, float Im)
{
  Real(*C) = Re;
  Imag(*C) = Im;
}
/* Membentuk sebuah COMPLEX dari komponen-komponennya */

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaCOMPLEX(COMPLEX *C)
{
  float Re, Im;
  scanf("%f %f", &Re, &Im);
  CreateComplex(C, Re, Im);
}
/* I.S. : C tidak terdefinisi */
/* F.S. : C terdefinisi */
/* Proses : Membaca komponen Re dan Im dari pengguna */

void TulisCOMPLEX(COMPLEX C)
{
  if(C.Im < 0)
  {
    printf("%.2f%.2fi\n", C.Re, C.Im);
  }
  else 
  {
    printf("%.2f+%.2fi\n", C.Re, C.Im);
  }
}
/* I.S. : C sembarang */
/* F.S. : Nilai C ditulis dengan format "a + bi" atau "a - bi" (tanpa spasi) dan diakhiri newline */
/* Proses : Menulis nilai Re dan Im ke layar */

/* ***************************************************************** */
/* KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE                         */
/* ***************************************************************** */
COMPLEX AddCOMPLEX(COMPLEX C1, COMPLEX C2)
{
  COMPLEX result;
  result.Re = C1.Re + C2.Re;
  result.Im = C1.Im + C2.Im;
  return result;
}
/* Mengirim hasil penjumlahan C1 + C2 */

COMPLEX SubtractCOMPLEX(COMPLEX C1, COMPLEX C2)
{
  COMPLEX result;
  result.Re = C1.Re - C2.Re;
  result.Im = C1.Im - C2.Im;
  return result;
}
/* Mengirim hasil pengurangan C1 - C2 */

COMPLEX MultiplyCOMPLEX(COMPLEX C1, COMPLEX C2)
{
  COMPLEX result;
  result.Re = ((C1.Re * C2.Re) - (C1.Im * C2.Im)); 
  result.Im = ((C1.Re * C2.Im) + (C1.Im * C2.Re));
  return result;

}
/* Mengirim hasil perkalian C1 * C2 */
/* Rumus: (a + bi) * (c + di) = (ac - bd) + (ad + bc)i */
/* (ac + adi + bci + - bd)*/

COMPLEX DivideCOMPLEX(COMPLEX C1, COMPLEX C2)
{
  COMPLEX result;
  float denominator;

  denominator = (C2.Re * C2.Re) + (C2.Im * C2.Im);

  if (denominator == 0) 
  {
    result.Re = 0;
    result.Im = 0;
  }
  else
  {
    result.Re = ((C1.Re*C2.Re) + (C1.Im*C2.Im))/denominator;
    result.Im = ((C1.Im*C2.Re) - (C1.Re*C2.Im))/denominator;  
  }
  return result;
}
/* Mengirim hasil pembagian C1 / C2 */
/* Rumus: (a + bi) / (c + di) = 
[(a + bi)(c - di)] / (c^2 + d^2) */
/*[ac - adi + bci + bd]*/
/* Jika denominator pecahan bernilai 0, maka kembalikan nilai 0+0i*/

/* ***************************************************************** */
/* KELOMPOK OPERASI LAIN TERHADAP TYPE                               */
/* ***************************************************************** */
float AbsCOMPLEX(COMPLEX C)
{
  return sqrt(C.Re*C.Re + C.Im*C.Im);
}
/* Mengirim nilai absolut (modulus) dari C */
/* Rumus: |C| = sqrt(Re^2 + Im^2) */

COMPLEX ConjugateCOMPLEX(COMPLEX C)
{
  COMPLEX result;
  result.Re = C.Re;
  result.Im = C.Im*-1;
  return result;
}
/* Mengirim hasil konjugasi dari C */
/* Rumus: Conj(C) = Re - i*Im */

/* *** Kelompok Operator Relational *** */
boolean CEQ(COMPLEX C1, COMPLEX C2)
{
  return (C1.Re == C2.Re && C1.Im == C2.Im);
}
/* Mengirimkan true jika C1 = C2 (Re dan Im sama) */

boolean CNEQ(COMPLEX C1, COMPLEX C2)
{
  return !(C1.Re == C2.Re && C1.Im == C2.Im);
}
/* Mengirimkan true jika C1 tidak sama dengan C2 */

/* ***************************************************************** */
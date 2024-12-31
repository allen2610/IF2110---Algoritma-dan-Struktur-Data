#include "point.h"
#include "complex.h"
#include <stdio.h>

COMPLEX PowerCOMPLEX(COMPLEX C, int P) {
  COMPLEX result;
  int i;

  if(P==0) {
    CreateComplex(&result, 1.0, 0.0);
    return result;
  }

  CreateComplex(&result, Real(C), Imag(C));
  for (i = 2; i<= P; ++i) {
    result = MultiplyCOMPLEX(result,C);
  }
}

void TransformPointByComplexPower(POINT *P, COMPLEX C, int n) {
  if(n == 0) {
    printf("Titik keluar dari lingkaran pada iterasi ke 0");
    return;
  }
  int i;
  COMPLEX pC = C;

  for(i = 1; i <= n; ++i) {
    float X, Y;
    X = Absis(*P) * Real(pC) - Ordinat(*P) * Imag(pC);
    Y = Absis(*P) * Imag(pC) + Ordinat(*P) * Real(pC);
    Absis(*P) = X;
    Ordinat(*P) = Y;
    pC = MultiplyCOMPLEX(pC,C);

    if(Absis(*P) * Absis(*P) + Ordinat(*P) * Ordinat(*P) >= 1.0) {
      printf("Titik keluar dari lingkaran pada iterasi ke %d", i);
      return;
    }
  }
  printf ("Titik tetap berada di dalam lingkaran setelah %d iterasi", n);
}
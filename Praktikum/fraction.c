#ifndef FRACTION_H
#define FRACTION_H

#include "boolean.h"
#include "fraction.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int N;   /* Pembilang */
    int D; /* Penyebut */
} FRACTION;

#define Numerator(F) (F).N
#define Denominator(F) (F).D

int gcd(int a, int b) {
  if(b == 0) return a;
  return gcd(b, a%b);
}

boolean IsFRACTIONValid(int N, int D) {
  return (D != 0);
}

void CreateFRACTION(FRACTION *F, int N, int R) {
  Numerator (*F) = N;
  Denominator(*F) = R;
}

void ReadFRACTION(FRACTION *F) {
  int N,R;
  scanf("%d %d", &N, &R);
  while(!IsFRACTIONValid(N,R)) {
    printf("FRACTION tidak valid\n");
    scanf("%d %d", &N, &R);
  }
  CreateFRACTION(F,N,R);
}

void WriteFRACTION(FRACTION F){
  int N = Numerator(F);
  int R = Denominator(F);

  int sign = ((N<0) ^ (R<0));

  int B = gcd(abs(N), abs(R));
  N /= B;
  R /= B;

  if(sign) {
    printf("-");
  }

  printf("%d/%d", abs(N), abs(R));
}

FRACTION AddFRACTION(FRACTION F1, FRACTION F2) {
  int N = Numerator(F1) * Denominator(F2) + Numerator(F2) * Denominator(F1);
  int D = Denominator(F1) * Denominator(F2);

  int B = gcd(N, D);
  N /= B;
  D /= B;

  FRACTION result;
  CreateFRACTION(&result, N, D);
  return result;
}

FRACTION SubtractFRACTION(FRACTION F1, FRACTION F2) {
  int N = Numerator(F1) * Denominator(F2) - Numerator(F2) * Denominator(F1);
  int D = Denominator(F1) * Denominator(F2);

  int B = gcd(N, D);
  N /= B;
  D /= B;

  FRACTION result;
  CreateFRACTION(&result, N, D);
  return result;
}

FRACTION MultiplyFRACTION(FRACTION F1, FRACTION F2) {
  int N = Numerator(F1) * Numerator(F2); 
  int D = Denominator(F1) * Denominator(F2);

  int B = gcd(N, D);
  N /= B;
  D /= B;

  FRACTION result;
  CreateFRACTION(&result, N, D);
  return result;
}

FRACTION DivideFRACTION(FRACTION F1, FRACTION F2) {
  int N = Numerator(F1) * Denominator(F2); 
  int D = Denominator(F1) * Numerator(F2);

  int B = gcd(N, D);
  N /= B;
  D /= B;

  FRACTION result;
  CreateFRACTION(&result, N, D);
  return result;
}

FRACTION MultiplyNumberFRACTION(int n, FRACTION F1) {
  int N = n * Numerator(F1); 
  int D = Denominator(F1);

  int B = gcd(N, D);
  N /= B;
  D /= B;

  FRACTION result;
  CreateFRACTION(&result, N, D);
  return result;
}

FRACTION SimplifyFRACTION(FRACTION F) {
  int N = Numerator(F);
  int D = Denominator(F);

  int B = gcd(N, D);
  N /= B;
  D /= B;

  FRACTION result;
  CreateFRACTION(&result, N, D);
  return result;
}

float ToDecimal(FRACTION F) {
  float N = Numerator(F);
  float D = Denominator(F);
  return (N/D);
}
/* Mengonversi FRACTION ke bentuk desimal */

#endif
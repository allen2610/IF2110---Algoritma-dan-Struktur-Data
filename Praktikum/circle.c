#ifndef CIRCLE_H
#define CIRCLE_H

#include "boolean.h"
#include "point.h"
#include "circle.h"

/* *** Definisi TYPE CIRCLE *** */
typedef struct {
    POINT CENTER;   /* titik tengah */
    float R;        /* radius */
} CIRCLE;

#define Center(C) (C).CENTER
#define Radius(C) (C).R

boolean IsCIRCLEValid(float X, float Y, float R) {
  return R > 0.0;
}

void CreateCIRCLE(CIRCLE *C, float X, float Y, float R) {
  POINT P;
  CreatePoint(&P,X,Y);
  Center(*C) = P;
  Radius(*C) = R;
}

void ReadCIRCLE(CIRCLE *C) {
  float X, Y, R;
  scanf("%f %f %f", &X, &Y, &R);
  while(!IsCIRCLEValid(X,Y,R)) {
    printf("CIRCLE tidak valid\n");
    scanf("%f %f %f", &X, &Y, &R);
  }
  CreateCIRCLE(C,X,Y,R);
}

void WriteCIRCLE(CIRCLE C) {
  POINT P = Center(C);
  float X = Absis(P);
  float Y = Ordinat(P);
  float R = Radius(C);
  printf("P(%.2f,%.2f) r=%.2f", X, Y, R);
}

float Circumference(CIRCLE C){
  float pi = 3.14;
  return (2.0 * pi * Radius(C));
}

float Area(CIRCLE C) {
  float pi = 3.14;
  return (pi * Radius(C) * Radius(C));
}

boolean IsPOINTInsideCIRCLE(CIRCLE C, POINT P) {
  return (Panjang(P, Center(C)) < Radius(C));
}

boolean IsPOINTInEdgeCIRCLE(CIRCLE C, POINT P) {
  return (Panjang(P, Center(C)) - Radius(C)) <= 1e-7;
}

boolean IsCIRCLEInsideCIRCLE(CIRCLE C1, CIRCLE C2) {
  return (Panjang(Center(C1), Center(C2)) < fabs(Radius(C1) - Radius(C2)));
}

boolean IsCIRCLESTangents(CIRCLE C1, CIRCLE C2){
  return (fabs(Panjang(Center(C1), Center(C2)) - fabs(Radius(C1) + Radius(C2))) <= 1e-7 || fabs(Panjang(Center(C1), Center(C2)) - fabs(Radius(C1) - Radius(C2))) <= 1e-7);
}

boolean IsCIRCLESIntersects(CIRCLE C1, CIRCLE C2) {
  return (fabs(Radius(C1) - Radius(C2)) < Panjang(Center(C1),Center(C2)) && Panjang(Center(C1), Center(C2)) < fabs(Radius(C1) + Radius(C2)));
}

#endif
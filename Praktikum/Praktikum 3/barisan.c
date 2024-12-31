#include "listdin.h"
#include <stdio.h>
#include <stdlib.h>

int main () {
  /*KAMUS*/
  int N, i, j, hasil = 0, x, panjang;
  ListDin l;

  /*ALGORITMA*/
  scanf("%d", &N);
  CreateListDin(&l, N);

  for (i = 0; i < N; i++) {
    scanf("%d", &x);

    int id = listLength(l);
    for(j = 0; j < listLength(l); j++) {
      if(ELMT(l, j) > x) {
        hasil++;
        if (id == listLength(l)) {
          id  = j;
        }
      }
    }
    for(j = listLength(l) - 1; j >= id; j--) {
      ELMT(l, j+1) = ELMT(l, j);
    }
    ELMT(l, id) = x;
    NEFF(l)++;
  }

  printf("%d\n", hasil);
  return 0;
}
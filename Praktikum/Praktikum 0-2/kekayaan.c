#include "liststatik.h"
#include <stdio.h>
#include <stdlib.h>

int main () {

  /*KAMUS*/
  int i,j = 0;
  int simpan = 1;

  /*ALGORITMA*/
  ListStatik l;
  CreateListStatik(&l);
  readList(&l);

  i = getLastIdx(l);
  j = i - 1;

  for (i = getLastIdx(l); i >= 0; i--) {
    ELMT(l, i) += simpan;
    if(ELMT(l, i) == 10) {
      simpan = 1;
      ELMT (l,i) = 0;
    } else {
      simpan = 0;
      break;
    }
  }

  if(simpan == 1) {
    printf("1 ");
  }

  for (i = 0; i < listLength(l); i++) {
    printf("%d", ELMT(l,i));
    if (i != listLength(l)-1) {
      printf(" ");
    }
  }

  printf("\n");
  return 0;
}
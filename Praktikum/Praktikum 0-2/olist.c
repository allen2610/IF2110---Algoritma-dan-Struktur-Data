#include "liststatik.h"
#include <stdio.h>
#include <stdlib.h>

int main () {
  /*KAMUS*/
  ListStatik l1, l2;
  int i,j, count;
  IdxType val;
  
  /*ALGORITMA*/
  CreateListStatik(&l1);
  CreateListStatik(&l2);
  readList(&l1);

  for (i = 0; i <listLength(l1); i++) {
    for (j = 0; j < i; j++) {
      if(ELMT(l1, i) == ELMT(l1, j)) {
        break;
      }
    }
    if(i == j) {
        insertLast(&l2, ELMT(l1,i));
    }
  }

  printList(l2);
  printf("\n");

  for (i = 0; i < listLength(l2); i++) {
    count = 0;
    for (j = 0; j < listLength(l1); j++) {
      if(ELMT(l2,i) == ELMT(l1, j)) {
        count++;
      }
    }
    printf("%d %d\n", ELMT(l2,i), count);
  }
  return 0;
}
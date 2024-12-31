#include "liststatik.h"
#include <stdio.h>
#include <stdlib.h>

int main () {
  /*KAMUS*/
  ListStatik l;
  CreateListStatik(&l);
  readList(&l);
  ElType temp1 = MARK, temp2 = MARK;
  int i, j, count, count1 = 0, count2 = 0;

  /*ALGORITMA*/
  for (i = 0; i < listLength(l); i++) {
    count = 0;
    for (j = 0; j < listLength(l); j++) {
      if(ELMT(l,i) == ELMT(l,j)) {
        count++;
      }
    }
    if(count == count1 && temp1 > ELMT(l, i)) {
      temp1 = ELMT(l,i);
    } 
    if(count == count2 && temp2 > ELMT(l, i)) {
      temp2 = ELMT(l,i);
    } 
    if(count > count1) {
      count2 = count1;
      temp2 = temp1;
      count1 = count;
      temp1 = ELMT(l,i);
    }
    if(count > count2 && count < count1) {
      count2 = count;
      temp2 = ELMT(l,i);
    }
  }
  
  if (count2 != 0) {
    printf("%d\n", temp2);
  } else {
    printf("Tidak ada elemen kedua yang paling sering muncul\n");
  }
  
  return 0;
}
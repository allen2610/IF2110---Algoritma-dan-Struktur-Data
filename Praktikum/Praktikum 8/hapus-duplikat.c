#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"
#include "hapus-duplikat.h"

List hapusDuplikat(List l) {
  if (isEmpty(l)) {
    return l;
  }

  List result;
  CreateList(&result);

  int count[1001] = {0};

  ElType last = IDX_UNDEF;
  int i;

  for (i = 0; i < length(l); i++) {
    ElType val = getElmt(l, i);
    count[val]++;
  }

  for (i = 0; i < length(l); i++) {
    ElType val = getElmt(l,i);

    if (count[val] == 1) {
      insertFirst(&result, val);
    }
  }

  return result;
}
#include <stdio.h>
#include "list_circular.h"
#include "boolean.h"

int main() {
  int N; scanf("%d",  &N);

  List l;
  CreateList(&l);

  for (int i = 0; i < N; i++) {
    int value = 0;
    scanf("%d",&value);
    insertLast(&l, value);
  }

  Address p = FIRST(l);
  Address maxp;
  int max = INFO(p);
  int idxMax = 0;
  
  for (int i = 0; i < N; i++) {
    if (INFO(p) >= max) {
      max = INFO(p);
      idxMax = i;
      maxp = p;
    }
    p = NEXT(p);
  }

  FIRST(l) = maxp;

  displayList(l);
}
#include <stdio.h>
#include "listdin.h"


int main() {
  /*KAMUS*/
  ListDin l, l1, l2;
  int N, i;
  int first, last, result;
  result = 0;


  /*ALGORITMA*/
  scanf("%d", &N);
  CreateListDin(&l, N);
  CreateListDin(&l1, N);
  CreateListDin(&l2, N);


  for (i = 0; i < N; i++) 
  {
      scanf("%d", &ELMT(l, i));
  }

  ELMT(l1, 0) = ELMT(l, 0);
  ELMT(l2, N-1) = ELMT(l, N-1);
  NEFF(l1)++;
  NEFF(l2)++;
  
  for (i = 1; i < N; i++) 
  {
      if (ELMT(l, i) > ELMT(l1, i-1)) 
      {
          ELMT(l1, i) = ELMT(l, i);
      }
      else 
      {
          ELMT(l1, i) = ELMT(l1, i-1);
      }


      if (ELMT(l, N-i-1) < ELMT(l2, N-i))
      {
          ELMT(l2, N-i-1) = ELMT(l, N-i-1);
      }
      else 
      {
          ELMT(l2, N-i-1) = ELMT(l2, N-i);
      }
      NEFF(l1)+=1;
      NEFF(l2)+=1;

  }
  for (i = 0; i < N; i++) 
  {
      first = -1;
      if (i > 0) 
      {
          first = ELMT(l1, i-1);
      }
      last = 99999999;
      if (i < N-1) 
      {
          last = ELMT(l2, i+1);
      } 
      if (last > ELMT(l, i) && first < ELMT(l, i)) 
      {
          result+=1;
      }
  }

  printf("%d\n", result);
  return 0;
}


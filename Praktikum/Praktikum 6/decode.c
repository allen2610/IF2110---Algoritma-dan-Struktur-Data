#include <stdio.h>
#include "stack.h"

int main () {
  /*KAMUS*/
  int i , N, len, k, count, power, j, l;
  char c, val;
  char arr[MaxEl];
  Stack S;
  CreateEmpty(&S);

  /*ALGORITMA*/
  scanf("%d", &N);

  for (i = 0; i < N; i++) {
    scanf(" %c", &c);

    if(c == ']') {
      len = 0;
      while (InfoTop(S) != '[') {
        Pop(&S, &arr[len]);
        len++;
      }

      arr[len] = '\0';

      Pop(&S, &val); //ini untuk bracket

      k = 0;
      count = 0;

      while (InfoTop(S) <= '9' && InfoTop(S) >= '0') { //sampai habis angkanya
        Pop(&S, &val); //next angka liao
        power = 1;
        for (j = 0; j < count; j++) {
          power *= 10;
        }
        count ++;
        k += (val - '0') * power;
      }

      for (j = 0; j < k; j++) { //masukin array ke stack k times
        for (l = len - 1; l >= 0; l--) {
          Push (&S, arr[l]);
        }
      }
    } else {
      Push(&S, c);
    }
  }

  len = Top(S);
  for (i = 0; i <= len; i++) {
    printf("%c", S.T[i]);
  }
  printf("\n");

  return 0;
}
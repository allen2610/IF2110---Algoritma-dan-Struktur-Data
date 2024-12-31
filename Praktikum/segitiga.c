#include <stdio.h>

int main() {
  int n;
  int i;
  int j;
  scanf("%d", &n);
  while(n<0 || n>100) {
      scanf("%d", &n);
  }

  for (i=0; i<n; i++) {
    for (j=0; j<i; j++) {
      printf(" ");
    }
    for (j=0; j<(2*(n-i)-1); j++) {
      printf("*");
    }
    printf("\n");
  }
  return 0;
}
#include <stdio.h>

int main () {
  int n,a,b,i,j,count,temp1,temp2;
  scanf("%d %d %d", &n,&a,&b);
  temp1 = a;
  temp2 = b;
  for (i=0; i<(n-2);i++){
    count = temp1 + temp2;
    temp1 = temp2;
    temp2 = count;
  }
  printf("%d\n", count);
}
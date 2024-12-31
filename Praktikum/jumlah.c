#include <stdio.h>

int main() {
  int n, k, a, i, count;
  count=0;
  scanf("%d %d", &n, &k);
  while(n<1||n>1000||k<1||k>1000){
    scanf("%d %d", &n, &k);
  }
  for (i=0;i<n;i++){
    scanf("%d",&a);
    if(a%k!=0){
      count+=a ;
    }
  }
  printf("%d\n", count);
  return 0;
}
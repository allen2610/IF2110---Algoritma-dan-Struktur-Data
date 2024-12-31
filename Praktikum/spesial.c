#include <stdio.h>

int main () {
  int a,b,i,j,count;
  scanf("%d %d", &a, &b);
  while(a<1 || a>b || b>1000){
    scanf("%d %d", &a, &b); 
  }
  printf("%d",a);
  while (a<=b) {
    if(a%2==1){
      a+=1;
      if(a<=b){
        printf(" %d", a);      
      }
    }
    else{
      a*=2;
      if(a<=b){
        printf(" %d", a);      
      }
    }
  }
  printf("\n");
  return 0;
}
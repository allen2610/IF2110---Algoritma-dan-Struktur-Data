#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

int main () {
    List l1, l2, output;
    CreateList(&l1);
    CreateList(&l2);
    CreateList(&output);
    int val;

    scanf("%d", &val);
    while (val != -1) {
        insertLast(&l1, val);
        scanf(" %d", &val);
    }

    scanf("%d", &val);
    while (val != -1) {
        insertLast(&l2, val);
        scanf(" %d", &val);
    }

    int length1 = length(l1);
    int length2 = length(l2);
   
    if(length1 > length2) {
        int beda = length1 - length2;
        for (int i = 0; i < beda; i++) {
                int val = 0;
                insertFirst(&l2,val);
            }
    } else if (length1 < length2) {
        int beda = length2 - length1;
        for (int i = 0; i < beda; i++) {
                int val = 0;
                insertFirst(&l1,val);
            }
    }

    int carry = 0;
    while (!isEmpty(l1)) {
        int val1,val2,sum = 0;
        deleteLast(&l1, &val1);
        deleteLast(&l2, &val2);
        sum = val1+val2+carry;
        if (sum >= 10) {
            carry = 1;
            sum -= 10;
        }
        else {
            carry = 0;
        }
        insertFirst(&output, sum);
   }
   
   if (carry == 1) {
    insertFirst(&output,carry);
   }
    Address p;
    p = FIRST(output);
    while(p != NULL) {
        printf("%d", INFO(p));
        p = NEXT(p);
        if (p != NULL) {
            printf(" ");
        }   
    }

    printf("\n");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

int main () {
    int val, idx;
    List l;
    CreateList(&l);

    scanf("%d", &val);
    while (val != -9999) {
        if (isEmpty(l)) {
            insertLast(&l, val);
        } else {
            idx = 0;
            while (idx < length(l) && val > getElmt(l, idx)) {
                idx++;
            }
            insertAt(&l, val, idx);                
        }
        scanf(" %d", &val);
    }

    displayList(l);
    return 0;
}
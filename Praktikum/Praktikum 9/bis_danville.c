#include <stdio.h>
#include <stdlib.h>
#include "list_circular.h"

int main () {
    List l;
    CreateList(&l);
    int N, i, val, count = 0;
    boolean found = false;

    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        scanf(" %d", &val);
        insertLast(&l, val);
    }

    while (!found && count < N) {
        Address p = FIRST(l);

        deleteFirst(&l, &val);
        insertLast(&l, val);

        found = true;
        if(INFO(p) < INFO(NEXT(p))) {
            for (i = 0; i < N -1; i++) {
                if (INFO(p) > INFO(NEXT(p))) {
                    found = false;
                } 
                p = NEXT(p);
            }

        } else {
            for (i = 0; i < N -1; i++) {
                if (INFO(p) < INFO(NEXT(p))) {
                    found = false;
                } 
                p = NEXT(p);
            }   
        }
        count++;
    }

    if (found) {
        printf("YES\n");
    } else {
        printf ("NO\n");
    }

    return 0;
}
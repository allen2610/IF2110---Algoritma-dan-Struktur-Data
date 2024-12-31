#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

int main () {
    char c;
    int val, buang;
    List todo;
    CreateList(&todo);

    scanf("%c", &c);
    while (c != 'X') {
        if (c == 'P') {
            scanf(" %d", &val);
            insertFirst(&todo, val);
        }
        if (c == 'I') {
            scanf(" %d", &val);
            insertLast(&todo, val);
        }
        if (c == 'C') {
            if(!isEmpty(todo)) {
                deleteFirst(&todo, &buang);
            }
        }
        if (c == 'D') {
            int idx = -1;
            scanf(" %d", &val);
            idx = indexOf(todo, val);
            if(idx != IDX_UNDEF) {
                deleteAt(&todo, idx, &buang);
            }
        }
        scanf("%c", &c);
    }
    displayList(todo);

    return 0;

}
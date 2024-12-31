#include <stdio.h>
#include "list_circular.h"

int main() {
    int N;
    List l;
    CreateList(&l);
    scanf("%d", &N);
    boolean del[N+69];

    for (int i = 1; i <= N; i++) {
        insertLast(&l, i);
        del[i] = false;
    }

    int ans = 0;
    boolean first = 1;
    int li = N;
    for (int i = 0; i < N-1; i++) {
        int input;
        scanf("%d", &input);
        
        Address now = FIRST(l);
        Address prev = now;
        Address deleted = NEXT(now);
        Address next = NEXT(deleted);
        
        if (input > 0 || first) input--;
        input %= li;
        input += li;
        input %= li;
        
        if (input == 0) input = li;

        for (int j = 1; j <= input; j++) {
            prev = NEXT(prev);
            deleted = NEXT(deleted);
            next = NEXT(next);
        }

        NEXT(prev) = next;
        FIRST(l) = deleted;
        del[INFO(deleted)] = 1;
        ans = INFO(prev);
        li--;
        first = 0;
    }

    for (int i = 1; i <= N; i++) {
        if (!del[i]) {
            printf("%d\n", i);
            break;
        }
    }
    
    return 0;
}
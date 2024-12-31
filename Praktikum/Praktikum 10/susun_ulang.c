#include "listrec.h"
#include "stdlib.h"
#include "stdio.h"

List last(List l, ElType *val) {
    if(NEXT(l) == NIL) {
        *val = INFO(l);
        return NIL;
    }
    NEXT(l) = last(NEXT(l), val);
    return l;
}

void sort(List l, List *res) {
    if(l == NIL){
        return;
    }
    if(length(l) == 1) {
        *res = konso(*res, INFO(l));
        return;
    }
    ElType a, b;
    a = INFO(l);
    l = last(l, &b);
    l = deleteFirst(l);
    sort(l, res);
    *res = konso(*res, b);
    *res = konso(*res, a);
}

int main() {
    List l, res;
    l = NIL; res = NIL;

    int N; scanf("%d", &N);

    for(int i = 0; i < N; ++i) {
        int a; scanf("%d", &a);
        l = konsb(l, a);
    }

    sort(l, &res);
    displayList(res);

    return 0;
}
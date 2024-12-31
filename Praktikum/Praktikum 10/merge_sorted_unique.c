#include "listrec.h"
#include <stdio.h>
#include <stdlib.h>

void mergeSortedUnique(List l1, List l2, List *res) {
    if(l1 == NIL && l2 == NIL) {
        *res = NIL;
        return;
    }
    if(l1 == NIL) {
        mergeSortedUnique(l1, NEXT(l2), res);
        ElType c = INFO(l2);
        if(*res == NIL) {
            *res = newNode(c);
        } else if(INFO(*res) != c) {
            *res = konso(*res, c);
        }
        return;
    }
    if(l2 == NIL) {
        mergeSortedUnique(NEXT(l1), l2, res);
        ElType c = INFO(l1);
        if(*res == NIL) {
            *res = newNode(c);
        } else if(INFO(*res) != c) {
            *res = konso(*res, c);
        }
        return;
    }

    ElType a = INFO(l1), b = INFO(l2);
    if(a == b) {
        mergeSortedUnique(NEXT(l1), NEXT(l2), res);
        if(*res == NIL) {
            *res = newNode(a);
        } else if(INFO(*res) != a) {
            *res = konso(*res, a);
        }
    } else if(a > b) {
        mergeSortedUnique(l1, NEXT(l2), res);
        if(*res == NIL) {
            *res = newNode(b);
        } else if(INFO(*res) != b) {
            *res = konso(*res, b);
        }
    } else if(a < b) {
        mergeSortedUnique(NEXT(l1), l2, res);
        if(*res == NIL) {
            *res = newNode(b);
        } else if(INFO(*res) != a) {
            *res = konso(*res, a);
        }
    }
    return;
}
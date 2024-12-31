#include <stdio.h>
#include "boolean.h"
#include "listdin.h"
#include <math.h>


int main() {
    int N;
    ListDin list,result;
    int i, list1, list2;
    boolean masuk;
    masuk = 0;
    scanf("%d", &N);
    CreateListDin(&list, N);
    CreateListDin(&result, N+99);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &ELMT(list, i));
        NEFF(list)+=1;
    }
    scanf("%d", &list1);
    scanf("%d", &list2);
    for (i = 0; i < listLength(list); i+=2) {
        int elmtnext = ELMT(list, i);
        int elmtnext2 = ELMT(list, i+1);
        if (elmtnext > list2 && !masuk) {
            insertLast(&result, list1);
            insertLast(&result, list2);
            masuk = 1;
        }
        if (listLength(result) > 0 && ELMT(result, getLastIdx(result)) >= elmtnext) {
            if (ELMT(result, getLastIdx(result)) < elmtnext2) {
                ELMT(result, getLastIdx(result)) = elmtnext2;
            }
            continue;
        }
        if (!masuk && elmtnext2 >= list1 && list2 >= elmtnext) {
            masuk = 1;
            if (elmtnext > list1) {
                elmtnext = list1;
            }
            if (elmtnext2 < list2) {
                elmtnext2 = list2;
            }
        }
        insertLast(&result, elmtnext);
        insertLast(&result, elmtnext2);
    }
    if (!masuk) 
    {
        insertLast(&result, list1);
        insertLast(&result, list2);
    }

    for (int i = 0; i < listLength(result); i++) 
    {
        if (i != listLength(result) - 1) printf("%d ", ELMT(result, i));
        else printf("%d\n", ELMT(result, i));
    }
}


















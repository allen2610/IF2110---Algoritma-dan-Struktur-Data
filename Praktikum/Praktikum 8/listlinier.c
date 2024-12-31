#include "listlinier.h"
#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>

Address newNode(ElType val) {
    Address p = (Address)malloc(sizeof(Node));
    if (p != NULL) {
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l) {
    FIRST(*l) = NULL;
}

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l) {
    return (FIRST(l) == NULL);
}

/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx) {
    int i = 0;
    List p = l;

    while (i < idx) {
        p = NEXT(p);
        i++;
    }
    return INFO(p);
}

void setElmt(List *l, int idx, ElType val) {
    int i = 0;
    Address p = *l;

    while (i < idx) {
        p = NEXT(p);
        i++;
    }
    INFO(p) = val;
}

int indexOf(List l, ElType val) {
    List p = l;
    int i = 0;
    boolean found = false;

    while ((p != NULL) && (!found)) {
        if (INFO(p) == val) {
            found = true;
        }
        else {
            p = NEXT(p);
            i++;
        }
    }

    if (found) {
        return i;
    }
    else {
        return IDX_UNDEF;
    }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val) {
    
    Address p;

    p = newNode(val);
    if (p == NULL) {}
    else {
        NEXT(p) = *l;
        *l = p;
    }
}

void insertLast(List *l, ElType val) {
 
    Address p, q;

    q = *l;
    p = newNode(val);
    if (p == NULL) {}
    else {
        if (isEmpty(*l)) {
            insertFirst(l, val);
        }
        else {
            while (NEXT(q) != NULL) {
                q = NEXT(q);
            }
            NEXT(q) = p;
        }
    }
}

void insertAt(List *l, ElType val, int idx) {
    Address p, q;
    int i = 0;

    q = *l;
    p = newNode(val);
    if (p == NULL) {}
    else {
        if (idx == 0) {
            insertFirst(l, val);
        }
        else {
            while (i < idx - 1) {
                i++;
                q = NEXT(q);
            }
            NEXT(p) = NEXT(q);
            NEXT(q) = p;
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val) {
    Address p = *l;

    *val = INFO(p);
    if (NEXT(p) == NULL) {
        *l = NULL;
        free(*l);
        CreateList(l);
    }
    else {
        *l = NEXT(p);
        free(p);
    }
}
void deleteLast(List *l, ElType *val)
{

    Address p, q;

    if (NEXT(*l) == NULL) {
        deleteFirst(l, val);
    }
    else {
        p = *l;
        q = NULL;
        while (NEXT(p) != NULL) {
            q = p;
            p = NEXT(p);
        }
        if (q == NULL) {
            *l = NULL;
        }
        else {
            NEXT(q) = NULL;
        }
        *val = INFO(p);
        free(p);
    }
}

void deleteAt(List *l, int idx, ElType *val){
    Address p, q;
    int i = 0;

    if (NEXT(*l) == NULL) {
        deleteFirst(l, val);
    }
    else {
        if (idx == 0) {
            deleteFirst(l, val);
        }
        else {
            p = *l;
            while (i < idx) {
                q = p;
                p = NEXT(p);
                i++;
            }
            *val = INFO(p);
            NEXT(q) = NEXT(p);
            NEXT(p) = NULL;
            free(p);
        }
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l) {

    Address p;

    p = l;

    printf("[");

    if (!isEmpty(l)) {
        while (NEXT(p) != NULL) {
            printf("%d,", INFO(p));
            p = NEXT(p);
        }
        printf("%d", INFO(p));
    }

    printf("]");
}

int length(List l) {
    int count = 0;
    Address p;


    p = l;
    if (isEmpty(l)) {
        return count;
    }
    else {
        count = 1;
        while (NEXT(p) != NULL)
        {
            p = NEXT(p);
            count++;
        }
        return count;
    }
}

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2) {
    Address p;
    List l3;
    ElType val;
    CreateList(&l3);
    p = l1;
    while (p != NULL) {
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    p = l2;
    while (p != NULL) {
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }

    return l3;
}

#ifndef LISTSTATIK_H
#define LISTSTATIK_H

#include <stdio.h>
#include "liststatik.h"
#include "boolean.h"

/*  Kamus Umum */
#define CAPACITY 100
/* Kapasitas penyimpanan */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/
#define MARK -9999
/* Nilai elemen tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int ElType;  /* type elemen List */
typedef int IdxType;
typedef struct {
   ElType contents[CAPACITY]; /* memori tempat penyimpan elemen (container) */
} ListStatik;

/* ********** SELEKTOR ********** */
#define ELMT(l, i) (l).contents[(i)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatik(ListStatik *l)
{
   int i;
   for (i = 0; i < CAPACITY; i++) {
      ELMT(*l, i) = MARK;
   }
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListStatik l){
   int cnt = 0;
   while (ELMT(l, cnt) != MARK && cnt < CAPACITY) {
      cnt++;
   }
   return cnt;
}

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListStatik l){
  return 0;
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
IdxType getLastIdx(ListStatik l) {
  return listLength(l) - 1; /*last element dikurang satu = indeks elemen terakhir*/
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListStatik l, IdxType i){
   return 0 <= i && i < CAPACITY;
}
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEff(ListStatik l, IdxType i) {
  return 0 <= i && i < listLength(l);
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListStatik l) {
  return listLength == 0;
}
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
boolean isFull(ListStatik l){
  return listLength(l) == CAPACITY;
}

void readList(ListStatik *l) {
   int n,i;
   scanf("%d", &n);

   while (n < 0 || n > CAPACITY) {
      scanf("%d", &n);
   }

   for (i = 0; i < n; i++) {
      scanf("%d", &ELMT(*l, i));
   }
   for (i = n; i < CAPACITY; i++) {
      ELMT(*l, i) = MARK;
   }
}

void printList(ListStatik l) {
  int i;
  printf("[");
   for (i = 0; i < listLength(l); i++) {
      printf("%d", ELMT(l, i));
      if (i != listLength(l) - 1) {
         printf(",");
      }
   }
  printf("]");
}
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus){
   int i;
   ListStatik l;
   CreateListStatik(&l);
   for (i = 0; i < listLength(l1); i++) {
      if (plus) {
         ELMT(l, i) = ELMT(l1, i) + ELMT(l2, i);
      } else {
         ELMT(l, i) = ELMT(l1, i) - ELMT(l2, i);
      }
   }
   return l;
}

boolean isListEqual(ListStatik l1, ListStatik l2) {
   int i;
   if (listLength(l1) != listLength(l2)) {
      return false;
   }

   for (i = 0; i < CAPACITY; i++) {
      if (ELMT(l1, i) != ELMT(l2, i)) {
         return false;
      }
   }

   return true;
}

int indexOf(ListStatik l, ElType val) {
  boolean ketemu = false;
  int i;
   for (i = 0; i < CAPACITY; i++) {
      if (ELMT(l, i) == val) {
         return i;
      }
   }
   return IDX_UNDEF;
}

void extremeValues(ListStatik l, ElType *max, ElType *min) {
   int i;
   *max = ELMT(l, 0);
   *min = ELMT(l, 0);

   for (i = 1; i < listLength(l); i++) {
      if (ELMT(l, i) > *max) {
         *max = ELMT(l, i);
      }

      if (ELMT(l, i) < *min) {
         *min = ELMT(l, i);
      }
   }
}

void insertFirst(ListStatik *l, ElType val) {
  int i;
   for (i = listLength(*l); i > 0; i--) {
      ELMT(*l, i) = ELMT(*l, i - 1);
   }
   ELMT(*l, 0) = val;
}

void insertAt(ListStatik *l, ElType val, IdxType idx)
{
  int i;
   for (i = listLength(*l); i > idx; i--) {
      ELMT(*l, i) = ELMT(*l, i - 1);
   }
   ELMT(*l, idx) = val;
}

void insertLast(ListStatik *l, ElType val){
  ELMT(*l, listLength(*l)) = val;
}

void deleteFirst(ListStatik *l, ElType *val){
   int i;
   *val = ELMT(*l, 0);
   for (i = 0; i < listLength(*l) - 1; i++) {
      ELMT(*l, i) = ELMT(*l, i + 1);
   }
   ELMT(*l, listLength(*l) - 1) = MARK;
}

void deleteAt(ListStatik *l, ElType *val, IdxType idx) {
   int i;
   *val = ELMT(*l, idx);
   for (i = idx; i < listLength(*l) - 1; i++) {
      ELMT(*l, i) = ELMT(*l, i + 1);
   }
   ELMT(*l, listLength(*l) - 1) = MARK;
}

void deleteLast(ListStatik *l, ElType *val)
{
   *val = ELMT(*l, listLength(*l) - 1);
   ELMT(*l, listLength(*l) - 1) = MARK;
}

void sortList(ListStatik *l, boolean asc) {
   int i, j;
   if (asc) {
      for (i = 0; i < listLength(*l) - 1; i++) {
         for (j = i + 1; j < listLength(*l); j++) {
            if (ELMT(*l, i) > ELMT(*l, j)) {
               ElType temp = ELMT(*l, i);
               ELMT(*l, i) = ELMT(*l, j);
               ELMT(*l, j) = temp;
            }
         }
      }
   } else {
      for (i = 0; i < listLength(*l) - 1; i++) {
         for (j = i + 1; j < listLength(*l); j++) {
            if (ELMT(*l, i) < ELMT(*l, j)) {
               ElType temp = ELMT(*l, i);
               ELMT(*l, i) = ELMT(*l, j);
               ELMT(*l, j) = temp;
            }
         }
      }
   }
}

#endif
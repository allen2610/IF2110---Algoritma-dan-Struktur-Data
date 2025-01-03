#ifndef LISTDIN_H
#define LISTDIN_H

#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>

/*  Kamus Umum */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int ElType; /* type elemen list */
typedef int IdxType;
typedef struct
{
    ElType *buffer; /* memori tempat penyimpan elemen (container) */
    int nEff;       /* >=0, banyaknya elemen efektif */
    int capacity;   /* ukuran elemen */
} ListDin;

#define NEFF(l) (l).nEff
#define BUFFER(l) (l).buffer
#define ELMT(l, i) (l).buffer[i]
#define CAPACITY(l) (l).capacity

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity) {
  BUFFER(*l) = (ElType *)malloc(capacity*sizeof(ElType));
  NEFF(*l) = 0;
  CAPACITY(*l) = capacity;
}
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

void dealocateList(ListDin *l) {
  NEFF(*l) = 0;
  CAPACITY(*l) = 0;
  free(BUFFER(*l));
}
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListDin l) {
  return NEFF(l);
}
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListDin l) {
  return IDX_MIN;
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
IdxType getLastIdx(ListDin l) {
  return(IdxType)(listLength(l)-1);
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, IdxType i) {
  return (i>=IDX_MIN) && (i<CAPACITY(l));
}
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEff(ListDin l, IdxType i) {
  return (i>=IDX_MIN) && (i<=NEFF(l));
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l){
  return listLength(l) == 0;
}
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isFull(ListDin l) {
  return listLength(l) == CAPACITY(l);
}
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l) {
  int N;
  IdxType i;
  boolean check = false;
  ElType elm;

  while(check!=true) {
    scanf("%d", &N);
    if((N >= 0) && (N<=CAPACITY(*l))) {
      check = true;
    }
  }
  NEFF(*l) = N;

  if (N > 0) {
    for(i = 0; i <= (IdxType)N -1; i++) {
      scanf("%d", &elm);
      ELMT (*l,i) = elm;
    }
  }
}
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
void printList(ListDin l) {
  IdxType i;
  printf("[");
  for (i=0; i <= NEFF(l) - 1; i++) {
    printf("%d", ELMT(l,i));
    if (i != NEFF(l)-1) {
      printf (",");
    }
  }
  printf("]");
}
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus) {
  IdxType i;
  ListDin Hasil;

  CreateListDin(&Hasil, NEFF(l1));
  for(i = 0; i <= NEFF(l1) - 1; i++) {
    if(plus == true) {
      ELMT(Hasil, i) = ELMT (l1,i) + ELMT(l2,i);
    } else {
      ELMT(Hasil, i) = ELMT (l1,i) - ELMT(l2,i);      
    }
  }
  NEFF(Hasil) = NEFF(l1);
  return Hasil;
}
/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2) {
  boolean sama = true;
  int i=0;

  if (NEFF(l1) == NEFF(l2)) {
    while((i < NEFF(l1)) && (sama == true)) {
      if(ELMT(l1,i) != ELMT(l2,i)) {
        sama = false;
      }
      i++;
    }
  } else {
    sama = false;
  }
  return sama;
}
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val) {
  int i = 0;
  boolean ketemu = false;
  IdxType idx = IDX_UNDEF;

  while((i<NEFF(l)) && (ketemu != true)) {
    if(ELMT(l,i) == val) {
      ketemu = true;
      idx = i;
    }
    i++;
  }
  return idx;
}
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListDin l, ElType *max, ElType *min) {
  int i;
  ElType maxVal, minVal;

  maxVal = ELMT(l,0);
  minVal = ELMT(l,0);

  for (i=0; i<=NEFF(l); i++) {
    if(ELMT(l,i)> maxVal) {
      maxVal = ELMT(l,i);
    }
    if(ELMT(l,i) < minVal) {
      minVal = ELMT(l,i);
    }
  }
  *max = maxVal;
  *min = minVal;
}
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */

/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut) {
  int i;
  CreateListDin(lOut, CAPACITY(lIn));
  NEFF(*lOut) = NEFF(lIn);
  for (i = 0; i < NEFF(lIn); i++) {
    ELMT(*lOut,i) = ELMT(lIn,i);
  }
}
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */ 
ElType sumList(ListDin l) {
  ElType sum = 0;
  IdxType i ;

  for (i = 0; i < NEFF(l); i++) {
    sum = sum + ELMT(l,i);
  }
  return sum;
}
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
int countVal(ListDin l, ElType val) {
  int count = 0;
  int i;

  for (i = 0; i < NEFF(l); i++) {
    if(ELMT(l,i) == val) {
      count++;
    }
  }
  return count;
}
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */

/* ********** SORTING ********** */
void sort(ListDin *l, boolean asc) {
  int i, j;
  ElType temp;
  IdxType idx;

  if(asc == true) {
    for(i = 1; i< NEFF(*l); i++) {
      temp = ELMT(*l,i);
      idx = i-1;
      while((temp < ELMT(*l, idx)) && (idx > 0)) {
        ELMT(*l, idx + 1) = ELMT(*l, idx);
        idx--;
      }
      if(temp >= ELMT(*l, idx)) {
        ELMT(*l, idx + 1) = temp;
      } else {
        ELMT(*l,idx +1) = ELMT(*l, idx);
        ELMT (*l,idx) = temp;
      }
    }
  } else {
    for(i = 1; i < NEFF(*l); i++) {
      temp = ELMT(*l,i);
      idx = i-1;
      while ((temp>ELMT(*l, idx)) && (idx > 0)) {
        ELMT(*l, idx +1) = ELMT(*l, idx);
        idx--;
      }
      if (temp <= ELMT(*l,idx)){
        ELMT(*l, idx+1) = temp;
      } else {
        ELMT(*l, idx+1) = ELMT(*l,idx);
        ELMT(*l, idx) = temp;
      }
    }
  }
}
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListDin *l, ElType val) {
  if(isFull(*l) != true) {
    ELMT(*l, NEFF(*l)) = val;
    NEFF (*l)++;
  }
}
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val) {
  int i;
  if(isEmpty(*l) != true) {
    *val = ELMT(*l, getLastIdx(*l));
    NEFF(*l)--;
  }
}
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandList(ListDin *l, int num) {
  ListDin temp;
  int i;
  CreateListDin(&temp, CAPACITY(*l) + num);
  for (i = 0; i <= NEFF(*l) -1; i++) {
    ELMT(temp,i) = ELMT(*l,i);
  }
  NEFF(temp) = NEFF(*l);

  dealocateList(l);
  copyList(temp, l);
}
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

void shrinkList(ListDin *l, int num) {
  ListDin temp;
  int i;

  CreateListDin (&temp, CAPACITY(*l) - num);
  for (i = 0; i <= NEFF(*l) -1; i++) {
    ELMT(temp,i) = ELMT (*l,i);
  }
  NEFF(temp) = NEFF(*l);
  dealocateList(l);
  copyList(temp,l);
}
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */

void compressList(ListDin *l) {
  ListDin temp;
  int i;

  CreateListDin(&temp, NEFF(*l));
  for (i = 0; i <= NEFF(*l) -1; i++) {
    ELMT(temp,i) = ELMT(*l,i);
  }
  NEFF(temp) = NEFF(*l);
  dealocateList(l);
  copyList(temp,l);
}
/* Proses : Mengubah capacity sehingga nEff = capacity */
/* I.S. List tidak kosong */
/* F.S. Ukuran nEff = capacity */

#endif
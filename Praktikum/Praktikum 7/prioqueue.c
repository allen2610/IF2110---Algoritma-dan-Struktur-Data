#include <stdio.h>
#include "boolean.h"
#include "prioqueue.h"

/* *** Kreator *** */
void CreatePrioQueue(PrioQueue *pq) {
  IDX_HEAD(*pq) = IDX_UNDEF;
  IDX_TAIL(*pq) = IDX_UNDEF;
}
/* I.S. sembarang */
/* F.S. Sebuah pq kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah pq kosong */

/* ********* Prototype ********* */
boolean isEmpty(PrioQueue pq) {
  return (IDX_HEAD(pq) == IDX_UNDEF && IDX_TAIL(pq) == IDX_UNDEF);
}
/* Mengirim true jika pq kosong: lihat definisi di atas */
boolean isFull(PrioQueue pq) {
  return (length(pq) == CAPACITY);
}
/* Mengirim true jika tabel penampung elemen pq sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

int length(PrioQueue pq) {
  if (isEmpty(pq)){
    return 0;
  } 
  if (IDX_HEAD(pq) > IDX_TAIL(pq)) {
    return (IDX_TAIL(pq) - IDX_HEAD(pq) + CAPACITY + 1);
  } else {
    return (IDX_TAIL(pq) - IDX_HEAD(pq) + 1);
  }
}
/* Mengirimkan banyaknya elemen prioqueue. Mengirimkan 0 jika pq kosong. */

/* *** Primitif Add/Delete *** */
void enqueue(PrioQueue *pq, ElType val) {
  if (isEmpty(*pq)) {
    IDX_HEAD(*pq) = 0;
    IDX_TAIL(*pq) = 0;
    TAIL(*pq) = val;
  } else {
    int i, p, len;
    len = length(*pq);
    p = len;

    for (i = 0; i < len; i++) {
      if((*pq).buffer[(IDX_HEAD(*pq) + i) % CAPACITY] <= val) {
        p = i;
        break;
      }
    }
    for (i = len - 1; i >= p; i--) {
      (*pq).buffer[(IDX_HEAD(*pq) + i + 1) % CAPACITY] = (*pq).buffer[(IDX_HEAD(*pq) + i) % CAPACITY];
    }

    (*pq).buffer[(IDX_HEAD(*pq) + p) % CAPACITY] = val;
    IDX_TAIL(*pq) = (IDX_TAIL(*pq) + 1) % CAPACITY;
  }
}
/* Proses: Menambahkan val pada pq dengan aturan FIFO */
/* I.S. pq mungkin kosong, tabel penampung elemen pq TIDAK penuh */
/* F.S. val disisipkan pada posisi yang sesuai, IDX_TAIL "mundur" dalam buffer melingkar.,
        pq terurut mengecil */

void dequeue(PrioQueue *pq, ElType *val) {
  *val = HEAD(*pq);

  if (length(*pq) == 1) {
    IDX_HEAD(*pq) = IDX_UNDEF;
    IDX_TAIL(*pq) = IDX_UNDEF;
  } else {
    IDX_HEAD(*pq) = (IDX_HEAD(*pq) + 1) % CAPACITY;
  }
}
/* Proses: Menghapus val pada pq dengan aturan FIFO */
/* I.S. pq tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        pq mungkin kosong */

/* *** Display Queue *** */
void displayPrioQueue(PrioQueue pq) {
  int p, h;
  p = 0;
  h = IDX_HEAD(pq);
  boolean first = true;

  printf("[");

  while (p < length(pq)) {
    if (first) {
      printf("%d", pq.buffer[(h + p) % CAPACITY]);
      first = false;
    } else {
      printf (",%d", pq.buffer[(h + p) % CAPACITY]);
    }
    p++;
  }

  printf("]\n");
}
/* Proses : Menuliskan isi PrioQueue dengan traversal, PrioQueue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. pq boleh kosong */
/* F.S. Jika pq tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 30, 20, 1 akan dicetak: [30,20,1] */
/* Jika Queue kosong : menulis [] */
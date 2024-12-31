#include <stdio.h>
#include "queue.h"

int main() {
    int N;
    Queue q;
    CreateQueue(&q);
    scanf("%d",&N);

    for (int i = 0; i< N; i++) {
        int input;
        scanf("%d",&input);

        if(input==4) {
            printf("Ukuran Queue saat ini adalah %d\n", length(q));
        }
        else if(input==3) {
            if(isEmpty(q)) {
                printf("Queue Kosong\n");
            }
            else {
                printf("Elemen Awal Queue adalah %d\n", HEAD(q));
            }
        }
        else if(input == 2) {
            if(isEmpty(q)) {
                printf("Queue Kosong\n");
            }
            else {
                int val;
                dequeue(&q,&val);
                printf("Dequeue %d Berhasil\n", val);
            }
        }
        else if(input == 1) {
            int value;
            scanf("%d", &value);
            if (isFull(q)) {
                printf("Queue Penuh\n");
            }
            else {
                enqueue(&q,value);
                printf("Enqueue %d Berhasil\n", value);
            }
        }
    }
    displayQueue(q);
}
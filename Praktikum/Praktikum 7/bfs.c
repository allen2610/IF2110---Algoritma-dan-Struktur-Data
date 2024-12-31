#include <stdio.h>
#include "queue.h"
#include "boolean.h"
#include <stdlib.h>


boolean valid(int inp1, int inp2, int N) {
    return (0 <= inp1 && inp1 < N && 0 <= inp2 && inp2 < N);
}

int main() {   
    int N;
    char array[100][100];
    boolean now[100][100];
    int distance[100][100];
    int awalx, awaly;
    int akhirx, akhiry;
    int sekitarx[4] = {1, -1, 0, 0};
    int sekitary[4] = {0, 0, 1, -1};
    Queue(q);
    CreateQueue(&q);
    ElType val;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("\n %c", &array[i][j]);
            distance[i][j] = -1;
            now[i][j] = false;

            if (array[i][j] == 'A') {
                awalx = i;
                awaly = j;
            }
            if (array[i][j] == 'B') {
                akhirx = i;
                akhiry = j;
            }
        }
    }

  
    val.row = awalx;
    val.col = awaly;
    enqueue(&q, val);

    now[awalx][awaly] = true;
    distance[awalx][awaly] = 0;

    while (!isEmpty(q)) {
        dequeue(&q, &val);
        int nowx = val.row;
        int nowy = val.col;

        for (int i = 0; i < 4; i++) {
            int nextx, nexty;
            nextx = nowx + sekitarx[i];
            nexty = nowy + sekitary[i];

            if (!valid(nextx, nexty, N) || now[nextx][nexty] || array[nextx][nexty] == '#'){
              continue;
            } 

            now[nextx][nexty] = true;  
            distance[nextx][nexty] = distance[nowx][nowy] + 1;
            val.row = nextx;
            val.col = nexty;
            
            enqueue(&q, val);
        }
    }

    if (distance[akhirx][akhiry] == -1) {
        printf("Tidak\n");
    } else {
        printf("Ya\n%d\n", distance[akhirx][akhiry]);
    }
}
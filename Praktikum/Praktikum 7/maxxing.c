#include <stdio.h>
#include "prioqueue.h"

int main()
{
    int N, i, j, k, val;
    scanf("%d", &N);
    PrioQueue q1,q2;
    CreatePrioQueue(&q1);
    CreatePrioQueue(&q2);

    for(i = 0; i < N; i++) {
        scanf("%d",&val);
        enqueue(&q1, val);
    }

    for(j = 0; j<N; j++) {
        val = 0;
        scanf("%d",&val);
        enqueue(&q2, val);
    }

    long long sum = 0;
    for(k = 0; k < N; k++) {
        int val1,val2;
        dequeue(&q1, &val1);
        dequeue(&q2, &val2);
        sum += (long long)val1 * (long long)val2;
    }
    printf("%lld\n",sum);
}
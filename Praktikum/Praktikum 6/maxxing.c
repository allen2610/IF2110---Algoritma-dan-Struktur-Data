#include <stdio.h>
#include "stack.h"

int max(int a, int b){
    if(a > b){
        return a;
    }
    return b;
}

int min(int a, int b){
    if(a < b){
        return a;
    }
    return b;
}

int answer[10007], A[10007], L[10007], R[10007];

int main () {
    Stack S;
    CreateEmpty(&S);

    int N; scanf("%d", &N);

    int x = 2000000000, temp;
    for(int i = 0; i < N; ++i){
        int a; scanf("%d", &a);
        A[i] = a;

        x = min(x, a);
        while(!IsEmpty(S) && a <= A[InfoTop(S)]){
            Pop(&S, &temp);
            R[temp] = i - 1;
        }
        Push(&S, i);
    }
    while(!IsEmpty(S)){
        Pop(&S, &temp);
        R[temp] = N - 1;
    }

    for(int i = N - 1; i >= 0; --i){
        int a, temp, len = 1; a = A[i];

        x = min(x, a);
        while(!IsEmpty(S) && a < A[InfoTop(S)]){
            Pop(&S, &temp);
            L[temp] = i + 1;
        }
        Push(&S, i);
    }
    while(!IsEmpty(S)){
        Pop(&S, &temp);
        L[temp] = 0;
    }

    for(int i = 0; i < N; ++i){
        int len = R[i] - L[i] + 1;
        answer[len] = max(answer[len], A[i]);
    }

    answer[N] = x;
    for(int i = N - 1; i >= 1; --i){
        answer[i] = max(answer[i], answer[i + 1]);
    }

    for(int i = 1; i <= N; ++i){
        printf("%d", answer[i]);
        if(i < N){
          printf(" ");
        }
    }
    printf("\n");

    return 0;
}
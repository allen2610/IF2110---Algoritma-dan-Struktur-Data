#include "matrix.h"
#include <stdio.h>

const int mod = 1e9 + 7;

int main(){
    Matrix M, comp;
    int N;
    scanf("%d", &N);

    createMatrix(N, N, &M);
    createMatrix(2, 2, &comp);
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            int a;
            scanf("%d", &a);
            ELMT(M, i, j) = a;
        }
    }
    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < 2; ++j){
            int a;
            scanf("%d", &a);
            ELMT(comp, i, j) = a;
        }
    }

    int ans = 0;
    for(int i = 0; i < N - 1; ++i){
        for(int j = 0; j < N - 1; ++j){
            int add = 0;
            for(int k = 0; k < 4; ++k){
                if(ELMT(M, i, j) > ELMT(comp, 0, 0) &&
                   ELMT(M, i, j + 1) > ELMT(comp, 0, 1) &&
                   ELMT(M, i + 1, j) > ELMT(comp, 1, 0) &&
                   ELMT(M, i + 1, j + 1) > ELMT(comp, 1, 1)){
                    add = 1;
                }
                int temp = ELMT(comp, 0, 0);
                ELMT(comp, 0, 0) = ELMT(comp, 1, 0);
                ELMT(comp, 1, 0) = ELMT(comp, 1, 1);
                ELMT(comp, 1, 1) = ELMT(comp, 0, 1);
                ELMT(comp, 0, 1) = temp;
            }
            ans += add;
        }
    }

    printf("%d\n", ans);

    return 0;
}
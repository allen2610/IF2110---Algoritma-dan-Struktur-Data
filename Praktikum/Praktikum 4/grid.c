#include "matrix.h"
#include <stdio.h>

const int MOD = 1e9 + 7;

int main(){
    /*KAMUS*/
    Matrix M, dp;
    int N;
    scanf("%d", &N);

    /*ALGORITMA*/
    createMatrix(N, N, &M);
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            int a;
            scanf("%d", &a);
            ELMT(M, i, j) = a;
        }
    }
    if(ELMT(M, 0, 0) == 1){
        printf("0\n");
        return 0;
    }
    createMatrix(N, N, &dp);
    ELMT(dp, 0, 0) = 1;

    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j) {
            if(ELMT(M, i, j) != 0) {
                continue;
            }
            if(i == 0 && j == 0) {
                continue;
            } else if(i == 0) {
                ELMT(dp, i, j) = ELMT(dp, i, j - 1);
            } else if(j == 0) {
                ELMT(dp, i, j) = ELMT(dp, i - 1, j);
            } else {
                ELMT(dp, i, j) = ELMT(dp, i - 1, j) + ELMT(dp, i, j - 1);
                if(ELMT(dp, i, j) >= MOD)ELMT(dp, i, j) -= MOD;
            }
        }
    }
    printf("%d\n", ELMT(dp, N - 1, N - 1));
    return 0;
}
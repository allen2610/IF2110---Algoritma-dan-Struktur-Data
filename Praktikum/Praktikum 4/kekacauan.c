#include "matrix.h"
#include <stdio.h>

const int mod = 1e9 + 7;

int main(){
    Matrix M, dp;
    int N;
    scanf("%d", &N);

    createMatrix(N, N, &M);
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            int a;
            scanf("%d", &a);
            ELMT(M, i, j) = a;
        }
    }
    int ans = 0;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(ELMT(M, i, j) == 0){
                continue;
            }
            for(int k = 0; k < N; ++k){
                if(k == j){
                    continue;
                }
                ans += ELMT(M, i, k);
                if(ans >= mod)ans -= mod; 
            }
            for(int k = 0; k < N; ++k){
                if(k == i){
                    continue;
                }
                ans += ELMT(M, k, j);
                if(ans >= mod)ans -= mod; 
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
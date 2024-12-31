#include "bintree.h"
#include <stdlib.h>

int depthFirstSearch(BinTree now, boolean pr){
    if(now == NULL){
        return 0;
    }
    int res = 0;
    res = (LEFT(now) == NULL ? 0 : depthFirstSearch(LEFT(now), false)) + (RIGHT(now) == NULL ? 0 : depthFirstSearch(RIGHT(now), false));
    
    if(!pr){
        int temp = ROOT(now) + (LEFT(now) == NULL ? 0 : depthFirstSearch(LEFT(now), true)) + (RIGHT(now) == NULL ? 0 : depthFirstSearch(RIGHT(now), true));
        if(temp > res){
            res = temp;
        }
    }

    return res;
}

int mencurry(BinTree T) {
    return depthFirstSearch(T, false);
}
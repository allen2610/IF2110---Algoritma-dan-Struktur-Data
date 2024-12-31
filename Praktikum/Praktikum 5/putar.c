# include <stdio.h>
# include "mesinkata.h"

void printWord() {
    int i;
    for (i = 0; i < currentWord.Length; i++)
    {
        printf("%c", currentWord.TabWord[i]);
    }
}

void balikWord() {
    int i;
    for (i = currentWord.Length - 1; i >= 0; i--)
    {
        printf("%c", currentWord.TabWord[i]);
    }
}

int main() {
    STARTWORD();
    int i = 0;
    while(!EndWord) {
        if (i%2==0){
            balikWord();
        } else {
            printWord();
        }
        ADVWORD();

        if(!EndWord) {
            printf(" ");
        }
        i++;
    }

    printf("\n");
    return 0;
}
#include <stdio.h>
#include "mesinkata.h"
#include <ctype.h>

void printWord() {
    int i;
    for (i = 0; i < currentWord.Length; i++)
    {
        printf("%c", currentWord.TabWord[i]);
    }
}

void decryptWord(int n) {
    for (int i = 0; i < currentWord.Length; i++)
    {
        char x = currentWord.TabWord[i];
        if (isupper(x))
        {
            currentWord.TabWord[i] = ((x - 'A' - n + 26) % 26) + 'A';
        }
        else if (islower(x))
        {
            currentWord.TabWord[i] = ((x - 'a' - n + 26) % 26) + 'a';
        }
    }
}

int castShift() {
    int i;
    int total = 0;
    for (i = 0; i < currentWord.Length; i++) {
        total *= 10;
        total += currentWord.TabWord[i] - '0';
    }

    return total;
}

int main() {
    STARTWORD();
    int x = castShift();
    x %= 26;
    ADVWORD();

    while(!EndWord){
        decryptWord(x);
        printWord();
        ADVWORD();

        if (!EndWord) {
            printf(" ");
        }
        else {
            printf("\n");
        }
    }
}
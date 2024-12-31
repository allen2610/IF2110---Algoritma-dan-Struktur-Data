#include <stdio.h>
#include "mesinkata.h"

void printKata()
{
    int i;
    for (i = 0; i < currentWord.Length; i++)
    {
        printf("%c", currentWord.TabWord[i]);
    }
}

boolean charValid(char c){
    return (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '@');
}

boolean isAllCharValid(){
    for (int i = 0; i < currentWord.Length; i++){
        if (!charValid(currentWord.TabWord[i])){
            return false;
        }
    }
    return true;
}

int countEt (){
    int count = 0;
    for (int i = 0; i < currentWord.Length; i++){
        if (currentWord.TabWord[i] == '@'){
            count++;
        }
    }
    return count;
}

boolean isIPv4Lay(){
    if (!isAllCharValid()){
        return false;
    }

    if (countEt() != 3){
        return false;
    }

    if (currentWord.TabWord[0] == '@' || currentWord.TabWord[currentWord.Length - 1] == '@')
    {
        return false;
    }

    int sum = 0;
    for (int i = 0; i < currentWord.Length; i++){
        if (currentWord.TabWord[i] == '@' && currentWord.TabWord[i + 1] == '@'){
            return false;
        }
        
        if (currentWord.TabWord[i] != '@'){
            sum *= 10;
            sum += currentWord.TabWord[i] - '0';
        }

        if (currentWord.TabWord[i] == '@' || i == currentWord.Length - 1){
            if (sum<0 || sum>255){
                return false;
            }
            sum = 0;
        }

        if (currentWord.TabWord[i] == '@' && currentWord.TabWord[i + 1] == '0' && i < currentWord.Length - 2){
            if (currentWord.TabWord[i + 2] != '@'){
                return false;
            }
        }
    }
    return true;
}
int main(){
    STARTWORD();
    
    while (!EndWord){
        if (isIPv4Lay()){
            printf("4Lay");
        } else {
            printf("ewh");
        }
        ADVWORD();
        if (!EndWord)
        {
            printf(" ");
        }
    }

    printf("\n");
    return 0;
}
#include <stdio.h>
#include "boolean.h"
#include "mesinkata.h"

boolean compareString (Word word1, Word word2) {
  int i;
  if (word1.Length != word2.Length) {
    return false;
  }

  for (i = 0; i < word1.Length; i++) {
    if(word1.TabWord[i] != word2.TabWord[i])  {
        return false;
      }
  }

  return true;
}

Word stringToWord (char str[], int len) {
  int i;
  Word ex;

  ex.Length = len;
  for (i = 0; i < len; i++) {
    ex.TabWord[i] = str[i];
  }
  return ex;
}

int main () {
  int i, num;
  boolean space, isNum, printNum;
  Word nol, satu, dua, tiga, empat, lima, enam, tujuh, delapan, sembilan, sepuluh, sebelas, belas, puluh, seratus, ratus, seribu, ribu;
  
  
  STARTWORD();
    char cnol[50] = "nol";
    nol = stringToWord(cnol, 3);

    char csatu[50] = "satu";
    satu = stringToWord(csatu, 4);

    char cdua[50] = "dua";
    dua = stringToWord(cdua, 3);

    char ctiga[50] = "tiga";
    tiga = stringToWord(ctiga, 4);

    char cempat[50] = "empat";
    empat = stringToWord(cempat, 5);

    char clima[50] = "lima";
    lima = stringToWord(clima, 4);

    char cenam[50] = "enam";
    enam = stringToWord(cenam, 4);

    char ctujuh[50] = "tujuh";
    tujuh = stringToWord(ctujuh, 5);

    char cdelapan[50] = "delapan";
    delapan = stringToWord(cdelapan, 7);

    char csembilan[50] = "sembilan";
    sembilan = stringToWord(csembilan, 8);

    char csepuluh[50] = "sepuluh";
    sepuluh = stringToWord(csepuluh, 7);

    char csebelas[50] = "sebelas";
    sebelas = stringToWord(csebelas, 7);

    char cbelas[50] = "belas";
    belas = stringToWord(cbelas, 5);

    char cpuluh[50] = "puluh";
    puluh = stringToWord(cpuluh, 5);

    char cseratus[50] = "seratus";
    seratus = stringToWord(cseratus, 7);

    char cratus[50] = "ratus";
    ratus = stringToWord(cratus, 5);

    num = -1;
    while (!EndWord) {
        isNum = false;
        printNum = false;

        if (compareString(nol, currentWord)) {
           if (num == -1)
            {
                num = 0;
            }
            num += 0;
            isNum = true;
        }
        else if (compareString(satu, currentWord)) {
            if (num == -1)
            {
                num = 0;
            }
            num += 1;
            isNum = true;
        }
        else if (compareString(dua, currentWord)) {
            if (num == -1)
            {
                num = 0;
            }
            num += 2;
            isNum = true;
        }
        else if (compareString(tiga, currentWord)) {
            if (num == -1)
            {
                num = 0;
            }
            num += 3;
            isNum = true;
        }
        else if (compareString(empat, currentWord)) {
            if (num == -1)
            {
                num = 0;
            }
            num += 4;
            isNum = true;
        }
        else if (compareString(lima, currentWord)) {
            if (num == -1)
            {
                num = 0;
            }
            num += 5;
            isNum = true;
        }
        else if (compareString(enam, currentWord)) {
            if (num == -1)
            {
                num = 0;
            }
            num += 6;
            isNum = true;
        }
        else if (compareString(tujuh, currentWord)) {
            if (num == -1)
            {
                num = 0;
            }
            num += 7;
            isNum = true;
        }
        else if (compareString(delapan, currentWord)) {
            if (num == -1)
            {
                num = 0;
            }
            num += 8;
            isNum = true;
        }
        else if (compareString(sembilan, currentWord)) {
            if (num == -1)
            {
                num = 0;
            }
            num += 9;
            isNum = true;
        }
        else if (compareString(sepuluh, currentWord)) {
            if (num == -1)
            {
                num = 0;
            }
            num += 10;
            isNum = true;
        }
        else if (compareString(sebelas, currentWord)) {
            if (num == -1)
            {
                num = 0;
            }
            num += 11;
            isNum = true;
        }
        else if (compareString(belas, currentWord)) {
            if (num == -1)
            {
                num = 0;
            }
            num += 10;
            isNum = true;
        }
        else if (compareString(puluh, currentWord)) {
            num += (10 * (num % 10)) - (num % 10);
            isNum = true;
        }
        else if (compareString(seratus, currentWord)) {
            if (num == -1)
            {
                num = 0;
            }
            num += 100;
            isNum = true;
        }
        else if (compareString(ratus, currentWord)) {
            num += (100 * (num % 100)) - (num % 100);
            isNum = true;
        }
        else {
            printNum = true;
        }

        if (printNum && num >= 0) {
            if (space)
            {
                printf(" ");
            }
            printf("%d", num);
            space = true;
            num = -1;
        }

        if (!isNum) {
            if (space)
            {
                printf(" ");
            }

            for (i = 0; i < currentWord.Length; i++)
            {
                printf("%c", currentWord.TabWord[i]);
            }

            space = true;
        }

        ADVWORD();
    }

    if (num >= 0) {
        if (space)
        {
            printf(" ");
        }
        printf("%d", num);
        space = true;
    }

    printf("\n");

    return 0;

}
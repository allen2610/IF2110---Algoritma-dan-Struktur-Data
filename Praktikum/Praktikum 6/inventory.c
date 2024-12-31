#include <stdio.h>
#include "boolean.h"
#include "stack.h"

int main() {
    /*KAMUS*/
    int N, i, total = 0, temp1, temp2, sum;
    char c;
    Stack s;

    /*ALGORITMA*/
    CreateEmpty(&s);
    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        scanf(" %c", &c);

        if (c == '+'){
            sum = 0;
            Pop(&s, &temp1);
            Pop(&s, &temp2);
            sum = temp1 + temp2;
            Push(&s, temp2);
            Push(&s, temp1);
            Push(&s, sum);
            
        } else if (c == 'A') {
            sum = 0;
            int ctr = 0, avg;
            while (!IsEmpty(s)) {
                Pop(&s, &temp1);
                sum += temp1;
                ctr++;
            }

            if (ctr == 0) {
                avg = 0;
            } else {
                avg = sum / ctr;
            }

            Push(&s, avg);

        } else if (c == 'S'){
            sum = 0;
            while (!IsEmpty(s))
            {
                Pop(&s, &temp1);
                sum += temp1;
            }
            Push(&s, sum);

        } else if (c == 'X'){
            Pop(&s, &temp1);

        } else {
            Push(&s, (c - '0'));
        }
    }

    while (!IsEmpty(s))
    {
        Pop(&s, &temp1);
        total += temp1;
    }
    printf("%d\n", total);

    return 0;
}
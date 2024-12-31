#include <stdio.h>
#include "stack.c"

int main() {
    /*KAMUS*/
    int N, i;
    char c;
    char temp;
    Stack S;
    boolean valid = true;

    /*ALGORITMA*/
    CreateEmpty(&S);
    scanf("%d", &N);

    if (N > 1) {
        for (i = 0; i < N; i++) {
            scanf(" %c", &c);

            if (c == '(' || c == '{' || c == '[')
            {
                Push(&S, c);
            } else {
                if (c == ')') {
                    if (IsEmpty(S) || InfoTop(S) != '(') {
                        valid = false;
                        break;
                    }
                    else {
                        Pop(&S, &temp);
                    }
                }

                if (c == ']') {
                    if (IsEmpty(S) || InfoTop(S) != '[') {
                        valid = false;
                        break;
                    } else {
                        Pop(&S, &temp);
                    }
                }

                if (c == '}') {
                    if (IsEmpty(S) || InfoTop(S) != '{') {
                        valid = false;
                        break;
                    } else {
                        Pop(&S, &temp);
                    }
                }
            }
        }

        if (!IsEmpty(S)){
            valid = false;
        }
    }
    else
    {
        valid = false;
    }

    if (valid) {
        printf("Valid\n");
    } else {
        printf("Invalid\n");
    }

    return 0;
}

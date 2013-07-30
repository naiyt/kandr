/* Excercise 1-12
   "Write a program that prints its input one word per line."*/

#include <stdio.h>

#define IN  1
#define OUT 0

main() {
    int c, state;
    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            printf("\n");
        }
        // Don't print the extra spaces on newlines
        else if (c != ' ') {
            putchar(c);
        }
    }
}

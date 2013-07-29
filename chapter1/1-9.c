/* Excercise 1-9
   "Write a program to copy its input to its ouptut, replacing each string
   of one or more blanks by a single blank." */

#include <stdio.h>

main() {
    int c;
    int save = '1'; // Just defaulting to something that isn't a space

    while ((c = getchar()) != EOF) {
        if (c == ' ' && save != ' ') {
            putchar(c);
        }
        else if (c != ' ') {
            putchar(c);
        }
        save = c;
    }
}

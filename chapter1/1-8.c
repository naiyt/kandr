/* Excercise 1-8
   "Write a program to count blanks, tabs, and newlines */

#include <stdio.h>

main() {
    int c, blanks, tabs, nl;
    blanks = tabs = nl = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++blanks;
        else if (c == '\t')
            ++tabs;
        else if (c == '\n')
            ++nl;
    }
    printf("Blanks: %d Tabs: %d Spaces: %d\n", blanks, tabs, nl);
}

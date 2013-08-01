/* Excercise 1-13
    
   "Write a program to print a histogram of the frequencies of different characters in its input."*/

#include <stdio.h>

main() {
    int c, i;
    int nl, tabs, spaces, other;
    int numWords = 4;
    nl = tabs = spaces = other = 0;

    while((c = getchar()) != EOF) {
        if(c == '\n')
            ++nl;
        else if(c == '\t')
            ++tabs;
        else if(c == ' ')
            ++spaces;
        else
            ++other; 
    }
    
    // Much cleaner if this was in a seperate function; alas, no functions yet.
    printf("NL    : ");
    for(i = 0; i < nl; i++)
        printf("#");

    printf("\nSpaces: ");
    for(i = 0; i < spaces; i++)
        printf("#");

    printf("\nTabs  : ");
    for(i = 0; i < tabs; i++)
        printf("#");

    printf("\nOther : ");
    for(i = 0; i < other; i++)
        printf("#");

    printf("\n");
}

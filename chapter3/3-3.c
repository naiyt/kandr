/* Excercise 3-3

   Write a fucntion expand(s1,s2) that expands shorthand notations like a-z
   in the string s1 into the equivalent complete list abc...xyz in s2. Allow
   for letters of either case and digits, and be prepared to handle cases
   like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing -
   is taken literally. */

#include <stdio.h>
#include <string.h>
#define MAXARRAY 256

// Doesn't handle all cases quite yet, but it works generally speaking
void expand(char s1[], char s2[]) {
    int i;
    int j = 0;

    for(i = 0; isspace(s1[i]); i++)
        ;

    if(s1[i] == '-') {
        s2[j] = '-';
        j++;
        i++;
    }
    
    while(s1[i] != '\0') {
        char firstChar = s1[i];
        if (s1[i+1] != '-') {
            s2[0] = '\0';
            return;
        }
        char secondChar = s1[i+2];
        for(; firstChar <= secondChar; firstChar++) {
            s2[j] = firstChar;
            j++;
        }

        i += 3;       
    }
    s2[j] = '\0';
}


main() {
    char s1[MAXARRAY];
    char s2[MAXARRAY];
    int c;
    int i = 0;
    for(i = 0; (c=getchar()) != EOF; i++) {
        if(c == '\n') {
            s1[i] = '\0';
            expand(s1, s2);
            printf("Expanded: %s\n", s2);
            i = -1;
            s1[0] = '\0';
        }
        else {
            s1[i] = c;
        }
    }
    return 0;
}

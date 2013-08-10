/* Excercies 2-5

   Write the function any(s1, s2) which returns the first location in a string s1
   where any character from the string s2 occurs, or -1 if s1 contains no characters
   from s2. (The standard library function strpbrk does the same job but returns
   a pointer to the location.) */


#include <stdio.h>
#include <stdbool.h>
#define MAX 100

// Any just iterates through the two character arrays,
// and passes each character and s1 to printLoc,
// which prints the first location of that character.
int findLoc(char s[], int c) {
    int i;
    for(i = 0; s[i] != '\0' && s[i] != '\n'; i++) {
        if(s[i] == c) {
            return i;
        }
    }
    return -1;
}

int any(char s1[], char s2[]) {
    int i, j;
    int loc = -1;
    for(i = 0; s2[i] != '\0'; i++) {
        loc = findLoc(s1, s2[i]);
        if(loc != -1)
            return loc;
    }
    return loc;
    
}


main() {
    char s1[MAX];
    char s2[MAX];
    
    printf("First string: ");
    fgets(s1, MAX, stdin);
    printf("Second string: ");
    fgets(s2, MAX, stdin);

    int loc = any(s1, s2);
    printf("First location of a character in string 2 in string 1: %d\n", loc);

    return 0;
}

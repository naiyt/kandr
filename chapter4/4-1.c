/* Excercies 4-1

   Write the function strindex(s,t) which returns the position of the
   rightmost occurence of t in s, or -1 if there is none. */


#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int mygetline(char line[], int max);
int strindex(char source[], char searchFor[]);

int main() {
    char pattern[] = "ould";
    char line[MAXLINE];
    int found = 0;
    int location = 0;

    while(mygetline(line, MAXLINE) > 0) {
        location = strindex(line, pattern);
        if(location >= 0) {
            printf("The rightmost position of %s is %i\n", pattern, location);
            found++;
        }
        else {
            printf("%s not found\n", pattern);
        }
    }

    return found;
}

int mygetline(char s[], int lim) {
    int c, i;
    
    i = 0;
    while(--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if(c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

int strindex(char source[], char searchFor[]) {
    int i, j, k;
    int searchLen = strlen(searchFor);
    int sourceLen = strlen(source);
    /* Start from the end of source; check each char to see if it
      matches the corresponding char in searchFor; if k reaches -1,
      then we matched every character in searchFor, and can return
      the result. */
    for(i = sourceLen - 1; source[i] >= 0; i--) {
        for(j=i, k=searchLen-1; k>=0 && source[j]==searchFor[k]; j--, k--)
            ;
        // We've moved i one to far at this point, so move it back,
        // then return the position of i minus the length of our search
        // phrase to get the position counting from the left.
        if(k == -1)
            i++;
            return i - searchLen;
    }
    return -1;
}

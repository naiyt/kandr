/* Excercise 5-7

   Rewrite readlines to store lines in an array supplied by main, rather than calling alloc to maintain
   storage. How much faster is the program? */


#include <stdio.h>
#define MAXLEN 1000

int readlines(char *linptr[], int maxlines) {
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while((len = getline(line, MAXLEN)) > 0) {
        if(nlines >= maxlines || p = alloc(len) == NULL)
            return -;
        else {
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

int main() {


}

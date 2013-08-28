/* Excercise 5-6

   Rewrite appropriate programs from earlier chapters and excercises with
   pointers instead of array indexing. Good possibilities include getline,
   atoi, itoa, and their variants, reverse, and strindex and getop. */

#include <stdio.h>

int mygetline(char *s, int lim) {
    
    int c, i;
    
    for(i=0; i < lim-1 && (c=getchar()) != EOF && c!= '\n'; ++i)
        *(s+i) = c;
    if(c == '\n') {
        *(s+i) = c;
        ++i;
    }
    *(s+i) = '\0';

    return i;
}

int main() {
    char test[100];
    
    while((mygetline(test, 100)) != 0)
        printf("%s", test);
    return 0;
}

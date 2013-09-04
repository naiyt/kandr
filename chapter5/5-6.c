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

void itoa(int n, char *s) {
    static int i = 0;

    if(n < 0) {
        *(s) = '-';
    }

    if (n / 10) {
        itoa(n / 10, s);
    }

    char num = n % 10 + '0';
    *(s+i) = num;
    ++i;
    *(s+i) = '\0';

}


int atoi(char *s) {
    int i, n;
    n = 0;

    for(i = 0; *(s+i) >= '0' && *(s+i) <= '9'; ++i)
        n = 10 * n + (*(s+i) - '0');

    return n;
}

void reverse(char *s, int len) {
    char reversed[len+1];
    int i, j;
    j = 0;

    reversed[len] = '\n';
    for (i = len - 1; i >= 0; --i, ++j) {
        reveresed[j] = *(s+i);
    }

    for(i = 0; i <= len; i++) {
        *(s+i) = reversed[i];
    }

    *(s+(len+1)) = '\0';
}

int strindex(char *source, char *searchFor) {
    int i, j, k;
    int searchLen = strlen(searchFor);
    int sourceLen = strlen(source);

    for(i = sourceLen - 1; *(source+i) >= 0; i--) {
        for(j = i, k=searchLen-1; k>=0 && *(source+j) == *(searchFor+k); j--, k--)
            ;

        if(k == -1) {
            i++;
            return i - searchLen;
        }

    }
    return -1;
}

int getop(char *s) {
    int i, c;
    while((*(s) = c = getch()) == ' ' || c == '\t')
        ;
    *(s+1) = '\0';

    i = 0;

    if(c == '-') {
        *(s+i++) = c;
        *(s+i) = c = getch();
    }

    if(!isdigit(c) && c != '.')
        return c;

    if (isdigit(c))
        while(isdigit(*(s+i++) = c = getch()));

    if(c == '.')
        while(isdigit(*(s+i++) = c = getch()))
            ;

    *(s+i) = '\0';

    if(c != EOF)
        ungetch(c);
    return NUMBER;

}




int main() {
    char test[100];
    
    //while((mygetline(test, 100)) != 0)
    //    printf("%s\n", test);

    char test2[100];
    itoa(123123, test2);
    printf("%s\n", test2);

    int num = atoi("1233");
    printf("%d\n", num);

    return 0;
}

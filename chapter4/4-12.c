/* Excercise 4-12

   Adapt the ideas of printd to write a recursive version of itoa;
   this is, convert an integer into a string by calling a recursive
   routine. */

#include <stdio.h>
#define MAXARRAY 100

void itoa(int n, char s[]) {
    static int i = 0;
    if(n < 0) {
        s[0] = '-';
        i = 1;
    }
    if(n / 10) {
        itoa(n / 10, s);
    }
    char num = n % 10 + '0';
    s[i] = num;
    s[++i] = '\0';
}

int main() {
    char s[MAXARRAY];
    itoa(1232152, s);
    printf("%s\n", s);

    return 0;
}

/* Write the function strend(s, t) which returns 1 if the string t occurs
   at the end of the string s, and zero otherwise. */

#include <stdio.h>
#include <string.h>
#define MAX 100

// Borked
int strend(char *s, char *t) {
    
    *s = *s + (*s - *t);

    while(*s) {
        printf("%c == %c\n", *s, *t);
        if(*s++ != *t++)
            return 0;
    }

    return 1;

}

int main() {

    char s1[MAX];
    char s2[MAX];

    printf("Enter first string: ");
    fgets(s1, MAX, stdin);
    printf("Enter second string: ");
    fgets(s2, MAX, stdin);

    int ends = strend(s1, s2);
    switch(ends) {
        case 1:
            printf("String 2 exists at the end of string 1\n");
            break;
        case 0:
            printf("String 2 does not exist at the end of string 1\n");
            break;
    }

    return 0;
}

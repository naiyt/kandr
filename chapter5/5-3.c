/* Excercise 5-3

   Write a pointer version of the function strcat that we showed in Chapter 2:
   strcat(s, t) copies the string t to to the end of s */

#include <stdio.h>
#define MAX 100

void mystrcat(char *s, char *t) {
    // Get to the end of s
    while(*s++) {
        if(*s == '\n') {
            break;
        }
    }

    while(*t != '\0') {
        if(*t != '\n')
            *s++ = *t;
        *t++;
    }
    *s = '\0';
}

int main() {
    char s1[MAX];
    char s2[MAX];

    printf("Enter first string: ");
    fgets(s1, MAX, stdin);
    printf("Enter second string: ");
    fgets(s2, MAX, stdin);

    mystrcat(s1, s2);
    printf("Concatenated: %s\n", s1);

}

/* Excercise 3-2

   Wirte a function escape(s, t) that converts character like newline
   and tab into visible escape sequences like \n and \t as it copies
   the string t to s. Use a switch. Write a function for the other direction
   as well, converting escape sequences into real characters. */

#include <stdio.h>
#include <string.h>
#define MAXLINE 100

void unescape(char s[], char t[], int tabSize) {
    int i, c;
    int j = 0;
    for(i = 0`

}

void escape(char s[], char t[]) {
    int i, c;
    int j = 0;
    for(i = 0; t[i] != '\0'; i++) {
        switch (t[i]) {
            case '\n':
                s[j] = '\\';
                s[j+1] = 'n';
                j += 2;
                break;
            case '\t':
                s[j] = '\\';
                s[j+1] = 't';
                j += 2;
                break;
            default:
                s[j] = t[i];
                ++j;
                break;
        }
    }  
    s[j+1] = '\0';
}

main() {
    char line1[MAXLINE];
    char line2[MAXLINE];
    int i, c;
    for(i = 0; (c = getchar()) != EOF; i++) {
        line1[i] = c;
    }
    line1[i+1] = '\0';
    escape(line2, line1);
    printf("Escaped: %s\n", line2); 
    return 0;
}

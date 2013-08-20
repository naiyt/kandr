/* Excercise 4-13

   Write a recursive version of the function reverse(s), which reverses
   the string s in place. */

#include <stdio.h>
#include <string.h>

// I need the positions we're swapping in this version,
// so I find that in the main reverse() function and then
// pass it here
void reverse_inplace(char s[], int start, int end) {
    char temp = s[start];
    s[start] = s[end];
    s[end] = temp;
    if(start < end)
        reverse_inplace(s, ++start, --end);
}

void reverse(char s[]) {
    int length = strlen(s) - 1;
    reverse_inplace(s, 0, length);
}

int main() {
    int charlen = 100;
    char s[charlen];
    while(1) {
        fgets(s, charlen, stdin);
        reverse(s);
        printf("%s\n", s);
    }
    return 0;
}

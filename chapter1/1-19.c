/* Excercise 1-19

   Write a function reverse(s) that reverses the character string s.
   Use it to write a program that reverses its input a line
   at a time. */

#include <stdio.h>
#include <stdbool.h>
#define MAXLINE 1000

// We haven't really learned about pointers by this point in the book,
// so the easiest way I found to do this is to get the reverse
// of the intial char array, then copy it back to the initial.
void reverse(char s[], int len) {
	char reversed[len+1];
	int i, j;
	j = 0;

	reversed[len] = '\n';
	for(i = len - 1; i >= 0; --i, ++j) {
		reversed[j] = s[i];
	}
	
	for(i = 0; i <= len; i++) {
		s[i] = reversed[i];
	}
	s[len+1] = '\0';
}

int mygetline(char line[], int maxline) {
	int c, i;
	for(i = 0; i < MAXLINE -1 && (c = getchar()) != EOF && c != '\n'; ++i) {        	line[i] = c;
    }
	if(i == 0 && c == '\n')
		i++;
	return i;
}

main() {
	char line[MAXLINE];
	int len;
	while((len = mygetline(line, MAXLINE)) > 0) {
		reverse(line, len);
		printf("%s", line);
	}	

	return 0;
}

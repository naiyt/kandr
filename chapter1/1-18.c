/* Excercise 1-18

   Write a program to remove trailing blanks and tabs from each line of
   input, and to delete entirely blank lines */

#include <stdio.h>
#include <stdbool.h>
#define MAXLINE 1000

// Iterates through the char array backwards, and moves
// the \0 back until we meet something other than a space
// or a tab.
void stripLine(char line[], int len) {
	int i;
	for(i = len - 1; i >= 0 && (line[i] == ' ' || line[i] == '\t'); --i) {
		line[i] = '\n';
		line[i+1] = '\0';
	}
}

bool mygetline(int maxline) {
	char line[maxline];
	int c, i;
	for(i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		line[i] = c;
	}	

	line[i] = '\n';
	line[i+1] = '\0';
	
	stripLine(line, i);
	printf("%s", line);

	if(c == EOF)
		return false;
	else
		return true;

}

main() {

	while(mygetline(MAXLINE)) {
		;
	}
}

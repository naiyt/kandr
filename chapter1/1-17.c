/* Excercise 1-7

   Write a program to print all lines that are longer than 80 characters.*/

#include <stdio.h>
#define MAXLINE 1000

int mygetline(char line[], int maxline);

main() {
	int len;
	char line[MAXLINE];

	while((len = mygetline(line, MAXLINE)) > 0) {
		if(len > 80) {
			printf("%d Long:\n", len);
			printf("%s", line);
		}
	}
	return 0;
}

int mygetline(char line[], int maxline) {
	int c, i;
	for(i=0; i < maxline-1 && (c = getchar()) != EOF && c!= '\n'; ++i) {
		line[i] = c;
	}
	if(c=='\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}

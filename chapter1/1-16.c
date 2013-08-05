/* Excercise 1-16

   "Revise the main routine of the longest-line program so it will correctly print the length of arbitrary long
   input lines, and as mush as possible of the text." */

/* I'm not entirely clear on what he wants here. I'm assuming he just wants to 
   print the length of the line and the text after each entered line, and to
   only modify this in main(). */

#include <stdio.h>
#define MAXLINE 1000

int mygetline(char line[], int maxline);
void copy(char to[], char from[]);

main() {
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while((len = mygetline(line, MAXLINE)) > 0) {
		// Subtract one so we don't count the newline
		printf("Length: %d\n", len-1);
		printf("String: %s", line);
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}

	if (max > 0)
		printf("%s", longest);
	return 0;
}

int mygetline(char s[], int lim) {
	int c, i;

	for(i=0; i < lim - 1 && (c = getchar()) != EOF && c!='\n'; ++i) {
		s[i] = c;
	}
	if (c=='\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void copy(char to[], char from[]) {
	int i = 0;
	while((to[i] = from[i]) != '\0') {
		++i;
	}
}

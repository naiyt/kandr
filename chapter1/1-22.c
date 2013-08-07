/* Excercise 1-22

   Write a program to "fold" long input lines into two or more
   shorter lines after the last non-blank character that occurs before
   the n-th column of input. Make sure you program does something
   intelligent with very long lines, and if there are no blanks or tabs
   before the specified column. */

// Just keep track of how many characters we have on a line, and
// outpute a \n if we reach the max lenght. The instructions
// do not state anything about breaking on words.

#include <stdio.h>

void fold(int max) {
	int c, count;
	count = 1;

	while((c = getchar()) != EOF) {
		if(c == '\n') {
			count = 0;
		}
		if(count > max) {
			putchar('\n');
			count = 0;
		}
		putchar(c);
		count++;
	}
}


main() {
	int length = 10;
	fold(length);
}

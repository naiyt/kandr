/* Excercise 1-23

   Write a program to remove all comments from a C program.
   Don't forget to handle quoted strings and character constants
   properly. Comments don't nest.*/

// This should handle both multiline and single line.
// Putting random comments through this file, so that
// the program can be tested on its own source.

#include <stdio.h>
#include <stdbool.h>

// Hi, I'm a single line comment.
void removeComments(void) {
	bool inSingle = false;
	bool inMulti= false;
	int c, prev;
	prev = 0;

	/* Multiline comment
	   for the epic win. */

	while((c = getchar()) != EOF) {
		if(prev == '/' && c == '*' && !inSingle && !inMulti) {
			inMulti = true;
		}
		else if(prev == '/' && c == '/' && !inSingle && !inMulti) {
			inSingle = true;
		}

		if(!inMulti && !inSingle && c != '/') {
			putchar(c);
		}

		if(inMulti) {
			if(prev == '*' && c == '/') {
				inMulti = false;
			}
		}

		else if(inSingle) {
			if(c == '\n') {
				inSingle = false;
			}

		}
		prev = c;
	}

}

// This is a main method. Its name is main.
// It is fairly mainstream.
main() {
	/* Will you remove these silly comments for me, please?
	   They are quite awful. */
	removeComments();

	return 0;
}

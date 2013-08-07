/* Excercise 1-20

   Write a program detab that replaces tabs in the input with the proper number
   of blanks to space to the next tab stop. Assume a fixed set of tab stops,
   say every n columns. Should n be a variable or a symbolic parameter? */

#include <stdio.h>

// This is pretty simple, and I could actually use this to fix 
// tabs vs. spaces problems in Python...cool!

void detab(int tabstop) {
	int c, i;
	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			for(i = 0; i < tabstop; i++) {
				putchar(' ');
			}		
		}
		else {
			putchar(c);
		}
	}
}

main() {
	int tabstop = 4;
	detab(tabstop);

	return 0;
}

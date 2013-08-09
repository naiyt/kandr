/* Excercise 2-2

   Write a loop equivalent to the for loop above without using
   && or || */

/* The for loop in question was:
   for(i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
   		s[i] = c;
*/

#include <stdio.h>
#include <stdbool.h>

// I don't know why I would ever replace that two line for loop
// with this monster, but I shall do as the book says.
main() {
	int lim = 1000;
	int i = 0;
	int c;
	char s[lim];

	while(true) {
		if(i >= lim-1) {
			break;
		}
		if ((c = getchar()) == '\n') {
			break;
		}
		if (c == EOF) {
			break;
		}
		s[i] = c;
		++i;
	}

	return 0;
}

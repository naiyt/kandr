/* Excercise 1-21

   Write a program entab that replaces strings of blanks by the minimum
   number of tabs and blanks to achieve the same spacing. Use the same tab
   stops as for detab. When either a tab or a single blank would suffice
   to reach a tab stop, which should be given preference? */

#include <stdio.h>
#include <stdbool.h>

void entab(int tabstop) {
	int c, i;
	int num = 0;
	bool on_spaces = false;
	while((c = getchar()) != EOF) {

		// Don't convert if the tabstop is 1; otherwise
		// all spaces would be converted to tabs!		
		if(tabstop == 1) {
			putchar(c);
		}
		
		else {
			if(c == ' ') {
				++num;
				on_spaces = true;
			}
			else {
				if(on_spaces && tabstop != 1) {
					on_spaces = false;
					int tabs = num / tabstop;
					int spaces = num % tabstop;
					num = 0;

					//printf("Printing %d tabs\n", tabs);
					//printf("Printing %d spaces\n", spaces);

					for(i = 0; i < tabs; i++) {
						//printf("TAB");
						putchar('\t');
					}
					for(i = 0; i < spaces; i++) {
						//printf("SPACE");
						putchar(' ');
					}
				}
				putchar(c);
			}
		}
	}
}


main() {
	int tabstop = 4;
	entab(tabstop);

	return 0;
}

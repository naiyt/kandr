/* Excercise 1-2

   "Experiment to find out what happens when print's argument string contains \c, where c
   is some character not listed above." */

#include <stdio.h>

main() {
    /* gcc gives me this error:
       "1-2.c: In function ‘main’:
       1-2.c:9:12: warning: unknown escape sequence: '\z' [enabled by default]"
       I hope you're happy. */
    printf("Break all the things! \z");
}

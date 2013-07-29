/* Excercise 1-6
   "Verify that the expression getchar() != EOF is 0 or 1 */

#include <stdio.h>

main() {
    // Val is set to 1 as long as getchar() is not EOF
    int val = getchar() != EOF;
    printf("%d", val);
}

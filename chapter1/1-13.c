// NOT finished

/* Excercise 1-13

   "Write a program to print a h istogram of the lengths of words in its input. It is easy to
   draw the histogram with bars horizontal; a vertical orientation is more challenging."*/

#include <stdio.h>

#define MAXLENGTH 20
#define IN  1
#define OUT 0

// We still haven't learned functions by this point in K&R, so no using them. Yay.
// However, we  haven't learned arrays, but I don't know of a simple way to allow
// a lot of variations with word lengths without some really long ugly code.
// Also: definitely horizontally. I don't dare do vertical.
main() {
    int c, i, j;
    int currentCount = 0;
    int state = OUT;

    int wordArray[MAXLENGTH + 1];
    for(i = 0; i < MAXLENGTH + 1; i++) {
        wordArray[i] = 0;
    }


    while((c = getchar() != EOF)) {
       if(state == OUT && currentCount != 0) {
            wordArray[currentCount] += 1;       
       }
       if(c == ' ' || c == '\n' || c == '\t') {
            if(state == IN) {
                state = OUT; 
            }
       }
       else {
            if (state == OUT) {
                state = IN;
            }
            currentCount += 1;
       }

    }

    for(i = 0; i < MAXLENGTH + 1; i++) {
        printf("%d - ", i);

        for(j = wordArray[i]; j > 0; j--) {
            printf("*");
        }
        printf("\n");
    } 

}

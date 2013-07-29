/* Excercise 1-3
   "Modify the temperature conversion program to print a
   heading above the table."*/

#include <stdio.h>

main() {
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    
    // This is the best way to do this, from what we've learned so
    // far in the book, I think. 
    printf("  F\t     C\n");
    while(fahr <= upper) {
        celsius = 5.0 * (fahr - 32.0) / 9.0;
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}

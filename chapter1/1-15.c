/* Excercise 1-15

    "Rewrite the temperature conversion program of Section 1.2 to use
    a function for conversion" */

#include <stdio.h>

float f_to_c(int fahr) {
    return 5.0 * (fahr - 32.0) / 9.0;
}

float c_to_f(int cels) {
    return 32 + (cels * 1.8);
}

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
        celsius = f_to_c(fahr);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}

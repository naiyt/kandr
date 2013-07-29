/* Excercise 1-4
   "Write a program to print the correspoinding Celsius to Fahrenheit table"*/

#include <stdio.h>

main() {
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    celsius = lower;
    
    printf("  C\t     F\n");
    while(celsius <= upper) {
        // Fahrenheit = Celsius * 1.8 + 32
        fahr = 1.8 * celsius + 32;
        printf("%3.0f\t%6.1f\n", celsius, fahr);
        celsius += step;
    }
}

/* Excercise 2-1

   Write a program to determine the ranges of char, short, int, and long
   variables, both signed and unsigned, by printing appropriate values
   from standard headers and by direct computation. Harder if you compute
   them: determine the ranges of various floating-point types. */

#include <stdio.h>
#include <limits.h>
#include <float.h>

// TODO: Compute them, and add floating point types.
main() {
	printf("Char min: %d\n", CHAR_MIN);
	printf("Char max: %d\n", CHAR_MAX);
	printf("Short min: %d\n", SHRT_MIN);
	printf("Short max: %d\n", SHRT_MAX);
	printf("Int min: %d\n", INT_MIN);
	printf("Int max: %d\n", INT_MAX);
	printf("Long min: %d\n", LONG_MIN);
	printf("Long max: %d\n", LONG_MAX);

	return 0;
}

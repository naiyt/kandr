/* Excercise 4-2

   Extend atof to handle scientific notation of the form:

   123.45e-6 */



#include <stdio.h>
#include <math.h>
#define MAXLENGTH 100

// This would be nicer if I moved the conversion from a
// char to an int to another function
double atof(char num[]) {
    double val, power, exponent;
    int i, sign;

    for(i = 0; isspace(num[i]); i++)
        ;

    sign = (num[i] == '-') ? -1 : 1;
    if(num[i] == '+' || num[i] == '-')
        i++;
    for(val = 0.0; isdigit(num[i]); i++)
        val = 10.0 * val + (num[i] - '0');
    if(num[i] == '.')
        i++;
    for(power = 1.0; isdigit(num[i]); i++) {
        val = 10.0 * val + (num[i] - '0');
        power *= 10;
    }
    
    val = sign * val / power;

    // check for scientific notation at this point
    if(num[i] == 'E' || num[i] == 'e') {
        i++;
        sign = (num[i] == '-') ? -1 : 1;
        if(num[i] == '+' || num[i] == '-')
            i++;
        for(exponent = 0.0; isdigit(num[i]); i++) {
            exponent = 10.0 * exponent + (num[i] - '0');
        }
        val = pow(val, sign*exponent);
    }

    return val;


}

int mygetline(char s[], int lim) {
    int c, i;

    i = 0;
    while(--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if(c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

int main() {
    char num[MAXLENGTH];
    double answer;

    while(mygetline(num, MAXLENGTH) > 0) {
        answer = atof(num);
        printf("%f\n", answer);
    } 

    return 0;
}




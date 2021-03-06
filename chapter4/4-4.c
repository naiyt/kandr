/* Excercise 4-4
    
   Add the commands to print the top elements of the stack without popping, to duplicate it,
   and to swap the top two elements. Add a command to clear the stack.

   */

#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);
void peek(void); // Prints the top to elements
void swap(void); // Swaps the top two elements
void clear(void); // Clears the stack

/* reverse Polish calculator */
main()
{
    int type;
    double op2;
    char s[MAXOP];
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%': // Modulus added! Easy peasy
                op2 = pop();
                push(pop() - op2);
                break;
            case 'p': // The user wants to peek
                peek();
                break;
            case 's':
                swap();
                break;
            case 'c':
                clear();
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

#define MAXVAL 100 /* maximum depth of val stack */
int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void peek(void) {
    if(sp > 0) {
        printf("Top: %f, Second to top: %f", val[sp-1], val[sp-2]);
    }
    else {
        printf("Error: empty stack\n");
    }

}

void swap(void) {
    if(sp > 0) {
        int temp = val[sp-1];
        val[sp-1] = val[sp-2];
        val[sp-2] = temp;
    }
    else {
       printf("Error: empty stack\n");
    }

}

void clear(void) {
    int i;
    for(i = 0; i < sp; i++) {
        val[i] = 0.0;
    }

}


int getch(void);
void ungetch(int);

/* getop: get next character or numeric operand */
int getop(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
  
    i = 0;
    // These lines add negative number support
    if(c == '-') {
        s[i++] = c;
        s[i] = c = getch();
    }

    if (!isdigit(c) && c != '.')
        return c; /* not a number */

    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))

    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    

    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */
int getch(void) /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}


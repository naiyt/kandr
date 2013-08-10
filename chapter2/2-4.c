/* Excercise 2-4

   Write an alternative version of squeeze(s1, s2) that deletes each charater in s1 that
   matches any charater in the string s2. */


#include <stdio.h>
#define MAX 100

// I just iterate through s2, and pass s1 into squeezeChar for each character we encounter

void squeezeChar(char s[], int c) {
    int i, j;

    for (i = j = 0; s[i] != '\0'; i++) {
        if(s[i] != c)
            s[j++] = s[i];
    }
    s[j] = '\0';

}

void squeeze(char s1[], char s2[]) {
    int i;
    for(i = 0; s2[i] != '\0'; i++) {
        squeezeChar(s1, s2[i]);
    }
    
}



main() {
    char s1[MAX];
    char s2[MAX];

    printf("First string: ");
    fgets(s1, MAX, stdin);
    printf("Second string: ");
    fgets(s2, MAX, stdin);
    
    squeeze(s1, s2);
    printf("Squeezed: %s\n", s1);
    
    return 0;
}

/* Excercies 6-2

	Write a program that reads a C program and prints in alphabetical order each group
	of variable names that are identical in ther ifrst 6 characters, but different
	somewhat thereafter. Don't count words within strings and comments. Make 6 
	a parameter that can be set from the command line. */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "utils.c"
#include "tree.c"


#define MAXWORD 100


struct baseNode {
	struct baseNode *left;
	struct baseNode *right;
	char* firstLetters;
	tnode* subtreeRoot;
	int count;
};

struct baseNode *baseAlloc(void) {
	return (struct baseNode *) malloc(sizeof(struct baseNode));
}

char *strfirst(char *s, int num) {
	int i;
	int len = strlen(s);
	if(num > len) {
		num = len;
	}

	char *newStr = (char*) malloc(sizeof(char) * MAXWORD);

	for( i = 0; i < num; i++) {
		newStr[i] = s[i];		
	}
	newStr[++i] = '\0';
	return newStr;

}

struct baseNode *addBase(struct baseNode *p, char *w, int num) {
	int cond;

	char* firstLetters = strfirst(w, num);

	if(p == NULL) {
		p = baseAlloc();
		p->firstLetters = firstLetters;
		p->left = p->right = NULL;
		p->count = 1;
		struct tnode *newRoot = NULL;
		struct tnode *root = addtree(newRoot, w);
		p->subtreeRoot = root;
	}	
	else if((cond = strcmp(firstLetters, p->firstLetters)) == 0) {
		// p->count++;
		addtree(p->subtreeRoot, w);
	}
	else if(cond < 0) {
		p->left = addBase(p->left, w, num);
	}
	else {
		p->right = addBase(p->right, w, num);
	}

	return p;
}

void fullTreePrint(struct baseNode *p) {
	if(p != NULL) {
		printf("Begins with %s :\n", p->firstLetters);
		treeprint(p->subtreeRoot);
		fullTreePrint(p->left);
		fullTreePrint(p->right);
	}
}



int main(int argc, char const *argv[])
{

	int to_comp = 6;
	if(argc > 1) {
		to_comp = atoi(argv[1]);
	}


	struct baseNode *root;
	char word[MAXWORD];

	root = NULL;
	while(getword(word, MAXWORD) != EOF) {
		if(isalpha(word[0])) {
			root = addBase(root, word, to_comp);
		}
	}

	fullTreePrint(root);
	return 0;
}



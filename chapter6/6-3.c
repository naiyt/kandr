/* Excercise 6-3
	Write a corss-refrencer that prints a list of all words in a document, 
	and for each word, a list of the line numbers on which it occurs. Remove
	noise words like "the" "and" and so on.
*/


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "linkedlist.c"
#include "utils.c"

#define MAXWORD 100



struct treeNode {
	char *word;
	struct node *wordList;
	struct treeNode *left;
	struct treeNode *right;
};

struct treeNode *talloc(void) {
	return (struct treeNode *) malloc(sizeof(struct treeNode));
}

char *strdup(char *s) {
	char *p;
	p = (char*) malloc(strlen(s) + 1);
	if(p != NULL)
		strcpy(p, s);
	return p;
}

void treeprint(struct treeNode *p) {
	if(p != NULL) {
		treeprint(p->left);
		printf("Word: %s | Line Numbers: \n", p->word);;
		print_list(p->wordList);
		treeprint(p->right);
	}
}

struct treeNode *addtree(struct treeNode *p, char *w, int count) {
	int cond;

	if(p == NULL) {
		p = talloc();
		p->wordList = nodeAlloc();
		p->wordList->lineNum = count;
		p->wordList->next = NULL;
		p->word = strdup(w);
		p->left = p->right = NULL;
	}
	else if ((cond = strcmp(w, p->word)) == 0) {
		insert(p->wordList, count);
	}
	else if(cond < 0) {
		p->left = addtree(p->left, w, count);
	}
	else {
		p->right = addtree(p->right, w, count);
	}
	return p;

}


int main(int argc, char const *argv[])
{

	struct treeNode *root;
	char word[MAXWORD];

	root = NULL;

	int count = 0;
	while(getword(word, MAXWORD) != EOF) {
		if(isalpha(word[0])) {
			count++;
			root = addtree(root, word, count);
		}
	}

	treeprint(root);
	return 0;
}
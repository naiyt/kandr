#include <stdio.h>
#include <stdlib.h>

struct node {
	node* next;
	int lineNum;
};

struct node *nodeAlloc(void) {
	return (struct node *) malloc(sizeof(struct node));
}


void insert(node* p, int val) {
	node* new_node = nodeAlloc();
	new_node->lineNum = val;
	new_node->next = NULL;

	node* it = p;

	while(it->next != NULL) {
		it = it->next;
	}
	it->next = new_node;
}

void print_list(node* p) {
	node* it = p;

	while(it->next != NULL) {
		printf("%d, ", it->lineNum);
		it = it->next;
	}
	printf("%d\n", it->lineNum);
}



#include <stdio.h>
#include <stdlib.h>

typedef struct _node *link;

typedef struct _node {
	int value;
	link next;
} node;

typedef struct _list {
	link head;
} list;

/* FACTORIAL PROBLEM
 *
 * Create a linked list with factorial of 4
 *
 * 1 x 1 = 1
 * 1 x 2 = 2
 * 1 x 2 x 3 = 6
 * 1 x 2 x 3 x 4 = 24
 * ... and so on
 *
 */

 // X-->1-->2-->6

list factorial(int x) {
	list ls = createList();
	link newNode = NULL;
	int count = 1;
	int fact = 1;
	
	while (counter <= x) {
		fact = fact * counter;
		newNode = createNode(fact);
	}
}

static list createList() {

}

static link createNode(int val) {
	link n = malloc(sizeof(node));
	n->value = val;
	n->next = NULL;
}

static void addToEnd() {

}



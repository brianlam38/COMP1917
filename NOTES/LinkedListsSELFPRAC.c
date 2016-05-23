#include <stdio.h>
#include <stdlib.h>

typedef struct _node *nodePointer

typedef struct _node {
	int value;
	nodePointer next;
} node;

typedef struct _list {
	nodePointer head;
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

typedef struct _node *nodePointer

typedef struct _node {
	int value;
	nodePointer next;
} node;

typedef struct _list {
	nodePointer head;
} list;

// Creating a new list
list newList(void) {
	list newList = malloc(sizeof(struct _list));
	assert(newList != NULL);
	newList->head = NULL;

	return newList;
}

// Creating a new node
void addItem(List l, int x) {
	assert(l != NULL);
	nodePointer newNode = malloc(sizeof(struct _node));
	newNode->value = x;
	newNode->next = l->next;	// set newNode pointer to the old node

	l->next = newNode; 			// set oldNode pointer to the newNodes
}





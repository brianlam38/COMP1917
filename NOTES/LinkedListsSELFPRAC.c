#include <stdio.h>
#include <stdlib.h>

/* LINKED LIST STRUCT TEMPLATE */

typedef struct _node *link

typedef struct _node {			// node = struct which contains a value + ptr "next" to the next node of list
	int value;
	link next;
} node;

typedef struct _list {			// list = struct which contains a ptr "head" to the first node of the list
	link head;
} list;

/* LINKED LIST BASIC UTILITY FUNCTIONS */

// Iterates a pointer through all nodes in the list
// Also Returns the number of nodes in the list
static int length(list l) {				
	int count = 0;						// initiate counter = 0

	link current = l->head;				// initiate head ptr (the current ptr you want to count from) = first node		

	while (current->next != NULL) {		// loop to count each node
		count++;							// +1 count each iteration
		current = current->next;			// iterate: current node ptr = next node
	}
	return count;
}

// Creates a list with nodes 0, 1, 2 ... n
static link createNode(int x) {
	link newNode = malloc(sizeof(struct _node));	// (1) set memory aside for new node
	newNode->value = x;								// (2) assign a value to new node
	newNode->next = NULL;							// (3) set next ptr = NULL (last node in list)
}

// Given an int + struct node PTR, pointing to the head PTR,
// add a new node at the head of the list with the 3-step-link-in:
	// (1)
static Push(struct node** headRef, int newData);



/* USE OF BASIC UTILITY FUNCTIONS */
void BasicsCaller() {
	struct node* head;
	int len;

	head = BuildOneTwoThree(); // Start with {1, 2, 3}

	Push(&head, 13); // Push 13 on the front, yielding {13, 1, 2, 3}
	// (The '&' is because head is passed
	// as a reference pointer.)

	Push(&(head->next), 42); // Push 42 into the second position
	// yielding {13, 42, 1, 2, 3}
	// Demonstrates a use of '&' on
	// the .next field of a node.
	// (See technique #2 below.)

	len = Length(head); // Computes that the length is 5.
}





static list createList(void) {
	list l = malloc(sizeof(struct _list));
	list->head = NULL;

	return l;
}

static link createNode(int x) {
	link newNode = malloc(sizeof(struct _node));
	newNode->value = x;
	newNode->next = NULL;
}

static void addToEnd(list l, link n) {
	if (l->head = NULL) {
		l->head = n;
	} else {
		curr = l->head;
		while ()
	}
}




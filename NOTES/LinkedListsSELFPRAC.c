#include <stdio.h>
#include <stdlib.h>

// ###############################
// # LINKED LIST STRUCT TEMPLATE #
// ###############################

typedef struct _node *link;

typedef struct _node {			// node = struct which contains a value + ptr "next" to the next node of list
	int value;
	link next;
} node;

typedef struct _list {			// list = struct which contains a ptr "head" to the first node of the list
	link head;
} *list;

// #######################################
// # LINKED LIST BASIC UTILITY FUNCTIONS #
// #######################################

/* CREATE A NEW NODE */
static link createNode(int x) {
	link newNode = malloc(sizeof(struct _node));	// (1) set memory aside for new node
	newNode->value = x;								// (2) assign a value to new node
	newNode->next = NULL;							// (3) set next ptr = NULL (last node in list)

	return newNode;
}

/* CREATE A NEW LIST */
static list createList(void) {
	list l = malloc(sizeof(struct _list));
	list->head = NULL;

	return l;
}

/* ITERATES POINTER THROUGH ALL NODES IN THE LIST */
static int length(list l) {				
	int count = 0;						// initiate counter = 0

	link current = l->head;				// initiate head ptr (the current ptr you want to count from) = first node		

	while (current->next != NULL) {		// loop to count each node
		count++;							// +1 count each iteration
		current = current->next;			// iterate: current node ptr = next node
	}
	return count;
}

/* PUSH NEW NODE AS THE 0TH NODE OF THE LIST */
static void insertNode (list l, int x) {								// "push" into the list as the 0th node
	link newNode = malloc(sizeof (struct _node));						// 1. create new node
	link->value = x;													// 2. put data in new node (99)

	link->next = l->head;												// 3. make ptr in new node point to the OLD node (node w/ 86)
	l->head = newNode;												    // 4. make ptr head, point to the new node
}

/* PUSH NEW NODE TO THE END OF THE LIST
 *
 * Special Case: Function to add nodes to end of an empty list
 * (1) Create initial node + Create loop
 * (2) Create dummy node + Create loop. Return (dummy.next) (not preferred method)
 *
 */
static void addToEnd(list l, link n) {
	if (list->head != NULL) {			// if head PTR != NULl, then head PTR = 
		list->head = n;
	} else {
		curr = l->head;
		while (curr->next != NULL)
			curr = curr->next;
	}
}

/* DELETE Nth NODE WITHIN LIST */
void deleteNthNode(list l, link currentNode, int index) {
	//1. While position != beforeNODE, increment count
	//2. Then create local ptr that points to node at position 0 (pos 0 = beforeNODE)
	//3. Then create local ptr that points to node at position 1 (pos 1= beforeNODE.next / deleteNODE)
	//4. Set beforeNEXT ptr = afterNODE
	//5. Free deleteNODE (node deleted, but local ptr to deleteNODE still exists)
	//6. Set local ptr to deleteNODE -> NULL
/*
	int pos = 0;
	link currentNode = l->head;

	while (pos != (index -1)) {
		pos++;
		currentNode = currentNode->next;
	}
*/
}

// ##################################
// # USE OF BASIC UTILITY FUNCTIONS #
// ##################################

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








/* MODULE 9 - LINKED LISTS */

/* List.h */

									// INTERFACE FUNCTIONS OF THE LIST
typedef int item;			 		// a list of items (of type int)
typedef struct _list * List; 		// a pointer "List" to a struct that stores the list

List newList (void);				// create the list
void showList (List l);				// to show the structure you're building (may be temporary)
int length (List l);				// tells us the length of the list (num items in the list)
item getItem (List l, int position);// get item within the list
void appendItem (List l, item i);	// append item to the end of the list


/* List.c */
/*	CREATING LINKED LIST FROM SCRATCH INSTRUCTIONS
*	1. Define a struct "node", with two properties: item data + ptr to the next node.
*	2. Define a pointer to the struct "node", called "*nodePointer".
*	3. Define a struct "list" (the HEAD), with one property: ptr to the first node.
*	4. Write a "newList" function --> Creates a list / head "new", which points to the first element (NULL initially)
*	5. Write a "length" function --> Counts the length of the linked list. Useful for running tests.
*	6. (OPTIONAL) Write an appendItem function --> Creates a newNode + inserts between the HEAD / FIRST NODEs
*/

#include "List.h"

typedef struct _node *nodePointer;	// *nodePointer points to a struct "node"

typedef struct _node {				// This is the struct called "node" --> Contains an ITEM + PTR to next node
	item data;
	nodePointer next;
} node;

/* LIST STRUCT */
typedef struct _list {				// (THE HEAD / LIST) has a pointer to the FIRST NODE in the list
	nodePointer first;				// A field called "first"
} list;									// The head can store extra fields such as: length of list, description of list

/* CREATING A NEW LIST */
List newList (void) {
	List new = malloc (sizeof (struct _list);
	assert (new != NULL);	
	new->first == NULL;				// Point to first element of the list (NULL because nothing in the list yet)
	return new;
}

/* FINDING LENGTH OF LIST */
int length (List l) {
	int count;
	count = 0;
	nodePointer current;

	current = l->first;
	while (current != NULL) {
		count++;
		current = current->next
	}

	return count;
}

void showList (List l) {
}

item getItem (List l, int position) {
	return 42;
}

/* INSERTING NEW NODE */
void appendItem (List l, item i) {
	assert (l != NULL);
	// 1. create new node
	nodePointer newNode = malloc (sizeof (struct _node));
	// 2. put data in new node (99)
	newNode->data = i;
	// 3. make ptr in new node point to the OLD node (node w/ 86)
	newNode->next = l->first;
	// 4. tell "list" where the start of the new chain is.
	l->first = newNode;
}

/*	GENERAL INSERTING BETWEEN TWO-NODES INSTRUCTIONS
*	1. Create a new node
*	2. Put data in new node
*	3. Make ptr in new node point to the OLD NODE in list --> tie new + old one together
*	4. Make ptr in the PREVIOUS NODE point to the new node. --> break link btwn previous node and old node, then tie previous + new together
*	IN EXAMS, YOU SHOULD:
*	1. Draw pictures (to understand specs)
*	2. Write tests
*	3. Implementations
*/

/* testList.c */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "List.h"

int main (int argc, char *argv[]) {

	printf ("testing newList");
	List l = newList ();
	assert (l != NULL);

	printf ("Testing an empty list has size 0\n");
	assert (length (l) == 0);

	appendItem (l, 86);			// add in 1 element
	assert (l != NULL);			// assert that l is not NULL
	assert (length (l) == 1);	// testing length now = 1

	appendItem (l, 99);
	assert (l != NULL);
	assert (length (l) == 2);	// testing length now = 2

	printf ("All List tests passed! You are awesome!")
	return EXIT_SUCCESS;
}

/* MODULE 10 - LINKED LISTS PART 2 */

beforeNODE = position -1 from the node you want to delete
deleteNODE = node that you want to delete
afterNODE = position +1 from the node you wnat to delete

// EXAMPLE: LISTHEAD --> 99 (beforeNODE) --> 86 (deleteNODE) --> 13 (afterNODE) --> NULL
// We want to remove the node marked "deleteNODE"

/* DELETE NODE FUNCTION */
deleteNode(l,1);	// from List l, delete node in position 1

void deleteNode (List l, int position) {
	//1. While position != beforeNODE, increment count
	//2. Then create local ptr that points to node at position 0 (pos 0 = beforeNODE)
	//3. Then create local ptr that points to node at position 1 (pos 1= beforeNODE.next / deleteNODE)
	//4. Set beforeNEXT ptr = afterNODE
	//5. Free deleteNODE (node deleted, but local ptr to deleteNODE still exists)
	//6. Set local ptr to deleteNODE -> NULL

	//NOTE: Deleting the first node (the one that head points to) will be different
}


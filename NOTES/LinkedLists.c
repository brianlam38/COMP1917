/* LECTRE 44 - LINKED LISTS #2 */

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
#include "List.h"

typedef struct _node *nodePointer;	// *nodePointer points to a struct "node"

typedef struct _node {				// This is the struct called "node" --> Contains an ITEM + PTR to next node
	item data;
	nodePointer next;
} node;

/* LIST STRUCT */
typedef struct _list {				// (THE HEAD) "list" is a pointer to the first node in the list
	nodePointer first;				// The head can store items such as:
} list;									// length of list, description of list

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
	nodePointer newNode = malloc (sizeof (struct _node));	// Setting aside memory for newNode
	newNode->data = i;										// Giving newNode a value
	newNode->next = NULL;									// Giving newNode a pointer to next node (NULL for now)

	l->first = newNode;										// Pointing previous ptr (HEAD ptr in this case) to newNode struct.
}

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
	assert (length (l) == 1);	//

	printf ("All List tests passed! You are awesome!")
	return EXIT_SUCCESS;
}




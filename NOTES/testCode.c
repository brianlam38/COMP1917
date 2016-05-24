#include <stdio.h>
#include <stdlib.h>

typedef struct _node *link;

typedef struct _node {		
	int value;
	link next;
} node;

typedef struct _list {	
	link head;
} *list;

/* (Q1) STANFORD: Given a list and an int, return the number
 *  			  of times that int occurs in the list.
 */

void CountTest() {
	list myList = BuildOneTwoThree(); // build {1, 2, 3}

	int count = Count(myList, 2); 	  // returns 1 since there's 1 '2' in the list
}

int Count(list l, int searchFor) {
	int count = 0;
	link currentNode = l->head;

	while (currentNode->next != NULL) {
		if (currentNode->value == searchFor) {
			count++;
		}
		currentNode = currentNode->next;
	}
	return count;
}

/* (Q2) STANFORD: Write a GetNth() function that takes a linked list and an
 *				  integer index and returns the data value stored in the node
 *				  at that index position.
 */

void GetNthTest() {
	struct node* myList = BuildOneTwoThree(); 		// build {1, 2, 3}	
	int lastNode = GetNth(myList, 2); 				// returns the value 3		
}

int GetNth(list sourceList, int index) {			// The nodes are numbered from 0.
	int count = 0;									// Assert fails if the index is invalid (outside 0..lengh-1).
	int numberResult;
	link currentNode = sourceList->head;

	while (currentNode->next != NULL) {
		if (count == index) {
			numberResult = currentNode->value;
		}
		count++;
		currentNode = currentNode->next;
	}
	return numberResult;
}

/* (Q3) STANFORD: Write a function deleteList() that takes a list, deallocates
 *				  all of its memory and sets its head pointer to NULL.
 */

void DeleteListTest() {
	struct node* myList = BuildOneTwoThree(); // build {1, 2, 3}
	DeleteList(&myList); 					  // deletes the three nodes and sets myList to NULL
}

void DeleteList(list l) {
	link currentNode = l->head;
	link nextNode;

	while (currentNode != NULL) {		// while end of list isn't reached,
		nextNode = currentNode->next;	// set nextNode = currentNode nextPTR (store)
		free(currentNode);				// frees currentNode memory
		currentNode = nextNode;			// sets currentNode var = nextNode
	}
	l->head = NULL;						// sets headPTR = NULL
}

/* (Q4) STANFORD: Write a function deleteList() that takes a list, deallocates
 *				  all of its memory and sets its head pointer to NULL.
 */







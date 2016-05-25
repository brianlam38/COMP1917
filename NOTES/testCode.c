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

// #######################################
// # STANFORD UNIVERSITY LINKED LIST QNS #
// #######################################

/* (Q1) STANFORD: Given a list and an int, return the number
 *  			  of times that int occurs in the list.
 *
 *		RESULT: CORRECT SOLUTION
 */

void CountTest() {
	list myList = BuildOneTwoThree(); // build {1, 2, 3}

	int count = Count(myList, 2); 	  // returns 1 since there's 1 '2' in the list
}

int Count(list l, int searchFor) {
	int count = 0;
	link currentNode = l->head;		  // l->head (head pointer) is copied into a local variable currentNode

	while (currentNode != NULL) {
		if (currentNode->value == searchFor) {
			count++;
			currentNode = currentNode->next;
		}
	}
	return count;
}

/* (Q2) STANFORD: Write a GetNth() function that takes a linked list and an
 *				  integer index and returns the data value stored in the node
 *				  at that index position.
 *				  The nodes are numbered from 0. Assert fails if the index is invalid (outside 0..lengh-1).
 *
 *		RESULT: "CURRECT" BUT NEED CONFIRMATION
 */

void GetNthTest() {
	struct node* myList = BuildOneTwoThree(); 		// build {1, 2, 3}	
	int lastNode = GetNth(myList, 2); 				// returns the value 3		
}													// 

int GetNth(list sourceList, int index) {			
	int count = 0;									// index of the node we're currently looking at.					
	int numberResult;
	link currentNode = sourceList->head;

	while (currentNode != NULL) {
		if (count == index) {
			numberResult = currentNode->value;
			count++;
			currentNode = currentNode->next;
		}
	}
	return numberResult;
}

/* (Q3) STANFORD: Write a function deleteList() that takes a list, deallocates
 *				  all of its memory and sets its head pointer to NULL.
 *
 *		RESULT: CORRECT SOLUTION
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

// ########################
// # UNSW LINKED LIST QNS #
// ########################

/* (Q1) MOD9 T-LAB: Function that finds the length of lists with the prototype */
int length(list ls) {
	int count = 0;
	link currentNode = ls->head;

	while (currentNode != NULL) {
		count++;
		currentNode = currentNode->next;
	}
	return count;
}

/* (Q2) MOD9 T-LAB: Function that determines whether two given lists are equal
 *				  	(equal values) and returns TRUE or FALSE.
 */
int areEqual(list ls1, list ls2) {
	int count = 0;
	char answer;
	link currentNode1 = ls1->head;
	link currentNode2 = ls2->head;

	while ((currentNode1 != NULL) && (currentNode2->next != NULL)) {
		if (currentNode1->value == currentNode2->value) {
			currentNode1->next = currentNode1;
			currentNode2->next = currentNode2;
			char answer = "TRUE";
		} else {
			char answer = "FALSE";
		}
	count++;
	}
	return answer;
}

/* (Q3) MOD9 T-LAB: Function called copy that takes a link to the first element
 *				  	of a list as an argument and returns a copy of the list
 *					(a new list) that contains the same data, in the same order.
 */

list copy(list ls) {
	// takes the link head node, then returns a copy of it that contains the same data, in the same order
	int count = 0;
	int nodeValue;
	link oldNode = ls->head;

	link headNode = createNode(x);				// create headNode

	list ls2 = malloc(sizeof(struct _list));	// create new list ls2
	ls2->head = copyNode;						// set ls2->head to NULL

	while (oldNode != NULL) {				// while old list traverse not finished
		link copyNode = createNode(x);				// create a copyNode, with value = x, nextPTR = NULL
		copyNode->value = oldNode->value;			// set copyNode value = oldNode value

		copyNode = copyNode->next;					// traverse to next copyNode
		oldNode = oldNode->next;					// traverse to next oldNode

		count++;
	}
	return ls2;
}

static link createNode(int x) {
	link newNode = malloc(sizeof(struct _node));
	newNode->value = x;
	newNode->next = NULL;

	return newNode;
}

/* (Q3) MOD9 T-LAB: Function that finds the minimum element in the list (lowest value).
 *					If there are duplicates then use the first one.
 *					Move that element to the front of the list.
 */

void minToFront(list ls) {

}

// Uses length traverse function
// Uses push function (push to headnode)

// LENGTH TRAVERSE
// While currentNode->next != NULL
	// store currentNode->value into a tempVAR
	// compare currentNode->next->value with currentNode->value
		// if it is smaller, then store node element inside tempNode.
		// else if currentNode->value = tempNode->value, then ignore
		// else ignore and traverse further down list until currentNode->next = NULL;
	// PUSH NODE TO FRONT
		// point tempNode to


// ###############################
// # LINKED LIST REVISION - CORE #
// ###############################
//https://www.openlearning.com/courses/comp1917rag/linked_list_revision_core1

// print out a list --> CORRECT SOLUTION
void showList (list listToPrint) {
	link currentNode = listToPrint->head;

	while (currentNode != NULL) {
		printf("[%d]->", currentNode->value);
		currentNode = currentNode->next;
	}
}
 
// insert item at the front of the list --> CORRECT SOLUTION
void frontInsert (list l, int item) {
	// Create insertNode
	link insertNode = malloc(sizeof(struct _node));
	assert(insertNode != NULL);
	insertNode->value = item;

	// Insert insertNode
	link oldNode = l->head;		// local ptr "oldNode" to the old node
	insertNode->next = oldNode;
	l->head = insertNode;
}
 
// count the number of items in the list --> CORRECT SOLUTION BUT NEEDS CHECKING @ "return"
int numItems (list l) {
	assert(l != NULL);

	int count = 0;
	link currentNode = l->head;		// local ptr "currentNode" to the currentNode

	while (currentNode != NULL) {
		count++;
		newNode = newNode->next;
	}
	return count;					// ANSWER SAYS "return (count)" --> Need to confirm why brackets are used???
}
 
// insert at end of list
void append (list l, int value) {
	// create new node
	link tailNodePTR = malloc(sizeof(struct _node));
	assert(tailNodePTR != NULL);
	tailNodePTR->value = x;
	tailNodePTR->next = NULL;

	// case 1 = empty list
	if (l == NULL) {
		l->head = tailNodePTR;

	} else {
		l->head = currentNodePTR;
		while (currentNodePTR->next != NULL) {
			currentNodePTR = currentNodePTR->next;
		}
		currentNodePTR->next = tailNodePTR;
	}
}
 
// Find the value stored at position i
// i MUST be a valid position in the list
// dont call this on positions outside the list
int lookup (list l, int position) {
	int count = 0;
	position = i;
	int answer = 0;
	link currentNode = l->head;
	while (currentNode != NULL) {
		if (count == i) {
			answer = currentNode->value;
		} else {
			currentNode = currentNode->next;
		}
		count++;
	}
	return answer;
}

// SECOND SOLUTION - WITHOUT IF / ELSE

int lookup (list l, int position) {
	int count = 0;
	position = i;
	int answer = 0;
	link currentNode = l->head;
	while (currentNode != NULL && count < i) {
		count++;
		answer = currentNode->value;
		currentNode = currentNode->next;
	}
	return answer;
}

// position = 3
// while currentNode->next is not end of list yet,
	// count 0 != 3
	// therefore, currentNode = currentNode->next
// move up one count
	// count 1 != 3
	// therefore ...
// move up ...
	// count 3 == 3
	// therefore, value = answer

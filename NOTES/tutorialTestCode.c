
// #####################
// # JORDANS QUESTIONS #
// #####################

// RecursiveReverse example

Node recursiveReverse(List L, Node Curr) {
	Node returnNode;
	if (Curr->next == NULL) {
		L->head = Curr;
		returnNode = Curr;
	} else {
		returnNode = recursiveReverse(L, Curr->next);
		returnNode->next = Curr;
		returnNode = Curr;
	}
	return returnNode;
}

// Concatenate List Example

List copyList(List A) {
	List C = malloc(sizeof(struct _list));

	Node curr = A->head;
	Node prev = curr;
	while (curr != NULL && curr->next != NULL) {
		Node newNode = malloc(sizeof(struct _node));
		newNode->value = curr->value;
		prev->next = newNode;
		curr = curr->next;
		prev = newNode;
	}
	return curr;
}

List concatenateAndNew(List A, List B) {
	List C = copyList(A);
	concatenateList(C, B);
	return C;
}

void concatenateList(List A, List B) {
	// Put list B -> end of A
	Node endA = getEndOfList(A);

	if (endA == NULL) {
		A->head = B->head;
	} else {
		endA->next = B->head;
	}
}

Node getEndOfList(List L) {
	node curr = L->head;
	while (curr != NULL && curr->next != NULL) {	// order of && matters.
		curr = curr->next;s
	}
	return curr;
}


// #######################
// # TUTE QUESTIONS WK10 #
// #######################

Given two linked lists, create a new list that 'interleaves' the two lists.
The two lists can be different lengths, and if no more nodes of one list can be 'zipped',
append the rest of the other nodes to your new list. Example is shown below:
List A: [1]->[3]->[5]->[X]
List B: [2]->[4]->[6]->[X]
List C = zip(list A, list B)
List C: [1]->[2]->[3]->[4]->[5]->[6]->[X]
Constraints: You should NOT malloc any new struct _nodes.
The original lists A and B should be empty lists by the end of the function.



list weavedList(list A, list B) {
	// create an empty list
	list C = malloc(sizeof(struct _list));
	C->head = NULL;

	link currentNodeA = A->head;
	link currentNodeB = B->head;

	// weave B-->A
	while (currentNodeA != NULL && currentNodeB != NULL) {
		currentNodeA = C->head;
	}





}

// ##########################
// # 2015 PRACTISE QUESTION #
// ##########################

// frontBackSplit.c
// 
 
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
 
#include "list-ppexam.h"

// given a list of nodes, split it into two sublists 
// - one for the front half, and one for the back half. 
// If the number of elements is odd, the extra element 
// should go in the front list. 

// The first argument (sourceList) is the original list.
// The second argument (frontList) which is initally empty 
// should point to the front half of the list.
// The third argument (backList) which is initially empty
// should point to the back half of the list.
// The original list (sourceList) should be empty after the split.
//
// Constraints:
// don't malloc any new nodes
// don't change the "value" field of any node, just change links
// don't delete any nodes (i.e. do not call free())

// e.g. if sourceList is 1->4->6->4->3->X then 
// after execution of the function frontBackSplit() 
// frontList should be 1->4->6->X and 
// backList should be 4->3->X and
// sourceList should be X (i.e. empty)
//
// and if sourceList is 3->10->15->25->X then
// after execution of the function frontBackSplit() 
// frontList should be 3->10->X and
// backList should be 15->25->X
// sourceList should be X (i.e. empty)

// A function to determine the length of a list called numItems() 
// is provided. Fell free to use it but do not modify the function.

//function to determine length of a linked list
int numItems (list l) {

    int length = 0;
    link current = l->head;
    while (current != NULL){
        length++;
        current = current->next;
    }
    return length;
}

void frontBackSplit (list sourceList, list frontList, list backList) {
// put your code here
    //now... how to do it????
    // we need to determine how many items there are in the initial list
    // then given even, we split,
    // given odd, we split

    int nodes = 0;
    int split = 0;

    nodes = numItems(sourceList);
    split = nodes / 2;
    if (nodes % 2 == 1) {
        split++;
    }

    // so here, split should return the number of nodes that should be attached to the frontList
    // the remained should be attached to the backList

    int counter = 0;
    link current = sourceList->head;
    link previous = NULL;

    if (sourceList->head != NULL) {
        frontList->head = sourceList->head;

        while (counter < split) {
            previous = current;
            current = current->next;
            counter++;
        }        
        backList->head = current;
        previous->next = NULL;
        sourceList->head = NULL;
    }
// Need to cut it off, how to cut it off???
// so here, current splits properly, where at the end of the while loop, current points to the address of the node which should be in the backList (I think)
// 
}







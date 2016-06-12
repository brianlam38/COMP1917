// pairwiseSwap.c
// 
 
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
 
#include "list-ppexam.h"
 
// given a list of nodes, write a function to swap nodes pairwise.
// For example, if the linked list is 1->2->3->4->5->6->7->X then
// the function should change it to 2->1->4->3->6->5->7->X and
// if the linked list is 1->2->3->4->5->6->X then the function 
// should change it to 2->1->4->3->6->5->X
//
// Constraints:
// don't malloc any new nodes
// don't change the "value" field of any node, just change links
// don't delete any nodes (i.e. do not call free())
// 
// More Examples:
// Original list 1->X, after swap remains 1->X
// Original list 1->4->X, after swap 4->1->X
// Original list 3->6->7->X, after swap 6->3->7->X
// Original list 5->3->6->2->X, after swap 3->5->2->6->X 


// HINTS: 
// 1) Traverse the list and swap two nodes at a time,
// then proceed to the next pair. 
// 2) You may need to maintain pointers to three nodes during each 
// swap operation - the two nodes that are being swapped and the node 
// preeceding the pair (i.e. previous, current and next).

int numItems (list l) {

    int length = 0;
    link current = l->head;
    while (current != NULL){
        length++;
        current = current->next;
    }
    return length;
}

void pairwiseSwap (list l) {
	int count = numItems(l);

	link curr1 = l->head;
	link curr2 = l->head->next;

	if (l->head != NULL) {
		// one node
		if (l->head->next == NULL) {
			curr1->next = NULL;
		// two nodes
		} else if (l->head->next->next == NULL) {
			curr1->next = NULL;
			curr2->next = curr1;
			l->head = curr2;
		// EVEN CASE
		} else if (count % 2 == 0) { 
			// first case linking
			link prev = curr1;
			curr1->next = curr2->next;
			curr2->next = curr1;
			l->head = curr2;
			while (curr1->next != NULL) {
				// setting up ptrs
				prev = curr1;
				curr1 = curr1->next;
				curr2 = curr1->next;
				// swapping
				curr1->next = curr2->next;
				curr2->next = curr1;
				prev->next = curr2;
			}
		// ODD CASE
		} else if (count % 2 == 1) {
			// first case linking
			link prev = curr1;
			curr1->next = curr2->next;
			curr2->next = curr1;
			l->head = curr2;
			while (curr1->next->next != NULL) {
				// setting up ptrs
				prev = curr1;
				curr1 = curr1->next;
				curr2 = curr1->next;
				// swapping
				curr1->next = curr2->next;
				curr2->next = curr1;
				prev->next = curr2;
					// ODD CASE
			}
			curr1->next->next = NULL;
		}
	}
}







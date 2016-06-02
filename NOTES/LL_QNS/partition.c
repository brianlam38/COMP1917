// partition.c
// gcc -Wall -Werror -std=c99 -O -o testPartition testPartition.c partition.c

//OR for gdb debugging use
// gcc -Wall -Werror -std=c99 -gdwarf-2 -o testPartition testPartition.c partition.c
     
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
     
#include "list-partition.h"
     
// given a list of integers and an integer key, write a function which 
// finds all the integers in the list that are smaller than the first element 
// and moves them to the beginning of the list. 

// So if the original list is        10->55->66->4->X, 
// the list should be modified to be  4->10->55->66->X

// If the original list is 10->4->1->X
// the list should be modified to be 4->1->10->X

// If the original list is    10->55->3->9->10->89->1->11->X, 
// the modified list would be 3->9->1->10->55->10->89->11->X

// If the original list is empty it should remain unmodified

// Constraints:
// don't delete any nodes (i.e. do not call free())
// don't create any new structs (i.e. do not call malloc())
// the nodes that are smaller and moved to the front should remain in their original relative order
// the nodes that are greater than or equal should remain in their original relative order
     
void partition (list sourceList) {
	if (sourceList->head != NULL) {
		link leftEnd = NULL;						// initiate LHS
		link leftStart = NULL;
		link curr = sourceList->head;				// curr @ NODE 1
		link initialNode = sourceList->head;		// initialNode @ NODE 1
		int initialVal = initialNode->value;

		// ONE NODE CASE
		if (sourceList->head->next == NULL) {
			curr->next = NULL;
		} else {
			link prev = curr;						// prev @ NODE 1
			curr = curr->next;						// curr @ NODE 2
			// For first node connect
			while (leftStart == NULL && curr != NULL) {
				// Moving to LHS
				if (curr->value < initialVal) {
					leftStart = curr;
					prev->next = curr->next;		// prev @ NODE 1
					curr->next = initialNode;		// connects curr to initial node
					curr = prev->next;				// bring curr @ NODE 2
					sourceList->head = leftStart;
				// Continue along list
				} else {
					prev = curr;
					curr = curr->next;
				}
			}
			// For all other connects until the end
			leftEnd = leftStart;
			while (curr != NULL) {
				// Moving to LHS
				if (curr->value < initialVal) {
					prev->next = curr->next;
					leftEnd->next = curr;
					curr->next = initialNode;
					//curr = prev->next;
					curr = prev->next;
					leftEnd = leftEnd->next;
				// Continue along list
				} else {
					prev = curr;
					curr = curr->next;
				}
			}			
		}
	}


}








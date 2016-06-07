#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
 
#include "list-ppexam.h"

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

// split sourceList into front and backList
// if odd amount of nodes, then frontList gets extra node
// make front and back empty afterwards

void frontBackSplit (list sourceList, list frontList, list backList) {
	int split = numItems(sourceList) / 2;

	// EMPTY LIST CASE
	if (sourceList->head == NULL) {
		frontList->head = NULL;
		backList->head = NULL;
	// ONE NODE CASE
	} else if (sourceList->head->next == NULL) {
		frontList->head = sourceList->head;
		frontList->head->next = NULL;
		sourceList->head = NULL;
		backList->head = NULL;
	} else {
		frontList->head = sourceList->head;
		link curr = frontList->head;
		link prev = NULL;
		int count = 0;
		// EVEN CASE
		if (numItems(sourceList) % 2 == 0) {
			while (count < split) {
				prev = curr;
				curr = curr->next;
				count++;
			}
			// linking backList
			backList->head = curr;
			// ending frontList
			prev->next = NULL;
		// ODD CASE
		} else if (numItems(sourceList) % 2 == 1) {
			while (count < (split + 1)) {
				prev = curr;
				curr = curr->next;
				count++;
			}
			// linking backList;
			backList->head = curr;
			// ending frontlist
			prev->next = NULL;
		}
		sourceList->head = NULL;
	}


}
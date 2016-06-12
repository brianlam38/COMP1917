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

void frontBackSplit (list sourceList, list frontList, list backList) {


	link curr = sourceList->head;
	link prev = NULL;

	int split = (numItems(sourceList) / 2);
	int count = 0;

	// null case
	if (sourceList->head == NULL) {
		frontList->head = NULL;
		backList->head = NULL;
	// one case
	} else if (numItems(sourceList) == 1) {
		frontList->head = sourceList->head;
		frontList->head->next = NULL;
		backList->head = NULL;
		sourceList->head = NULL;
	// even case
	} else if (numItems(sourceList) % 2 == 0) {
		frontList->head = sourceList->head;
		while (count < split) {
			prev = curr;
			curr = curr->next;
			count++;
		}
		backList->head = curr; 	 // start of backlist
		prev->next = NULL; 	   	 // end of frontlist
		sourceList->head = NULL; // empty sourceList

	// odd case
	} else if (numItems(sourceList) % 2 == 1) {
			frontList->head = sourceList->head;
			while (count < (split + 1)) {
				prev = curr;
				curr = curr->next;
				count++;
			}
			prev->next = NULL;
			backList->head = curr;
			sourceList->head = NULL;
	}
}
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
	int split = (numItems(sourceList) / 2);

	int count = 0;
	link current = sourceList->head;
	link previous = NULL;

	// null case
	if (sourceList->head == NULL) {
		frontList->head = current;
		current = NULL;
		sourceList->head = NULL;
	// one node case
	} else if (numItems(sourceList) == 1) {

		frontList->head = sourceList->head;
		frontList->head->next = NULL;
		backList->head = NULL;
		sourceList->head = NULL;

	// even case
	} else if (numItems(sourceList) == 1) {

		frontList->head = sourceList->head;
		while (count < split) {
			previous = current;
			current = current->next;
			count++;
		}
		backList->head = current;
		previous->next = NULL;
		sourceList->head = NULL;
	// odd case
	} else if (numItems(sourceList) == 1) {

		frontList->head = sourceList->head;
		while (count < (split + 1)) {
			previous = current;
			current = current->next;
			count++;
		}
		backList->head = current;
		previous->next = NULL;
		sourceList->head = NULL;
	}
}

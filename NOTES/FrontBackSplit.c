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
    // get length of sourceList
        // divide by 2.
    // If % 2 = 0, then do even split
    // If % 2 = 1, then do odd split (+1 node for frontList)

    int count = 0;
    int split = (numItems(sourceList) / 2);

    link current = sourceList->head;
    link previous = NULL;

    if (sourceList->head == NULL) {     // If sourceList is empty:
        frontList->head = current;          // attach sourceList to frontList
        current = NULL;               // point next node = NULL
        sourceList->head = NULL;            // empty sourceList
    // one node case
    } else if (numItems(sourceList) == 1) {
        frontList->head = sourceList->head;
        frontList->head->next = NULL;
        backList->head = NULL;
        sourceList->head = NULL;
    // odd cases > 1
    } else if (numItems(sourceList) % 2 == 0) {
        frontList->head = sourceList->head;
        while (count < split) {
            previous = current;
            current = current->next;
            count++;
        }
        backList->head = current;
        previous->next = NULL;
        sourceList->head = NULL;
    // odd cases > 1
    } else if (numItems(sourceList) % 2 == 1) {
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
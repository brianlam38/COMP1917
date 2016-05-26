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

    link currentFront = frontList->head;
    link currentBack = backList->head;

    // empty sourcelist case
    if (sourceList->head == NULL) {
        currentFront = sourceList->head;                // (1) Attach sourceList->head = currentFront head
        currentFront->next = NULL;                      // (2) Set currentFront->next = NULL
    } else {
    // event split case                                 
        if (split % 2 == 0) {
            currentFront = sourceList->head;            // (1) Attach front list first
            while (count != split) {
                currentFront = currentFront->next;
                count++
            }
            currentBack->head = currentFront->next;     // (2) Attach back list when split is reached
    // odd split case
        } else {
            currentFront = sourceList->head;            
            while (count < (split + 1) {
                currentFront = currentFront->next;
                count++;
            }
            currentBack->head = currentSource->next;
            }
        }
    }
}
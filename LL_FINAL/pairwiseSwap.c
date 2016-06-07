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
// put your code here

    int count = (numItems(l)) / 2; // so this will tell me how many times I need to do the double joint, not including when there is one extra

    if ((l->head != NULL) && (numItems(l) != 1)) {
        link current = l->head; // first node

        link first = current; // == first node (1 OLD)
        link second = first->next; // == second node (2 OLD)

        current = second->next; // reset to == third node (3 OLD)

        link oldTail = first;

        l->head = second;
        second->next = first;
        first->next = current;


        int counter = 0;

        while (counter < (count - 1)) {
            first = current; // == first node (1 OLD) 3
            second = first->next; // == second node (2 OLD) 4
 
            current = second->next; // reset to == third node (3 OLD) 5 OLD
    
            oldTail->next = second;
            second->next = first;
            oldTail = first;
            first->next = current;

            counter++;
        }
    }
}

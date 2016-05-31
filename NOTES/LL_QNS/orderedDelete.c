// orderedDelete.c
// 
 
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
 
#include "list-ppexam.h"
 
// given a list of nodes 
// eg 1->4->2->6->6->10->4->X
// starting from the front of the list remove from the 
// list any element whose value is smaller than the
// value of the last unremoved node before it.
// hence the list that is left will be in non decreasing
// order.  
// remove the new node by rearranging pointers, don't change the 
// value field for nodes already in the list.
// (don't call free() on the nodes you remove from the list -
// instead you can assume they are being used elsewhere or
// they have been declared on the stack so their removal 
// from the list will not cause a memory leak)
 
// e.g. running the function on this list:
//   1->4->2->3->6->6->10->4->X
// would alter the list to become
//   1->4->6->6->10->X

void orderedDelete (list l) {
    link curr = l->head;
    link prev = NULL;

    if (l->head != NULL) {
        prev = curr;
        curr = curr->next;
        while (curr != NULL) {
            if (prev->value <= curr->value) {
                prev = curr;
                curr = curr->next;
            } else {
                curr = curr->next;
                prev->next = curr;
            }
        }
    }
}


/* CHRIS SOLUTION
// A while loop with 7, 8, 21, X

    if (l->head != NULL) { //A1
        link current = l->head; //A1
        int maxValue = current->value; // what A1's value is 7

        link endOfNewList = current; // endOfNewList is pointing to A1
//------------------------------------------
        while (current->next != NULL) { // current->next is A
            link after = current->next; // after is == A2
            if (after->value >= maxValue) { // after->value is the value in A2 which is 8. This is greater than max value
                maxValue = after->value; //maxValue gets changed to 8
                endOfNewList->next = after;  //A1 is now pointing to A2
                endOfNewList = after; // endOfNewList now points to A2
            }
            current = current->next; //current now == A2
        }
    endOfNewList->next = NULL; // A2 now points to NULL
    }
} 
*/

/*---------------------------------------------THE WRONG VERSION
    if (l->head != NULL) { //A1
        link current = l->head; //A1
        int maxValue = current->value; // what A1's value is 7

        link endOfNewList = current; // endOfNewList is pointing to A1
        while (current->next != NULL) { // current->next is A
            link after = current->next; // after is == A2
            if (after->value >= maxValue) { // after->value is the value in A2 which is 8. This is greater than max value
                maxValue = after->value; //maxValue gets changed to 8
                endOfNewList->next = after;  //A1 is now pointing to A2
                endOfNewList = after; // endOfNewList now points to A2
                endOfNewList->next = NULL; // A2 now points to NULL                <=========================================
            }
            current = current->next; //current now == A2
        }
    }
// Why is there an error????
// The error is on the pointer line
// Error caused starting on the line pointer at where I made A2 point to NULL. But then, after the if, I changed current to the address of A2. So When I do the while loop again, it wont go ahead because it points at NULL
*/

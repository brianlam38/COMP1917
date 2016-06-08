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
    if (l->head != NULL) {
        link curr = l->head->next;        // @ NODE 1
        link prev = l->head;

        while (curr != NULL) {
            if (prev->value > curr->value) {
                curr = curr->next;
                // unlinking
                prev->next = curr;
            } else {
                prev = prev->next;
                curr = curr->next;
            }
        }
    }
}
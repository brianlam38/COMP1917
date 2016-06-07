/*
 *  firstWillBeLast.c
 *  concept thanks to Matthew
 *  20 13 s1 Practice Prac Exam #2
 *  UNSW comp1917
 *
 *  Created by INSERT YOUR NAME HERE
 *  Share freely CC-BY-3.0
 *
 */

// Complete this function and submit this file ONLY
// for the prac exam.  Do not change the other supplied
// as you will not be submitting them.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "firstWillBeLast.h"

nodePtr frontToBack (nodePtr list) {


}

/* CHRIS SOLUTION

// we need to get the first node of the list and move it to the back
// now... how do we do that
// we are going to need a previous???
// a current
// store the address of the first node
// store the address of the second node
// connect the list to the second node
// move first to the end
// make it point to NULL

    nodePtr current = list;
    nodePtr first = list;
    nodePtr ret = list;

    if (list != NULL) { 
        while (current->next != NULL) { // so here, we stop with current being the address of the last node in the list
            ret = first->next;
            current = current->next;
        }
        current->next = first;
        first->next = NULL;
    }
    
    return ret;
}

*/

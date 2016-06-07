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

// given a list of nodes this function takes the node
// from the front of the list and moves it to the end
// of the list  by changing pointers, leaving the relative
// order of the other nodes unchanged.
// note: this function must not create new nodes 
// or change the value field of existing nodes.

nodePtr frontToBack (nodePtr list) {
	nodePtr curr = list;	// initialises curr @ NODE 1
	nodePtr first = list;	// initialises first @ NODE 1

	if (list != NULL) {
		// ONE NODE CASE
		if (list->next == NULL) {
			list->next = NULL;
		// ALL OTHER CASES
		} else {
			while (curr->next != NULL) {
				curr = curr->next;
			}
			list = first->next;
			curr->next = first;
			first->next = NULL;
		}
	}
	return list;
}



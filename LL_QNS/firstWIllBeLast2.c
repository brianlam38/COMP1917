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
	nodePtr current = list;

	if (list != NULL) {
		list sendToBack = current;		// sendToBack var, stores current (NODE 1)

		list after = current->next;		// after var, stores current->next (NODE 2)
		list = after;				// connects l->head with after (NODE 2)
	} else if (list->next->next == NULL) {
		list->head = current;
		current->next = NULL;
	} else {

		while (current != NULL) {		// iterates to the last node
			current = current->next;
		}
		current->next = sendToBack;		// points old last node to new last node sendToBack
		sendToBack->next = NULL;		// points sendToBack to NULL
	}
	return list;
}




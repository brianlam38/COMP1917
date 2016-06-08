/*
 *  reverseList.c
 *  2013s1 Practice Prac Exam #1
 *  UNSW comp1917
 *
 *  Created by INSERT YOUR NAME HERE
 *  Share freely CC-BY-3.0
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list-ppexam.h"

nodePtr reverse (nodePtr inputList) {
	nodePtr curr = inputList;
	nodePtr prev = NULL;

	if (inputList != NULL) {
		while (curr != NULL) {
			nodePtr after = curr->next;
			curr->next = prev;
			prev = curr;
			curr = after;
		}
		inputList = prev;		
	}
	return inputList;
}

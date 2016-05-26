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
#include "reverseList.h"

list reverse (list inputList) {

	list reverseList = inputList;

	if (inputList != NULL) {
		list countList = inputList->rest; 		// create inputList counter + set it to inputlist head
		list previous = NULL;					// create previous counter + set to NULL
		list goBackToBeginning = inputList;
		list end = reverseList;
		while (goBackToBeginning->rest != NULL) {		// WHILE inputlist is not at the end:
			while (countList != NULL) {		// WHILE inputList counter != end of list
				previous = countList;					// previousPTR store address of countList; // point to second last node
				countList = countList->rest;			// iterate countList x 1 //points to last node
			}
			//reverseList->rest = countList;			// end of inputList connected to reverseList head
			end->rest = countList;
			end = countList;
			previous->rest = NULL;
			countList = goBackToBeginning;			// set countList back to address of inputList head (the start of the list)
		}
		end->rest = goBackToBeginning;
	}
	return reverseList;
}

// inputList:  [1] --> [2] --> [3] --> [X]
// outputList: [3] --> [2] --> [1] --> [X]

// NULL CASE
// inputList --> [X]
// outputList -->[X]

// Solution 1
	// Move INTPUT --> OUTPUT via:
		// --> [1]moveToFront --> [2]moveToFront --> [3]moveToFront --> [X]


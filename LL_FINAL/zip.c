/*
 *  zip.c
 *  
 *  2013 s1 Practice Prac Exam #2
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
#include "zip.h"

list zip (list listA, list listB) {
	list currA = listA;
	list currB = listB;

	if (listA && listB != NULL) {
		if ((listA->rest == NULL) && (listB->rest == NULL)) {
			currA->rest = currB;
			currB->rest = NULL;
		} else {
			currA = currA->rest;	// curr @ A.NODE 2
			list prevA = listA;		// prev @ A.NODE 1
			list prevB = NULL;
			while (currB != NULL) {
				prevA->rest = currB;
				prevB = currB;
				currB = currB->rest;
				prevB->rest = currA;
				prevA = currA;
				currA = currA->rest;
			}
		}
	}
	return listA;
}
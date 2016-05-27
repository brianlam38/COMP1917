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

// so there are no lists in this, just nodes and node pointers

// need to include a start once I find the end of the linked list
// so use a while loop
// if not starting NULL, store the addresses until I get the last

// repeat process but now attach to the end of the new node

// Lets assume we have 3 nodes in the linked List
// test 0 and 1 later

    list startingNode = inputList;

    if (inputList != NULL) {
        list current = inputList; // points to the first node
        list previous = current;// here previous contains the address of the first node

        while (current != NULL) {
            previous = current;// so here, it will stop where previous is the address of the final node
            current = current->rest; 
        }

        startingNode = previous; // so startingNode contains the address of the new header; the address of the new first node; the address of the final node in the old list
        list endNewNode = startingNode; //endNewNode also contains the address of the new node, but we will be moving this later

        while (inputList->rest != NULL) { // so here, it will stop the loop when the address of the old first node points to NULL
            current = inputList; // here, current will be equal to the address of the first node
            
            while (current->rest != NULL) {
                previous = current; // here, it will stop at the address of the second last node
                current = current->rest; // here, it will stop at the address of the last node
            }
            
            endNewNode->rest = current;
//            current->rest = NULL; // shouldnt need this
            endNewNode = current;
            previous->rest = NULL;

        }
        endNewNode->rest = inputList;
        inputList->rest = NULL;
    }

    return startingNode;
}

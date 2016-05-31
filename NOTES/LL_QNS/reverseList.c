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

list reverse (list inputList) {
    link curr = inputList->head;
    link temp = curr;
    link next = curr->next;

    if (inputList != NULL) {

        if (next == NULL) {
            inputList->head = curr;
            curr->next = NULL;
        }

        if (temp == curr) {
            temp->next = NULL;      // temp @ NODE 1 -> points to NULL
            curr = next;            // curr @ NODE 2
            next = curr->next;      // next @ NODE 3
        }

        while (curr != NULL) {
            curr->next = temp;      // point curr backwards NODE 2 -> NODE 1
            temp = curr;            // set temp @ NODE 2
            curr = next;            // set curr @ NODE 3
            next = curr->next;      // set next @ NODE 4
        }
        inputList->head = curr;
    }
    return inputList;
}







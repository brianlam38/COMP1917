#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
 
#include "list-ppexam.h"

void orderedDelete (list l) {
link current = l->head;
link after = NULL;

	if (l->head == NULL) {		// case for 1 value
		l->head = NULL;
	} else if (current->next == NULL) {			// case for no values
		l->head = current;
	} else {
	
		while (current->next != NULL) {
			after = current->next;
			if (current->value <= after->value) {	// if next node > current node, then ignore
				current = current->next;
			} else {								// else, set current = after
				current->next = after->next;
			}
		}
	}	
}





/* EXAM NOTES
 *
 * (1) For linking, think about placing left -> right path (esp with the equations)
 *	   --> Linking existing node after another one: list->head = newNode
 *	   --> Unless you are declaring a new "link" to begin iteration, then link currentNode = list->head;
 *
 * (2) With moving nodes within its own list, you can create a PTR to the list itself that acts as a "copy"
 *	   --> list A;
 *	   --> E.g. link listPTR = A;
 *
 */

// #######################
// # DIFFICULT QUESTIONS #
// #######################

//#####################################################################################
/* SPLIT LIST INTO 2: FRONT + BACK LIST */
void frontBackSplit (list sourceList, list frontList, list backList);

	// SOLVED

//#####################################################################################
/* WEAVE 2 LISTS TOGETHER */
list weavedList(list A, list B);

	// NO SOLUTION YET

//#####################################################################################
/* REVERSE A LIST (old struct) */
list reverse (list inputList) {

	link curr = inputList->head;	// at node 1
	link prev = NULL;				// at NULL

	while (curr != NULL) {
		link after = curr->next;	// creates var AFTER, storing address NODE 2
		curr->next = prev;			// sets curr's next to point to prev.
		prev = curr;				// sets var PREV to address NODE 1
		curr = after;				// sets curr to address NODE 2
	}
	inputList->head = prev;

	return inputList;
}


	// Create a temp var that stores address of head node
	// Traverse each node and reverse the link / reverse the address (breaking the link)


//#####################################################################################
/* FRONT TO BACK (old struct) */
nodePtr frontToBack (nodePtr list);

	// NO SOLUTION YET

//#####################################################################################
/* PAIR SWAP */

void pairwiseSwap (list l) {

}


int numItems (list l) {
}

//#####################################################################################
/* REMOVE UPPER CASE */

void removeUpperCase(List l) {
	// WHILE current != null
		// IF value is between A - Z:
			// Set temp var = current (store current's value)
			// Iterate current x 1

			// IF prev = NULL 					--> For starting case
				// Set list head = current;
			// ELSE 							--> For every other case
				// Set prev->next = current;

			// Free (temp var)

		// ELSE
			// Set prev = current (stores current's value)
			// Iterate current once

//#####################################################################################
/* ORDERED DELETE */

int numItems (list l);
void frontBackSplit (list sourceList, list frontList, list backList);

	// SOLVED

//#####################################################################################





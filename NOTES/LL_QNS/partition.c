void partition (list sourceList) {
	link smallerList = NULL;					// represent the left list
	link smallerTail = NULL;					// represent the end node of left list

	if (sourceList->head != NULL) {
		int val = sourceList->head->value;		// stores initial comparison value

		link curr = sourceList->head->next;		// initiates current (node 2)
		link prev = sourceList->head;			// initiates previous (node 1)

		while (curr != NULL) {
			// MOVE NODE CASE
			if (curr->value < value) {			
				link next = curr->next;			// declare a next ptr (node 3)
				prev->next = next;				// breaking link, connecting prev to next (node 1 -> node 3)

				// INITIAL MOVE NODE CASE
				if (smallerTail == NULL) {
					smallerList = curr;			// set smallerList = curr (smallerList = node 2)
				// OTHER MOVE NODE CASES
				} else {
					smallerTail->next = curr;	// connect "curr" (node to move from RHS) to smallertail->nexts
					smallerTail = curr;			// update the new smallerTail
				}
				smallerTail = curr;				// set smallerTail = curr (for the initial case)
				curr->next = NULL;				// set the tail to point to NULL
				curr = next;					// MOVE CURR BACK TO RHS LIST @ NEXT NODE
			// NON MOVE NODE CASE
			} else {
				prev = curr;					// move prev up to curr
				curr = curr->next;				// move curr to next node
			}
		}
		// AT THE END OF LIST ITERATION
		if (smallerTail != NULL) {
			smallerTail->next = sourceList->head;	// connect LHS tail with sourceList->head
			sourceList->head = smallerList;			// set sourceList->head to front of LHS list
		}
	}
}
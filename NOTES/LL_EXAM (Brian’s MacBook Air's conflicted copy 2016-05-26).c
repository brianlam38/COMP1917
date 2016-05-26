/* EXAM NOTES
 *
 * (1) When thinking about linking, think about placing things left -> right path (esp with the equations)
 *	   --> Linking existing node after another one: list->head = newNode
 *	   --> Unless you are declaring a new "link" to begin iteration, then link currentNode = list->head;
 *
 * (2) When moving entire lists (through splitting lists etc):
 *	   --> You can simply point 
 */

 //function to determine length of a linked list
int numItems (list l) {

    int length = 0;
    link current = l->head;
    while (current != NULL){
        length++;
        current = current->next;
    }
    return length;
}

void frontBackSplit (list sourceList, list frontList, list backList) {
	// get length of sourceList
		// divide by 2.
	// If % 2 = 0, then do even split
	// If % 2 = 1, then do odd split (+1 node for frontList)

	int count = 0;
	int split = (numItems(sourceList) / 2);				// split variable used to count to halfway

	link currentFront = frontList->head;
	link currentBack = backList->head;

	// empty sourcelist case
	if (sourceList->head == NULL) {
		sourceList->head = currentFront;				// (1) Attach sourceList->head = currentFront head
		currentFront->next = NULL;						// (2) Set currentFront->next = NULL
	} else {
	// event split case									
		if (split % 2 == 0) {
			sourceList->head = currentFront;			// (1) Attach front list first
			while (count != split) {
				currentFront = currentFront->next;
				count++
			}
			currentBack->head = currentFront->next;		// (2) Attach back list when split is reached
	// odd split case
		} else {
			sourcelist->head = currentFront;			
			while (count < (split + 1) {
				currentFront = currentFront->next;
				count++;
			}
			currentBack->head = currentSource->next;
			}
		}
	}
}
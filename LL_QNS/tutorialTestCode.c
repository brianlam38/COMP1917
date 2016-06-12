
// #####################
// # JORDANS QUESTIONS #
// #####################

// RecursiveReverse example

Node recursiveReverse(List L, Node Curr) {
	Node returnNode;
	if (Curr->next == NULL) {
		L->head = Curr;
		returnNode = Curr;
	} else {
		returnNode = recursiveReverse(L, Curr->next);
		returnNode->next = Curr;
		returnNode = Curr;
	}
	return returnNode;
}

// Concatenate List Example

List copyList(List A) {
	List C = malloc(sizeof(struct _list));

	Node curr = A->head;
	Node prev = curr;
	while (curr != NULL && curr->next != NULL) {
		Node newNode = malloc(sizeof(struct _node));
		newNode->value = curr->value;
		prev->next = newNode;
		curr = curr->next;
		prev = newNode;
	}
	return curr;
}

List concatenateAndNew(List A, List B) {
	List C = copyList(A);
	concatenateList(C, B);
	return C;
}

void concatenateList(List A, List B) {
	// Put list B -> end of A
	Node endA = getEndOfList(A);

	if (endA == NULL) {
		A->head = B->head;
	} else {
		endA->next = B->head;
	}
}

Node getEndOfList(List L) {
	node curr = L->head;
	while (curr != NULL && curr->next != NULL) {	// order of && matters.
		curr = curr->next;s
	}
	return curr;
}


// #######################
// # TUTE QUESTIONS WK10 #
// #######################

Given two linked lists, create a new list that 'interleaves' the two lists.
The two lists can be different lengths, and if no more nodes of one list can be 'zipped',
append the rest of the other nodes to your new list. Example is shown below:
List A: [1]->[3]->[5]->[X]
List B: [2]->[4]->[6]->[X]
List C = zip(list A, list B)
List C: [1]->[2]->[3]->[4]->[5]->[6]->[X]
Constraints: You should NOT malloc any new struct _nodes.
The original lists A and B should be empty lists by the end of the function.



list weavedList(list A, list B) {
	// create an empty list
	list C = malloc(sizeof(struct _list));
	C->head = NULL;

	link currentNodeA = A->head;
	link currentNodeB = B->head;

	// weave B-->A
	while (currentNodeA != NULL && currentNodeB != NULL) {
		currentNodeA = C->head;
	}
}





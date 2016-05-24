/*	LINKED LIST EXAM PRACTISE
 *
 * 	There are two style of exam questions:
 *	(1) Create new list with new copies of old list
 *	(2) Move original list stuff into a new list
 *
 *	EXTRA TIPS: Memory Leaks
 *	- You will be notified if you should free() or not
 *
 */

typedef struct _node *link;	// a link points to a node

typedef struct _node {
	int value;
	link next;
} node;

// list = a pointer to a struct which contains a pointer to the first node of the list called the "head"

typedef struct _list {
	link head;
} *list;

/* FACTORIAL PROBLEM
 * 
 * 0 or less
 * X
 * 1
 * 1->X
 * 2
 * 1->2->X
 * 3s
 * 1->2->6
 */

static list createList(void);
static link createNode(int val);

//LIST->X
list factorial (int x) {
	list ls = createList();			//create a new list - function
	link newNode = NULL;
	int counter = 1;
	int fact = 1;

	while (counter <= x) {			//while loop that generates all factorials
		fact = fact * counter;
		newNode = createNode(fact);	//create a new node - function
		addToEnd(ls,newNode);		//add to the end of the list
		counter++;
	}
	return ls;
}

static list createList(void) {
	list l = malloc(sizeof(struct _list));
	l->head = NULL;
	return l;
}

static link createNode(int val) {
	link n = malloc(sizeof(struct _node));
	n->value = val;
	n->next = NULL;
}

static void addToEnd(list l, link n){
   link curr;
   if(l->head == NULL){
       l->head = n;
   } else {
       curr = l->head;
       while(curr->next != NULL){
            curr = curr->next;
       }
       curr->next = n;
   }
}



/* SELECT EVENS PROBLEM
 *
 * Given a list of integers, write a function which
 * finds all even integers and constructs a new list
 * containing these even integers.

 * The original list should be returned by the function.
 * So if the original list is 1->55->66->4->X , the function
 * should return an empty list.

 * Constraints (moveEven sub-problem)
 * - Don't delete any nodes (i.e. do not call free())
 * - The order of integers in the new list should be the same as the original
 * - The original list should remain unmodified
 *
 * Different variations:
 * - 
 * -
 *
 */

list selectEven (list sourceList) {

	list newList = createList();

	list curr = sourceList->head;

	while (curr != NULL) {
		if (curr->value %2 == 0) {
			newNode = createNode(curr->value);
			addToEnd(newList,newNode);
		}
		curr = curr->next;
	}
	return newList;
}

// moveEven subproblem
list moveEven (list sourceList) {
	list newList = createList();	// new list that you're moving old nodes from old list to
	link curr = sourceList->head;	// the current link
	link prev = NULL;				// the previous link

	while (curr != NULL) {
		if (curr->value %2 == 0) {
			if (prev == NULL) {
				sourceList->head = curr->next;
			} else {
				prev->next = curr->next;	// pointing previous' ptr to current->nextPTR's node
			}
			addToEnd(newList,curr);
			curr = nextNode;
		} else {
			prev = curr;
			curr = curr->next;
		}
	}
	return evenList;
}





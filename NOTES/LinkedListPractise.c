// Make a linked list struct - Each node stores an int

typedef struct _node *nodePointer;

typedef struct _node {
	int x;
	nodePointer next;
} node;

// Give a list, which is a circular sorted linked list
// Write a function that inserts a new number into the list
	// PROPERTIES OF THIS LINKED LIST: CIRCULAR + SORTED
	// therefore after inserting new node it must remain same properties

// 1. Create a new node --> addNode(3)
// 2. Go along the list and check each node if it is LESS THAN the node you will insert
// 3. Go along the next node and check if it is GREATER THAN than node you will insert.
// 4. Insert it between the two
// 5. First get (3) and point it to four.
// 6. THEN get (2) and point it to (3).

// EXTRA EXAMPLE: INSERTING (5) INTO THE CIRCULAR LIST
// If it is greater than the node we want to insert + If it's the first thing in the list
	// How to check if it has reached start of the list
	// if (next == listHead && (insert logic for greater than insertNode))

// EXTRA EXAMPLE #2: INSERTING (-1) INTO THE CIRCULAR LIST
// If first item is greater than what you want to insert, point the insertNode to the whole list (rather than a node)
	// Point (-1) to (1)
	// Point (L) to (-1)
	// Point (5) to (-1)

// EXTRA EXAMPLE #3: LIST WITH JUST A HEAD + A NUMBER (5), INSERTING A LARGER NUMBER (6) INSIDE THE LIST
	// 1. The next points to itself
	// 2. The next node is also the first node.
	// 3. Point tne new one (6) to the next one (5).
	// 4. Point the first one (5) to the new one (6).

// EXTRA EXAMPLE #4: LIST WITH NO NODES.
	// Check if head = NULL
	// 

WHAT YOU SHOULD DO FOR INTERVIEWS / EXAMS: LOOK AT EDGE CASES BEFORE YOU START!!!
	// GET THE QN
	// LOOK AT THE PROPERTIES OF THE QN
	// START LOOKING AT EDGE CASES --> Maintain properties of the list

Given a list, singular list, not necessarily sorted, tell me if there is a loop in it or not. (e.g. could be a line, turned into a loop)
	// Find out if there is a loop between you run through it.




/* EXAM NOTES
 *
 * (1) When thinking about linking, think about placing things left -> right path (esp with the equations)
 *	   --> Linking existing node after another one: list->head = newNode
 *	   --> Unless you are declaring a new "link" to begin iteration, then link currentNode = list->head;
 *
 *
 *
 *
 */

// #######################
// # DIFFICULT QUESTIONS #
// #######################

// Concetenate two lists into a new list
List concatenateListIntoNew(List A, List B);

// Concetenate list B into list A
List concatenateListIntoA(List A, List B);

// Split original list into 2 lists: a front + back list. If list is odd, front list gets extra node
void frontBackSplit (list sourceList, list frontList, list backList);

// Weave list
list weavedList(list A, list B);


//Written by Michael Simarta
//With the help of Bernice Chen
//header file for a Linked List structure
//contains functions that can be implemented on a Linked List
 
typedef struct _node* Node;
typedef struct _list* List;
 
 
//returns a new list of length 0
List newList();
 
//frees everything malloced for the list
void destroy(List l);
 
//appends a node of value to the end of the list
void append(List l, int value);
 
//returns the int value of the node at index (indexes start at 0)
//assumes input index is within range of the list's length
int getValue(List l, int index);
 
//find the median of the list
//You can assume that the list is sorted.
//For even sized lists, the median is the average of the two middle elements
 
//CHALLENGE: implement using one traversal of the list only
int median(List l); 
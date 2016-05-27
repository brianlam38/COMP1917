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
void append(List l, char value);
//returns the char value of the node at index
//assumes input index is within range of the list's length
char getValue(List l, int index);
 
//remove all upper case letters from the list
//type "ascii" on the Terminal, it might be useful
void removeUpperCase(List l);

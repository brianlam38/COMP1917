/*
typedef struct _node *nodePtr;

typedef struct _node {
   int      value;
   nodePtr  next;
} node;
*/


typedef struct _node *link;    // a link points to a node
 
typedef struct _node {
    int value;
    link next;
} node;
 
// a list is represented by a pointer to a struct which contains 
// a pointer to the first node of the list called the "head"
typedef struct _list {
    link head;
} *list; 

//int numItems (list l); //implementation of this function is provided
void frontBackSplit (list sourceList, list frontList, list backList);

//void orderedDelete (list l);

//nodePtr frontToBack (nodePtr list);

//list reverse (list inputList);

int numItems (list l); //implementation of this function is provided
//void pairwiseSwap (list l);

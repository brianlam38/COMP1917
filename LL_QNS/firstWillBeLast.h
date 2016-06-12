/*
 *  firstWillBeLast.h
 *  thanks to Matthew
 *  20 13 s1 Practice Prac Exam #2
 *  UNSW comp1917
 *
 *  Created by Richard Buckland
 *  Share freely CC-BY-3.0
 *
 */

typedef struct _node *nodePtr;

typedef struct _node {
   int      value;
   nodePtr  next;
} node;

// given a list of nodes this function takes the node
// from the front of the list and moves it to the end
// of the list  by changing pointers, leaving the relative
// order of the other nodes unchanged.
// note: this function must not create new nodes 
// or change the value field of existing nodes.
nodePtr frontToBack (nodePtr items);

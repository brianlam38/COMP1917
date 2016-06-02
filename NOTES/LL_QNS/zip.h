/*
 *  zip.h
 *
 *  2013s1 Practice Prac Exam #3
 *  UNSW comp1917
 *
 *  Created by Richard Buckland
 *  Share freely CC-BY-3.0
 *
 */

typedef struct _node *list;

typedef struct _node {
   char value;
   list rest;
} node;

// given two equal length list of nodes listA and listB,
// this function "zips" them together into a single
// list - which it returns.   The first node of listA is
// the first node of the output list, and the first node
// listB is the second node of the output list, and the
// second node of listA is the third node of the output
// list, and so on up ubtil the last node of listB which
// is the last node of the output list.
// So zipping A,B,C,D and a,b,c,d would give the list
// A,a,B,b,C,c,D,d
// note: You can assume that the two input lists are of
// exactly the same length
// note: this function must not create new nodes 
// or change the value field of existing nodes.
list zip (list listA, list listB);

// testOrderedDelete.c
// testing orderedDelete() in exam.c
// richard buckland 25 may 2014

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "list-ppexam.h"

// simple unit tests on the list
void testList (void);
void showList (list l);


int main (int argc, char *argv[])  {

    testList();
    printf ("All tests passed.  You are awesome!\n");
    return EXIT_SUCCESS;
}


void testList (void) {

    // test a list with no nodes in it
    printf ("test an empty list\n");
    list myList = malloc (sizeof (*myList));
    assert (myList !=NULL);
    myList->head = NULL;  
    
    printf ("before delete..\n");
    showList (myList);
    orderedDelete (myList);
    printf ("after delete..\n");
    showList (myList);

    assert (myList->head == NULL);  

    // create 10 nodes on the stack 
    node nodes[10];

    // test a list with one node in it
    printf ("test a list containing one node\n");
    myList->head = &nodes[0];
    myList->head->value = 42;
    myList->head->next = NULL;  
    
    printf ("before delete..\n");
    showList (myList);
    orderedDelete (myList);
    printf ("after delete..\n");
    showList (myList);

    assert (myList->head == &nodes[0]);  
    assert (myList->head->value == 42);
    assert (myList->head->next == NULL); 

    printf ("test a list containing three nodes no deletion\n");
    myList->head = &nodes[0];
    nodes[0].value = 7;
    nodes[1].value = 8;
    nodes[2].value = 21;  
    nodes[0].next  = &nodes[1];
    nodes[1].next  = &nodes[2];
    nodes[2].next  = NULL;  
    
    printf ("before delete..\n");
    showList (myList);
    orderedDelete (myList);
    printf ("after delete..\n");
    showList (myList);

    assert (nodes[0].value == 7);
    assert (nodes[1].value == 8);
    assert (nodes[2].value == 21);  
    assert (nodes[0].next  == &nodes[1]);
    assert (nodes[1].next  == &nodes[2]);
    assert (nodes[2].next  == NULL);  

    printf ("test a list containing three nodes b deleted\n");
    myList->head = &nodes[0];
    nodes[0].value = 7;
    nodes[1].value = 6;
    nodes[2].value = 21;  
    nodes[0].next  = &nodes[1];
    nodes[1].next  = &nodes[2];
    nodes[2].next  = NULL;  
    
    printf ("before delete..\n");
    showList (myList);
    orderedDelete (myList);
    printf ("after delete..\n");
    showList (myList);

    assert (nodes[0].value == 7);
    assert (nodes[1].value == 6);
    assert (nodes[2].value == 21);  
    assert (nodes[0].next  == &nodes[2]);
//    assert (nodes[1].next  == &nodes[2]);
    assert (nodes[2].next  == NULL);  

    printf ("test a list containing three nodes c deleted\n");
    myList->head = &nodes[0];
    nodes[0].value = 7;
    nodes[1].value = 26;
    nodes[2].value = 21;  
    nodes[0].next  = &nodes[1];
    nodes[1].next  = &nodes[2];
    nodes[2].next  = NULL;  
    
    printf ("before delete..\n");
    showList (myList);
    orderedDelete (myList);
    printf ("after delete..\n");
    showList (myList);

    assert (nodes[0].value == 7);
    assert (nodes[1].value == 26);
    assert (nodes[2].value == 21);  
    assert (nodes[0].next  == &nodes[1]);
    assert (nodes[1].next  == NULL);
//  assert (nodes[2].next  == NULL);  

    printf ("test a list containing three nodes b+c deleted\n");
    myList->head = &nodes[0];
    nodes[0].value = 7;
    nodes[1].value = 3;
    nodes[2].value = 5;  
    nodes[0].next  = &nodes[1];
    nodes[1].next  = &nodes[2];
    nodes[2].next  = NULL;  
    
    printf ("before delete..\n");
    showList (myList);
    orderedDelete (myList);
    printf ("after delete..\n");
    showList (myList);

    assert (nodes[0].value == 7);
    assert (nodes[1].value == 3);
    assert (nodes[2].value == 5);  
    assert (nodes[0].next  == NULL);
//    assert (nodes[1].next  == NULL);
//  assert (nodes[2].next  == NULL);  

// eg inserting 3 in the list 
//   1->4->2->3->6->6->10->4->X
// would alter the list to become
//   1->4->6->6->10->X
    myList->head   = &nodes[0];
    nodes[0].value = 1;
    nodes[1].value = 4;
    nodes[2].value = 2;  
    nodes[3].value = 3;
    nodes[4].value = 6;
    nodes[5].value = 6;  
    nodes[6].value = 10;
    nodes[7].value = 4;
  
    nodes[0].next = &nodes[1];
    nodes[1].next = &nodes[4];
    nodes[2].next = &nodes[3];  
    nodes[3].next = &nodes[4];
    nodes[4].next = &nodes[5];
    nodes[5].next = &nodes[6];  
    nodes[6].next = &nodes[7];
    nodes[7].next = NULL;

    printf ("before delete..\n");
    showList (myList);
    orderedDelete (myList);
    printf ("after delete..\n");
    showList (myList);

    assert (myList->head   == &nodes[0]);
    assert (nodes[0].value == 1);
    assert (nodes[1].value == 4);
    //assert (nodes[2].value == 2);  
    //assert (nodes[3].value == 3);
    assert (nodes[4].value == 6);
    assert (nodes[5].value == 6);  
    assert (nodes[6].value == 10);
    //assert (nodes[7].value == 4);
  
    assert (nodes[0].next == &nodes[1]);
    assert (nodes[1].next == &nodes[4]);
    //assert (nodes[2].next == &nodes[3]);  
    //assert (nodes[3].next == &nodes[4]);
    assert (nodes[4].next == &nodes[5]);
    assert (nodes[5].next == &nodes[6]);  
    assert (nodes[6].next == NULL);
    //assert (nodes[7].next == NULL);
  
}


void showList (list l) {

    assert (l !=NULL);

    // start at the first node
    link current = l->head;
    while (current != NULL) {
        printf ("[%d] -> ", current->value);
        current = current->next;
    }
    printf ("X\n");
}



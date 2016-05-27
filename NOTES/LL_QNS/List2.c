//Written by Michael Simarta
//With the help of Bernice Chen
//List2.c file that implements all functions declared in List2.h
//implement the removeUpperCase() functions here
 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "List2.h"
 
typedef struct _node {
    char value;
    Node next;
} node;
 
typedef struct _list {
    Node head;
} list;
 
//when the removeUpperCase() function is complete,
//compile with testList2.c, type
//"gcc -Wall -Werror -O -o test testList2.c List2.c"
//to run program, type
//"./test"
 
//TODO
//Read List2.h to help you look at the hints
//remove values which are uppercase
//
//given a list X
//(Empty List)
//then removeUpperCase(list);
//the list is still X
//
//given a list a->X
//then removeUpperCase(list);
//the list is a->X
//
//given a list A->X
//then removeUpperCase(list);
//the list is X
//
//given a list A->a->X
//then removeUpperCase(list);
//the list is a->X
//
//given a list C->a->A->D->X
//then removeUpperCase(list);
//the list is a->X
//
//given a list A->a->B->b->C->c->d->D->E->e->X
//then removeUpperCase(list);
//the list is a->b->c->d->e->X
/*
typedef struct _node* Node;
typedef struct _list* List;
*/

void removeUpperCase(List l) {
    Node current = l->head;
    Node prev = NULL;

    while(current != NULL){

        if(current->value >= 'A' && current->value <= 'Z'){
            Node tmp = current;
            current = current->next;
         
            if (prev == NULL){       // if prev = NULL (the starting case) (should only run once)
                l->head = current; 
            } else {                 // else = set prev->next = current
                prev->next = current;
            }
         
            free(tmp);
         
        } else {
            prev = current;
            current = current->next;
        }
    }
}


//returns a new list of length 0
List newList() {
   List l = malloc(sizeof(list));
   assert ( l!=NULL );
   l->head = NULL;
   return l;
}
 
//frees everything malloced for the list
void destroy(List l) {
   Node curNode = l->head;
   Node prevNode = NULL;
 
   while (curNode != NULL) {
     prevNode = curNode;
     curNode = prevNode->next;
     free(prevNode);
   }
 
   free(l);
}
 
//appends a node of value to the end of the list
void append(List l, char value) {
   Node newNode = malloc(sizeof(node));
   newNode->value = value;
   newNode->next = NULL;
   Node curNode = l->head;
   if ( curNode==NULL ) {
      l->head = newNode;
   } else {
      while ( curNode->next!=NULL ) {
         curNode = curNode->next;
      }
      curNode->next = newNode;
   }
}
 
//returns the int value of the node at index
//assumes input index is within range of the list's length
char getValue(List l, int index) {
 
   Node curNode = l->head;
   assert (curNode!=NULL);
   int counter = 0;
   while (counter<index) {
      curNode = curNode->next;
      counter++;
   }
   return curNode->value;
}







/*  CHRIS ANSWER

// starting with the address of the list,
// move forward
// if between 'A' and 'Z', remove from the list, otherwise, continue as normal
  
    // special list head case
    if (l->head != NULL) {
        Node current = l->head; // so now current points to the first node of the list
        Node endOfList = NULL;

        while ((current->value >= 'A') || (current->value <= 'Z')) {
            current = current->next;
        } // so this while loop will stop with current containing the address of the first node where the char is not UPPER CASE

        l->head = current; // so here, we have officially connected the old list head to the first node which we will not drop
        endOfList = current; // here, current contains the address of the last node in the list

        current = current->next; // here, current contains the address of the node after the one which is last officially in the list

        while (current != NULL) {
            if ((current->value < 'A') && (current->value >'Z')) {
                endOfList->next = current;
                endOfList = current;
            }
        current = current->next;
        }
    }
}
*/



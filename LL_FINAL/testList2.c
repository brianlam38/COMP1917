// Written by Michael Simarta
// With the help of Bernice Chen.
//
//run this testList2.c file with a compilable List2.c
//that should have the functions declared in List2.h implemented
 
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
 
void test_test();
 
void test_removeUpperCase();
 
int main( int argc, char * argv[] ) {
   printf("......STARTING TESTS......\n");
 
   test_test();
   test_removeUpperCase();
 
   printf("ALL TESTS PASSED. YOU ARE AWESOME!\n");
 
   return EXIT_SUCCESS;
}
 
void test_test() {
   List l = newList();
   append(l, 'a');
   append(l, 'B');
   append(l, 'c');
   assert ( getValue(l, 0) == 'a');
   assert ( getValue(l, 1) == 'B');
   assert ( getValue(l, 2) == 'c');
   destroy(l);
 
   printf("EXISTING FUNCTIONS WORK FINE.\n");
}
 
 
//function to test the removeUpperCase() function
void test_removeUpperCase() {
   printf("TESTING removeUpperCase()...\n");
   
   //Empty List
   //Should remain the same
   List l = newList();
   removeUpperCase(l);
   assert (l->head == NULL);
   printf("removeUpperCase Test1 passed.\n");
   destroy(l);
 
   //1 Node list
   //Original: a->X
   //Result: a->X
   l = newList();
   append(l, 'a');
   removeUpperCase(l);
   assert(getValue(l, 0) == 'a');
   assert(l->head->next == NULL);
   destroy(l);
   printf("removeUpperCase Test2 passed.\n");
 
   //1 Node list
   //Original: A->X
   //Result: X
   l = newList();
   append(l, 'A');
   removeUpperCase(l);
   assert(l->head == NULL);
   destroy(l);
   printf("removeUpperCase Test3 passed.\n");
 
   // Original: A->a->X
   // Result: a->X
   l = newList();
   append(l, 'A');
   append(l, 'a');
   removeUpperCase(l);
   assert(getValue(l, 0) == 'a');
   assert(l->head->next == NULL);
   destroy(l);
   printf("removeUpperCase Test4 passed.\n");
 
   // Original: C->a->A->D->X
   // Result: a->X
   l = newList();
   append(l, 'C');
   append(l, 'a');
   append(l, 'A');
   append(l, 'D');
   removeUpperCase(l);
   assert(getValue(l, 0) == 'a');
   assert(l->head->next == NULL);
   destroy(l);
   printf("removeUpperCase Test5 passed.\n");
 
   // Original: A->a->B->b->C->c->d->D->E->e->X
   // Result: a->b->c->d->e->X
   l = newList();
   append(l, 'A');
   append(l, 'a');
   append(l, 'B');
   append(l, 'b');
   append(l, 'C');
   append(l, 'c');
   append(l, 'd');
   append(l, 'D');
   append(l, 'E');
   append(l, 'e');
   removeUpperCase(l);
   assert(getValue(l, 0) == 'a');
   assert(getValue(l, 1) == 'b');
   assert(getValue(l, 2) == 'c');
   assert(getValue(l, 3) == 'd');
   assert(getValue(l, 4) == 'e');
   assert(l->head->next->next->next->next->next == NULL);
   destroy(l);
   printf("removeUpperCase Test6 passed.\n");
}

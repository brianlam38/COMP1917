/*
 *  testFirstWillBeLast.h
 *  concept thanks to Matthew
 *  20 13 s1 Practice Prac Exam #2
 *  UNSW comp1917
 *
 *  Created by David Collien & Richard Buckland
 *  Share freely CC-BY-3.0
 *
 *  this program runs a simple test for moving the
 *  first element of a list to the end of the list
 *  by changing pointers.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "firstWillBeLast.h"

#define FIRST  1
#define SECOND 2
#define THIRD  3
#define FOURTH 4
#define FIFTH  5
#define SIXTH  6

void testFrontToBack (void);

int main (int argc, char *argv[]) {
   printf ("Running unit tests on frontToBack()...\n");
   testFrontToBack();
   printf ("All PRAC EXAM tests passed! You are AWESOME!\n");
   
   return EXIT_SUCCESS;
}

void testFrontToBack (void) {

   nodePtr inputList;
   nodePtr outputList;
   
   node first;
   node second;
   node third;
   node fourth;
   node fifth;
   node sixth;
   
   first.value = FIRST;
   second.value = SECOND;
   third.value = THIRD;
   fourth.value = FOURTH;
   fifth.value = FIFTH;
   sixth.value = SIXTH;

   
   printf ("TEST 1: testing frontToBack on an empty list...\n");
   inputList = NULL;
   outputList = frontToBack(inputList);
   assert (outputList == NULL);
   printf ("... TEST 1 passed!\n");
   
   
   
   printf ("TEST 2: testing frontToBack on a single item list...\n");
   
   inputList = &first;
   first.next = NULL;
   
   outputList = frontToBack (inputList);
   assert (outputList == &first);
   assert (outputList->value == FIRST);
   assert (outputList->next == NULL);
   
   printf ("... TEST 2 passed!\n");
   
   
   
   printf ("TEST 3: testing frontToBack on double item list...\n");
   
   inputList = &first;
   first.next = &second;
   second.next = NULL;
   
   outputList = frontToBack (inputList);
   assert (outputList == &second);
   
   assert (outputList->value == SECOND);
   assert (outputList->next == &first); // 9
   
   assert (outputList->next->value == FIRST);
   assert (outputList->next->next == NULL);
   
   printf ("... TEST 3 passed!\n");

   

   printf ("TEST 4: testing frontToBack on 6 item list...\n");

   // input list is first->...->sixth->NULL
   inputList = &first;
   first.next = &second;
   second.next = &third;
   third.next = &fourth;
   fourth.next = &fifth;
   fifth.next = &sixth;
   sixth.next = NULL;

   outputList = frontToBack (inputList);
   // after moving front to back the output list should be
   // second->third->...sixth->first;
   
   
   printf ("   test that the links are correct\n" );
   
   assert (outputList  == &second);
   assert (second.next == &third);
   assert (third.next  == &fourth);
   assert (fourth.next == &fifth);
   assert (fifth.next  == &sixth);
   assert (sixth.next  == &first);
   assert (first.next  == NULL);

   printf ("   YES, links are correct\n" );

   printf ("   test that node values have not been changed\n" );

   assert(first.value  == FIRST);
   assert(second.value == SECOND);
   assert(third.value  == THIRD);
   assert(fourth.value == FOURTH);
   assert(fifth.value  == FIFTH);
   assert(sixth.value  == SIXTH);

   printf ("   YES, node values have not been changed\n" );

   printf ("... TEST 4 passed!\n");
   
   
   
   
}

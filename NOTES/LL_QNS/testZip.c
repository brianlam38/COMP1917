/*
 *  testZip.h
 *  
 *  2013 s1 Practice Prac Exam #2
 *  UNSW comp1917
 *
 *  Created by Richard Buckland
 *  Share freely CC-BY-3.0
 *
 *  this program runs a simple test for interleaving
 *  "zipping" two lists of equal length into a single
 *  combined list, by changing pointers.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "zip.h"

#define FIRST_A  'A'
#define SECOND_A 'B'
#define THIRD_A  'C'
#define FIRST_B  'a'
#define SECOND_B 'b'
#define THIRD_B  'c'

#define BIG_TEST_SIZE 10

void testZipNull (void);
void testZipSingletons (void);
void testZipTwo (void);
void testZip10 (void);

int main (int argc, char *argv[]) {
   printf ("Running unit tests on zip()...\n");
   testZipNull ();
   testZipSingletons ();
   testZipTwo ();
   testZip10 ();
   printf ("All PRAC EXAM tests passed! You are AWESOME!\n");
   
   return EXIT_SUCCESS;
}


void testZipNull (void) {
   
   printf ("TEST 1 (Null): testing zip on two empty lists...\n");
   
   list zipped = zip (NULL, NULL);
   assert (zipped == NULL);
   printf ("TEST 1 (null) passed!\n");
   
}

void testZipSingletons (void) {

   printf ("TEST 2 (singletons): testing zip on two single elt lists...\n");
   node nodeA0 = {FIRST_A, NULL};
   node nodeB0 = {FIRST_B, NULL};
   list listA = &nodeA0;
   list listB = &nodeB0;
   
   list zipped = zip (listA, listB);
   assert (zipped != NULL);
   assert (zipped == &nodeA0);
   assert (zipped->value == FIRST_A);
   
   assert (zipped->rest == &nodeB0);
   assert (zipped->rest->value == FIRST_B);

   assert (zipped->rest->rest == NULL);
   printf ("TEST 2 (singletons) passed!\n");
   
}

void testZipTwo (void) {
   
   printf ("TEST 3 (twos): testing zip on two 2-element lists...\n");
   node nodeA1 = {SECOND_A, NULL};
   node nodeB1 = {SECOND_B, NULL};
   node nodeA0 = {FIRST_A, &nodeA1};
   node nodeB0 = {FIRST_B, &nodeB1};
   
   list listA = &nodeA0;
   list listB = &nodeB0;
   
   list zipped = zip (listA, listB);
   assert (zipped != NULL);
   assert (zipped == &nodeA0);
   assert (zipped->value == FIRST_A);
   
   assert (zipped->rest == &nodeB0);
   assert (zipped->rest->value == FIRST_B);
   
   assert (zipped->rest->rest == &nodeA1);
   assert (zipped->rest->rest->value == SECOND_A);
   
   assert (zipped->rest->rest->rest == &nodeB1);
   assert (zipped->rest->rest->rest->value == SECOND_B);
   
   assert (zipped->rest->rest->rest->rest == NULL);
   printf ("TEST 3 (twos) passed!\n");
   
}

void testZip10 (void) {
   printf ("TEST 4 (10s): testing zip on two 10-element lists...\n");
   printf (" ... create the nodes\n");
   
   node nodes[BIG_TEST_SIZE*2];  // enough nodes for two lists
   
   // connect and put values 'A'..'J' in the first list
   // (first list is stored in even numbered nodes)   
   int place = 0;
   while (place<BIG_TEST_SIZE) {
      int location = place*2;
      nodes[location].value = 'A'+place;
      if (place == (BIG_TEST_SIZE-1)) {
         // the final node has a null next pointer
         nodes[location].rest = NULL;
      } else {
         // otherwise points to the node two places on
         // (as the list is of the even numbered nodes
         // so only contains every second node)
         nodes[location].rest = &nodes[location+2];
      }
      place++;
   }
   
   // connect and put values 'a'..'j' in the second list
   // (second list is stored in odd numbered nodes)
   place = 0;
   while (place<BIG_TEST_SIZE) {
      int location = place*2 + 1;  //+1 for odd numbers
      nodes[location].value = 'a'+place;
      if (place == (BIG_TEST_SIZE-1)) {
         // the final node has a null next pointer
         nodes[location].rest = NULL;
      } else {
         // otherwise points to the node two places on
         // (as the list is of the even numbered nodes
         // so only contains every second node)
         nodes[location].rest = &nodes[location+2];
      }
      place++;
   }
   
   
   printf (" ... call zip()\n");
   list listA = &nodes[0];
   list listB = &nodes[1];
   list zipped = zip(listA, listB);
   
   printf (" ... test links are correct\n");
   assert (zipped == &nodes[0]);
   
   // all nodes should point to the next node
   int i = 0;
   while (i < (BIG_TEST_SIZE*2 - 1)) {
      assert (nodes[i].rest == &nodes[i+1]);
      i++;
   }
   // final node terminated by NULL
   assert (nodes[BIG_TEST_SIZE*2 - 1].rest == NULL);
   
   
   printf (" ... check that values have not been changed\n");
   printf ("        should be \"AaBbCcDdEeFfGgHhIiJj\"\n");
   printf ("        yours are \"");   
   i=0;
   while (i < BIG_TEST_SIZE*2) {
      printf ("%c", nodes[i].value);
      if ((i%2) == 0) {
         assert (nodes[i].value == ('A'+i/2));
      } else {
         assert (nodes[i].value == ('a'+i/2));
      }
      i++;
   }
   printf ("\"\n");
   printf ("TEST 4 (10s): passed!\n");
}

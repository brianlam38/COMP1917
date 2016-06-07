/*  testReverseList implementation
 *  2013s1 Practice Prac Exam #1
 *  UNSW comp1917
 *
 *  Created by Richard Buckland
 *  Share freely CC-BY-3.0
 *
 */
//
// this program runs a simple test on a reverse

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "reverseList.h"

#define FIRST   42
#define SECOND  0
#define THIRD   21
#define FOURTH  0xBEA
                      //R

void testReverse (void);
void testReverseEmpty (void);
void testReverseOne (void);
void testReverseTwo (void);
void testReverseThree (void);

int main (int argc, const char * argv[]) {
   testReverse();
   return EXIT_SUCCESS;
}

void testReverse (void) {

   printf ("Testing reverse.\n");
   testReverseEmpty();
   testReverseOne();
   testReverseTwo();
   testReverseThree();
   printf ("\n");
   printf ("All tests passed.  You are Awesome!\n");
}


void testReverseEmpty (void) {
   printf ("testing reverse an empty list ...\n");
   assert (reverse (NULL) == NULL);
   printf ("passed\n");
}

void testReverseOne (void) {
   printf ("testing reverse a list of size 1...\n");
   // create a simple list on the stack
   node first;

   list inputList = &first;
   list outputList;

   first.value = FIRST;
   first.rest  = NULL;

   printf ("...checking output list is reversed ...\n");
   outputList = reverse (inputList);

   assert (outputList == &first);
   assert (outputList->rest == NULL);

   printf ("...checking node values are not altered\n");
   assert (first.value  == FIRST);

   printf ("...passed\n");

}

void testReverseTwo (void) {
   printf ("testing reverse a list of size 2...\n");
   // create a simple list on the stack
   node first;
   node second;

   list inputList = &first;
   list outputList;

   first.value = FIRST;
   first.rest  = &second;

   second.value = SECOND;
   second.rest  = NULL;

   printf ("...checking output list is reversed ...\n");
   outputList = reverse (inputList);

   assert (outputList == &second);
   assert (outputList->rest == &first);
   assert (outputList->rest->rest == NULL);

   printf ("...checking node values are not altered\n");
   assert (first.value  == FIRST);
   assert (second.value == SECOND);

   printf ("...passed\n");

}

void testReverseThree (void) {
   printf ("testing reverse a list of size 3...\n");
   // create a simple list on the stack
   node first;
   node second;
   node third;

   list inputList = &first;
   list outputList;

   first.value = FIRST;
   first.rest  = &second;

   second.value = SECOND;
   second.rest  = &third;

   third.value = THIRD;
   third.rest  = NULL;

   printf ("...checking output list is reversed ...\n");
   outputList = reverse (inputList);

   assert (outputList == &third);
   assert (outputList->rest == &second);
   assert (outputList->rest->rest == &first);
   assert (outputList->rest->rest->rest == NULL);

   printf ("...checking node values are not altered\n");
   assert (first.value  == FIRST);
   assert (second.value == SECOND);
   assert (third.value  == THIRD);

   printf ("...passed\n");

}


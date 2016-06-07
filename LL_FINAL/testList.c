// Written by Michael Simarta
// With the help of Bernice Chen.
//
//run this testList.c file with a compilable List.c
//that should have the functions declared in List.h implemented 
 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "List.h"
 
 
void test_test();
 
void test_median();
 
int main( int argc, char * argv[] ) {
   printf("......STARTING TESTS......\n");
 
   test_test();
   test_median();
 
   printf("ALL TESTS PASSED. YOU ARE AWESOME!\n");
 
   return EXIT_SUCCESS;
}
 
void test_test() {
   List l = newList();
   append(l, 0);
   append(l, 1);
   append(l, 2);
   assert ( getValue(l, 0) == 0);
   assert ( getValue(l, 1) == 1);
   assert ( getValue(l, 2) == 2);
 
   printf("EXISTING FUNCTIONS WORK FINE.\n");
}
 
 
//function to test the median() function
void test_median() {
   printf("TESTING median()...\n");
   
   //Empty List
   // median is 0
   List l = newList();
   assert(median(l) == 0);
   printf("median Test1 passed.\n");
   destroy(l);
 
   //1 Node list
   // median is 1
   l = newList();
   append(l, 1);
   assert(median(l) == 1);
   printf("median Test2 passed.\n");
   
   // 0->1->2->X
   // median(l) = 1
   l = newList();
   append(l, 0);
   append(l, 1);
   append(l, 2);
   assert ( median(l) == 1 );
   destroy(l);
   printf("median Test3 passed.\n");
 
   // 2->3->5->6->X
   // median(l) = 4
   l = newList();
   append(l, 2);
   append(l, 3);
   append(l, 5);
   append(l, 6);
   assert(median(l) == 4);
   printf("median Test4 passed.\n");
 
   // 2->3->5->6->1000->X
   // median(l) = 5
   append(l, 1000);   
   assert(median(l) == 5);
   printf("median Test5 passed.\n");
   destroy(l);
}

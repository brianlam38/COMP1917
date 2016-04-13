//
//  main.c
//  memory
//
//  Created by Richard Buckland on 20/11/12.
//
 
#include <stdio.h>
#include <stdlib.h>
 
long add (int x, int y);
 
int main(int argc, const char * argv[]) {
 
   int x;
   int y;
   long total;
 
   x = 40;
   y = 2;
 
   total = add (x, y);

   char c ='a';
 
   printf("the sum of %d and %d is %ld\n", x, y, total);
   printf("the size of char is %lu\n", sizeof(c));
 
   unsigned long ul       = 100000000;
      printf("the size of ul is %lx\n", sizeof(ul));
   unsigned int ui        = 9;
      printf("the size of ui is %x\n", sizeof(ui));
   unsigned long long ull = 20000000000000000;
      printf("the size of ull is %llx\n", sizeof(ull));
   unsigned short us      = 3;
      printf("the size of us is %u\n", sizeof(us));
 
   signed long sl       = 4000000;
      printf("the size of sl is %ld\n", sizeof(sl));
   signed int si        = 5;
      printf("the size of si is %d\n", sizeof(si));
   signed long long sll = 6000000000000000;
      printf("the size of sll is %lld\n", sizeof(sll));
   signed short ss      = 7;
      printf("the size of ss is %d", sizeof(ss));

/*
 
   long l       = 80000000;
      printf("the size of l is %ld\n", sizeof(l));
   int i        = 9;
      printf("the size of i is %d\n", sizeof(i));
   long long ll = 100000000000000000;
      printf("the size of ll is %ld\n", sizeof(ll));
   short s      = 1;
      printf("the size of s is %d\n", sizeof(s));
 
   float f = 3.1;
      printf("the size of float is %f\n", sizeof(f));
   double d = 3.14;
      printf("the size of double is %f\n", sizeof(d));
 
   // add them all together just to make use of them so the compiler
   // doesn't grumble that they are unused in the program
 
   double grandTotal;
   grandTotal =  c +
                 ul + ui + ull + us +
                 sl + si + sll + ss +
                  l +  i +  ll +  s +
                  f + d;
 
   printf ("all these things added together make %f\n", grandTotal);
 
   return EXIT_SUCCESS;
}
 
long add (int x, int y) {
   long answer;
   answer = x + y;
 
   return answer;
}
 
 
 
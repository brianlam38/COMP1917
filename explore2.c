//
//  main.c
//  memory
//
//  Created by Richard Buckland on 20/11/12.
//
 
#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#include<float.h> 
long add (int x, int y);
 
int main(int argc, const char * argv[]) {
 
   int x;
   int y;
   long total;
 
   x = 1;
   y = 2;
   int *address;
   address = &x; 
   total = add (x, y);
 
   printf("the sum of %d and %d is %ld\n", x, y, total);
   printf("the size of int %ld\n",sizeof(x));
   printf("the address of x is %p\n" , &x);
   printf("the address of y is %p\n" , &y);

   char c ='a';
   printf("the size of char c %ld\n",sizeof(c));
   printf("the address of c is %p\n" , &c);
 
   unsigned long ul = 0;
   printf("the size of unsigned long ul is  %ld\n",sizeof(ul));
   printf("the address of ul is %p\n" , &ul);

  
   unsigned int ui = 1;
   printf("the size ofunsgined int ui is  %ld\n",sizeof(ui));
   printf("the address of ui is %p\n" , &ui);


   unsigned long long ull = 2;
   printf("the size of long long ull is %ld\n",sizeof(ull));
   printf("the address of ull is %p\n" , &ull);
   

   unsigned short us = 3;
   printf("the size of unsigned short us is %ld\n",sizeof(us));
   printf("the address of us is %p\n" , &us);

   signed long sl = 4;
   printf("the size of signed long sl is %ld\n",sizeof(sl));
   printf("the address of sl is %p\n" , &sl);
  

   signed int si = 5;
   printf("the size of signed int si is %ld\n",sizeof(si));
   printf("the address of si is %p\n" , &si);

   signed long long sll = 6;
   printf("the size ofsingned long long sll is  %ld\n",sizeof(sll));
   printf("the address of sll is %p\n" , &sll);
  
   signed short ss = 7;
   printf("the size of signed short ss is %ld\n",sizeof(ss));
   printf("the address of ss is %p\n" , &ss);
 

   long l = 8;
   printf("the size of long l is %ld\n",sizeof(l));
   printf("the address of l is %p\n" , &l);
  
   
   int i = 9;
   printf("the size of int i is %ld\n",sizeof(i));
   printf("the address of i is %p\n" , &i);


   long long ll = 10;
   printf("the size of long long ll  %ld\n",sizeof(ll));
   printf("the address of ll is %p\n" , &ll);


   short s = 11;
   printf("the size of short s is %ld\n",sizeof(s));
   printf("the address of s is %p\n" , &s);
 

   float f = 3.1;
   printf("the size of float f is %ld\n",sizeof(f));
   printf("the address of f is %p\n" , &f);

   double d = 3.14;
   printf("the size of double d is  %ld\n",sizeof(d));
    printf("the address of d is %p\n" , &d);

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

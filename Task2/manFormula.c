//This is a template for programming in c
//template.c
//by: Daniel Shougam z5114053	
//date: whatever the date is

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mandelbrotTest.c"

typedef struct _complexNum ComplexNum;

struct _complexNum{
   double re;
   double im;
   double mod;
};

int escapeSteps(double re, double im);
int calculateMod(double re, double im);

int main(int argc, char* argv[]){

   testEscapeSteps();

   ComplexNum number;
   number.im = 0;
   number.re = 0;

   printf("Enter a point \n");
   scanf("%lf %lf", &number.re, &number.im);
   printf("You picked the point: (%lf + %lfi)\n", number.re, number.im);

   printf("Steps taken %d\n", escapeSteps(number.re, number.im));

   return EXIT_SUCCESS;
}

int escapeSteps(double re, double im){

   ComplexNum original;
   original.re = re;
   original.im = im;
   original.mod = calculateMod(original.re, original.im);
   ComplexNum old = original;
   ComplexNum new;
   new.re = 0;
   new.im = 0;
   new.mod = 0;
   int steps = 1;
      while (new.mod < 2){
         if (original.mod >= 2){
            return steps;
         }
         new.re = (old.re*old.re) - (old.im*old.im) + original.re;
         new.im = (2*old.re*old.im) + original.im;
         printf("I am here\n");
         new.mod = calculateMod(new.re, new.im);
         steps++;
         printf("The Original one is: %lf %lfi\n", original.re, original.im);
         printf("The Old one is: %lf %lfi\n", old.re, old.im);
         printf("The new one is: %lf %lfi\n", new.re, new.im);
         if (steps == 256){
            return steps;
         }
         old = new;
   }
   return steps;
}

int calculateMod(double re, double im){
   double modulus = 0;
   modulus = sqrt((re * re) + (im * im));
   return modulus;
}

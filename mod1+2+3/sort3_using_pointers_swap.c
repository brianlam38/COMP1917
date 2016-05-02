#include <stdio.h>
#include <stdlib.h>

void sort();							// declaring sort()

int main(int argc, char * argv[]) {
	int a, b, c; 						// declaring variables a, b, c

	scanf ("%d %d %d", &a, &b, &c);		// scanning in values, assigning to variables

	sort(&a, &b, &c);					// sort function

	printf ("%d\n%d\n%d\n", a, b, c);	// printing sorted result

	return EXIT_SUCCESS;
}

void sort(int *a, int *b, int *c) {		// void function, doesn't return anything for use
   int swap;							// declaring swap int variable
   
   if (*a > *b) {						//
      swap = *a;
      *a = *b;
      *b = swap;
   }
   
   if (*b > *c) {
      swap = *b;
      *b = *c;
      *c = swap;
   }
   
   if (*a > *b) {
      swap = *a;
      *a = *b;
      *b = swap;
   }
}
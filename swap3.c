/*
  Brian Lam & David Reisenberg
  Brian Lam
  z5035087
  Tutor: Jordan Brown
  Kora Wednesday
  Date : 23/3/2016
  Swaps two integers with pointers.
*/

#include <stdio.h>
#include <stdlib.h>

// Declares swap function
void swap(int *first, int *second);

int main(int argc, char * argv[]) {
// Declaring int "first" and "second"
	int first;
	int second;

// Asking user to assign integer to variable "first"
	printf ("Enter the first number:\n");
	scanf ("%d", &first);

// Asking user to assign integer to variable "second"
	printf ("Enter the second number:\n");
	scanf ("%d", &second);

// Prints UNSWAPPED numbers
	printf ("UNSWAPPED two numbers are first = %d, second = %d\n", first, second);

// Calls swap function and prints SWAPPED numbers
	swap(&first, &second);
	printf ("SWAPPED two numbers are first = %d, second = %d\n", first, second);

	return EXIT_SUCCESS;
}
// Function to swap two integers using POINTERS
void swap(int *first, int *second) {
	int temp;
	temp = *first;
	*first = *second;
	*second = temp;
}
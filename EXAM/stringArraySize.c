#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char stringArray[] = "Four";
	printf("The array has a size of %lu elements\n\n", sizeof(stringArray));
	// ANSWER: The array has a size of 5 elements
	// NOTE: You can't use sizeof() function on pointers to arrays

}
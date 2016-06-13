#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int x = 1;
	int *xPointer = &x;
	//char * kar = (char) x;

	printf("*xPointer = value %d\n\n", *xPointer);
	printf("address of xPointer = %p\n", &xPointer);
	printf("xPointer = address %p\n", xPointer);
	printf("address of x = address %p", &x);

	return EXIT_SUCCESS;
}
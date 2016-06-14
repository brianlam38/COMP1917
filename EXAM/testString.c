#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	char str1[] = "hello";
	char *stringPtr = str1;

	printf ("%c\n", *stringPtr);
	printf ("%p\n", &stringPtr);

	/*
	if (str1 == str2) {
   		printf ("equal\n");
	} else {
   		printf ("not equal\n");
	}
	*/
	return EXIT_SUCCESS;
}
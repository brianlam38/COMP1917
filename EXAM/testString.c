#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	char str1[] = "hello";
	char str2[] = "hello";

	printf ("%p\n", str1);
	printf ("%p", str2);

	/*
	if (str1 == str2) {
   		printf ("equal\n");
	} else {
   		printf ("not equal\n");
	}
	*/
	return EXIT_SUCCESS;
}
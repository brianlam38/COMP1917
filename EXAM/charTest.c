#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

	char *string = "abc";
	char string1[4] = "abc";

	printf("%c", string[2]);
	printf("%lu\n", sizeof(string));

	printf("%lu\n", sizeof(string1));
	//printf("%s", string);


	return EXIT_SUCCESS;
}
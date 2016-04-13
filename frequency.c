#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // Including for "tolower" function

int main(int argc, char * argv[]) {
	int count[256]; // Declaring array of size 256
	char c; // Declaring variable "c" as a char type
	while ((c = getchar()) != EOF) { // While standard in (continually take in input character by character), until the end of file
		c = tolower(c); // Changes character to lower case
		int x = 'a';
		count[x]++;
	}

	int i = 'a';
	while (i <= 'z') {
		printf ("%c = %d\n", i, count[i]);
		i++;
	}
	
	return EXIT_SUCCESS;
}


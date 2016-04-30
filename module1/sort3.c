#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
	int first, second, third; 

	printf ("Enter the first number: \n");
	scanf ("%d", &first);

	printf ("Enter the second number: \n");
	scanf ("%d", &second);

	printf ("Enter the third number: \n");
	scanf ("%d", &third);

	/* SCANF TEST
	printf ("%d\n%d\n%d\n", first, second, third);	
	*/
	printf ("Your numbers assorted in ascending order: \n");
	if (first < second < third) {						// First case
		printf ("%d\n%d\n%d\n", first, second, third);
	} else if (first < third < second) {
		printf ("%d\n%d\n%d\n", first, third, second);
	} else if (second < first < third) {				// Second case
		printf ("%d\n%d\n%d\n", second, first, third);
	} else if (second < third < first) {
		printf ("%d\n%d\n%d\n", second, third, first);
	} else if (third < first < second) {				// Third case
		printf ("%d\n%d\n%d\n", third, first, second);
	} else if (third < second < first) {
		printf ("%d\n%d\n%d\n", third, second, first);
	}
	return EXIT_SUCCESS;
}





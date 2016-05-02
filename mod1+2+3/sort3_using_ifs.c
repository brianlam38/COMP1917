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

	if (first < second && first < third) {				// First case
		printf ("%d\n", first);
		if (second < third) {
			printf ("%d\n%d\n", second, third);
		} else {
			printf ("%d\n%d\n", third, second);
		}
	} else if (second < first && second < third) {		// Second case
		printf ("%d\n", second);
		if (first < third) {
			printf ("%d\n%d\n", first, third);
		} else {
			printf ("%d\n%d\n", third, first);
		}
	} else if (third < first && third < second) {		// Third case
		printf ("%d\n", third);
		if (first < second) {
			printf ("%d\n%d\n", first, second);
		} else {
			printf ("%d\n%d\n", second, first);
		}
	}
	return EXIT_SUCCESS;
}





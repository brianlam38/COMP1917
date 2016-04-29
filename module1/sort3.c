#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
	int first, second, third; 
	printf ("Enter three numbers: \n");
	scanf ("%d %d %d", &first, &second, &third);

	/* Testing scanf */
	printf ("%d\n%d\n%d\n", first, second, third);

	if (first < second < third) {						// First case
		printf ("%d\n%d\n%d\n", first, second, third);
	} else if (first < third < second) {
		printf ("%d\n%d\n%d\n", first, second, third);
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
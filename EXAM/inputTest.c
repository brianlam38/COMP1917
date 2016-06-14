#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char *argv[]) {
	int n;
	int count = 0;

	scanf("%d", &n);
	assert((n >= 1) && (n <= 1000000));

	while ((n%2) != 1) {
		n = n / 2;
		count++;
	}
	printf("The number of times halved = %d", count);

	return EXIT_SUCCESS;
}
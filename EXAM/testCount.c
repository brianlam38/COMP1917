#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int count = 10;
	int other = 0;
	int *temp = &count;

	*temp = 20;
	printf("*temp = %d\n", *temp);
	temp = &other;
	printf("temp = %p\n", &other);
	*temp = count;
	printf("other = %d\n\n", other);

	printf("count = %d, *temp = %d, other = %d\n", count, *temp, other);
}
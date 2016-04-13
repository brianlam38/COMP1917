#include <stdio.h>
#include <stdlib.h>

int swap(int x, int y); //This is a function prototype. It lets code know that the function is defined further down.

int main(int argc, char * argv[]) {
	int x = 1;
	int y = 2;

	printf("x is %d\n y is %d\n", x, y);
	swap(x, y);

	float 	a = 3.0;
	float b = 43.0;

	double c = 3.0;
	double d = 43.0;

	printf("%.20f\n", a/b);
	printf("%.20lf\n", c/d);


	return EXIT_SUCCESS;
}

int swap(int x, int y) {
	int z = x;

	x = y; //x = 1 --> 2
	y = z; //y = 2 --> 1
	printf("x is %d\n y is %d\n", x, y);
	return EXIT_SUCCESS;
}
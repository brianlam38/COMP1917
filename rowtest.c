#include <stdio.h>
#include <stdlib.h>
#define WIDTH 15
#define HEIGHT 5

int main(int argc, char * argv[]) { // Main program
	int col = 0; // Defining + Initialising var
	int row = 0; // Defining + Initialising var

	while (row < HEIGHT) { // While loop for ROW
		col = 0;
		while (col < WIDTH) { // While loop within While loop for COL
			printf ("*");
			col++; // Implementing progression for COL
		}
		printf ("\n");
		row ++; // Implementing progression for ROW
	}
	return EXIT_SUCCESS;
}

// This program successfully prints out 15 columns x 5 rows of stars.

## test message
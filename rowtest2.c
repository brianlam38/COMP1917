/*
	FLAG OF IRELAND

	This program prints out the flag of Ireland
	BRIAN LAM
	31/3/16

	Practising the use of NESTED LOOPS / IF STATEMENTS

	The flag of Ireland is made up of GREENS, WHITES, ORANGES (R,W,O respectively)
*/

#include <stdio.h>
#include <stdlib.h>
#define WIDTH 15
#define HEIGHT 5

int main(int argc, char * argv[]) { // Main function

	int col = 0; // Declaring & Initialising variable #1
	int row = 0; // Declaring & Initialising variable #2

	while (row < HEIGHT) {
		col = 0;
		while (col < WIDTH) {
		if (col >= 0 && col < 5) {
			printf ("G");
		} else if (col > 5 && col < 10) {
			printf ("W");
		} else if (col > 10 && col < 15) {
			printf ("O");
		}
			col++;
		}
		row++;
		printf ("\n");
	}
	return EXIT_SUCCESS;
}

// Use VARIABLES in your IF STATEMENTS, if you are trying to find something that changes.
	// I.e. using COL instead of WIDTH
// Only use the #DEFINE CONSTANTS if you are testing against one thing.

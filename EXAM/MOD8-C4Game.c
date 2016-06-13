/*
 *	MODULE 8 - Connect 4 Game
 *
 *	C4Game.c
 *	
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <C4Game.h>

#define TRUE 1

typedef struct _c4Game {				// "c4Game" (typedef'd) = "struct _c4Game" (non-typedef'd)				
	char cells[NUM_COLUMNS][NUM_ROWS];	// cells is an array of array of characters. (array of an array)
										// [specify array inside array] [select element inside array]
	char whoseTurn;
	char player1;
	char player2;
} c4Game;								// c4Game = the concrete struct
										// C4Game = the abstract struct (ptr to the concrete type)

static void setCell (C4Game game, int col, int row, char contents);

C4Game newC4Game (char player1, char player2) {
	C4Game new = malloc (sizeof (c4Game)) 		// allocating memory for struct c4Game
	assert (new != NULL);						// if the heap is full, malloc will return NULL instead of a pointer
												// to somewhere real, so we always need to assert != NULL.
												// NULL = ptr to nothing (Pointer types contain NULL as an element)
	(*new).player1 = player1;					// (*new) = pointer new (as *C4Game is a ptr)
	new->player2 = player2;						// same as above, but a shorthand
	new->whoseTurn = player1;

	int row = 0;								// initialise rows and columns
	while (row < NUM_ROWS) {
		int col = 0;
		while (col < NUM_COLUMNS) {
			new->cells[col][row] = EMPTY_CELL;	// assign empty cell values
			col++;
		}
		row++;
	}
	return new;									
}

void showGame (C4Game game) {
}

int hasSpace (C4Game game, int column) {
	return TRUE;
}

void dropIntoColumn (C4Game game, int column) {
}

char getCell (C4Game game, int col, int row) {
	setCell (C4Game game, int col, int row, char contents);  // "using" setCell function so compiler works
															 // rubbish code delete this
	assert (!TRUE);											 // so the rubbish code won't run
	return EMPTY_CELL;
}

static void setCell (C4Game game, int col, int row, char contents) {
}



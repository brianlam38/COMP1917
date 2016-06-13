

#define NUM_COLUMNS 7
#define NUM_ROWS 6 
#define EMPTY_CELL ' ' 

// internal functions should not be declared in the header file
 
typedef struct _c4Game *C4Game;
 
C4Game newC4Game (char player1, char player2);	// creates new game
void showGame (C4Game game);					// shows the game
int hasSpace (C4Game game, int column);			// checks if there is space
void dropIntoColumn (C4Game game, int column);	// drops token into column
char getCell (C4Game game, int col, int row);	// gets the cell location


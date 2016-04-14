/*
LECTURE 11 - TIME MANAGEMENT
	Think about the most important things of the day that you need to do + do them first!
	Making one mistake --> mistake can be compounded.
		How to solve this: "sit on your hands" for about 60 seconds before you make a move.
	Task 1 is due soon
		Use the stress well. Think carefully, plan carefully and spend extra time on it.
		Don't respond to stress badly / forgetting the most important things
		Think carefully when approaching task one
		HARDEST THING IF YOU DON'T KNOW HOW TO PROGRAM = Managing your emotions / mental state.
		Art of Programming = notion of being CALM / RELAXED / RIDING THE STRESS / NOT LETTING STRESS OVERCOME YOU
*/

/////////////////////////////////////////////////////////////////////////////////////////////

/*
LECTURE 12 - FUNCTIONS PT 1.
	Lecture examples on TYPES and VARIABLES
*/

// PROGRAM DESIGN DECISION:
	// Should I read it in MAIN and parse it in?
	// Or should I read it in the inner function?
	// GENERALLY: Whats the SCOPE of this variable for me?
		// Does it only have meaning inside this function? --> If so, just read it in the function
		// Or do I need to use it several times? --> Read it in a higher function, then parse it into subfunctions

// One method to see where your errors are at, is to COMMENT OUT
// an entire chunk of code to pinpoint the location of your error.

#include <stdio.h>
#include <stdlib.h> //We are including stdlib.h so we can use "EXIT_SUCCESS"

// Declaring the functions (function prototype)
void exampleOne(void);
void exampleDouble(void);
void exampleHex(void);

int main(int argc, char * argv[]) {
	printf ("Lecture 3 examples!\n");

/* Defining a function in MAIN / parsing the height in
// You will receive an error "too many arguments to function exampleDouble"
// due to the exampleDouble(void)

	double height;
	height = 2.31;
	exampleDouble(height);
*/

	exampleOne();
	exampleHex();

	printf ("EXIT_SUCCESS is %d\n", EXIT_SUCCESS); //This prints out what EXIT_SUCESS is, so we know what it is

	int x;
	x = 1234; //How is "1234" stored? --> Break it into TWO DIGIT NUMBERS
//Example 2 of storing values
	x = 12345678901; //WARNING WILL APPEAR --> Overflow in implicit constant conversion (too big to fit into an int)


	printf ("x is %d\n", x);

	printf ("Example done\n");
//Converts EXIT_SUCESS to be a number (zero). We use EXIT_SUCESS because we don't want to use MAGIC NUMBERS (which are bad)
	return EXIT_SUCCESS;
}

/////////////////////////////////////////////////////////////////////////////////////////////

/*
	VOID EXAMPLE - Not taking anything in / not returning anything.
	If a function returns nothing --> you say VOID.
	A short example to show what the Void function does.
	E.g. Printing "HELLOWORLD" doesn't take anything in
*/

//DEFINES function exampleOne (void = tells C that its a function that takes nothing in)
	// It's a CONSTANT function
	// It doesn't return any values --> doesn't compute any number that it gives to us.
	// Doesn't parse any values back to the program.
//To call this function: add "exampleOne();" in the main program (int main).
	// + you need to put the function prototype (declaring a function / declaring that it exists)
	// --> Add void exampleOne(void); above int main
	// otherwise it won't compile as it doesn't recognise the function in the main program.

void exampleOne(void) {
	printf("Example 1\n");
	printf("EXIT_SUCCESS is %d\n", EXIT_SUCCESS);
	return;
}

/////////////////////////////////////////////////////////////////////////////////////////////

// Void Example - DOUBLE
// How do you print a float out?
// Remember to declare the function in the main program

void exampleDouble (void) {
	double height = 1.84;
	printf ("your height is %f\n", height);
}

/////////////////////////////////////////////////////////////////////////////////////////////

// Void Example - DOUBLE
// How do you print a hexadecimal number out?
// This function will print out "your height is 4d2"

void exampleHex (void) {
	long height = 1234;
	printf ("your height is %lx\n", height);
}










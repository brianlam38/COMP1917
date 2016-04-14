/*
	LECTURE 18 - REPLICATION
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {

	return EXIT_SUCCESS;
}

// Revisiting Loops

int counter;
counter = 0;

while (counter < 100) {

	printf ("Bats\n");
	counter++; // Increases counter by value 1. Short hand way of saying "counter + 1"
}

/*
	What can go wrong while writing LOOPS?
	(1) Not incrementing / progressing the counter (forgetting to increase the counter)
	--> Result = infinite loop until and error occurs.
	--> You have to constantly be progressing for the loop to work.
	--> The loop shouldn't go on forever.
	(2) Forgetting to initialise variables (counter in this case) to zero
	--> When a var is declared, it will point to a piece of memory
	--> Until the var is initialised, that piece of memory could contain anything,
	which makes it unpredictable / bad.
	--> An "un-initialized variable" error may occur when trying to compile the program
	(3) Forgetting a SEMI-COLON after your increment in the WHILE LOOP
	(4) "NOT HAVING THE RIGHT TEST" = Having the WRONG LOOP CONDITION "while (wrong)"

		LOOP PROBLEM SUMMARY:
		1. Initialisation problem
		2. Progression problem
		3. Termination condition not being right
		Most of these problems result in loops stopping early, late or going on forever.

	LOOP CONVENTIONS
	(1) If your loop starts with ZERO, always use a "LESS THAN <"
	--> In this case, remember to increase value by 1 to include your "end value"
	(2) If your loop starts with ONE, always use "LESS THAN & EQUAL TO <="
	--> {FENCEPOST ERROR} If only "LESS THAN" is used, the person will most
	likely miss out by 1 too soon / 1 too late.
	--> E.g. how many days between the 10th & 21st January?
	--> More on the Fencepost error: E.g. Need 4 x wires + 5 x posts to build a fence.
	--> Always do a SANITY CHECK when you're writing loops, to make sure it makes sense
*/

// REFER TO MODULE 2.3
// ENCODING PROGRAM & LOOPS
int main(int argc, char * argv[]) {

	testEncode ();

	printf ("Enter 4 letters\n");

	char plainChar;

	int counter = 0;
	while (counter < 4) {
		scanf ("%c", &plainChar);
		if (isLowerCase(plainChar)) { // if the plainChar is lower caes, then:
			printf ("%c", encode (plainChar)); // print "encoded plainChar"
		}
		counter++; // INCLUDE PROGRESSION
	}

	printf ("\ndone\n");

	return EXIT_SUCCESS;
}

int isLowerCase (char letter) {
	return (letter >= FIRST_LC_LETTER) && (letter);
}

int toLower (char letter) {
	// upper case letter to lower case
	// other characters untouched
	if ((letter >= "A") && (letter <= "Z")) {
		letter = letter - 'A' + 'a'; // Remember use 'SINGLE QUOTATION' for characters
	}
	return letter;
}

void testEncode (void) {
	assert (encode ('a') == ('b'));
	assert (encode ('z') == ('a'));
	assert (encode ('A') == ('A'));
	assert (encode ('7') == ('7'));

	printf ("All tests passed!!!");
	printf ("You are aweosme!\n");

	// no return because VOID function
}

<---------LOOP ENCODE #2--------------->

int main(int argc, char * argv[]) {

	testEncode ();

	printf ("Enter 4 letters\n");

	char plainChar;

	// int counter = 0; // Commenting out because we don't use the var "counter"
	scanf ("%c", &plainChar); // Read it in first
	while (plainChar != ' ') { // Test it
		if (isLowerCase(plainChar)) { 
			printf ("%c", encode (plainChar)); // Possibly print it out
		}
		scanf ("%c", &plainChar); // Progressing to the end --> Need to read it in again until we get a "space"
	}
	printf ("\ndone\n");

	return EXIT_SUCCESS;
}

/*
	LECTURE 19 - REDUNDANCY

	Function (revision)
	- Something that takes some input in (possibly none, one or many), does some work inside
	and puts a single thing out.
	- When its doing the work, it might also do other things called SIDE-EFFECTS

	The Wondrous Function (only has one input & one output)
	- Takes in an INT / Puts out an INT
	- If the # is ODD --> x 3 + 1
	- If the # is EVENT --> / 2
	- Therefore:
		6 --> 3
		7 --> 22
		4 --> 2
		5 --> 16
		etc.
	- You can take the output and feed it back into the input:
	(Called ITERATING THE FUNCTION / FUNCTION ITERATIVES ON ITSELF)
		5 --> 16 --> 8 --> 2 --> 1 --> 4 --> 2 --> 1 --> 4 ... loop
		7 --> 22 --> 11 --> 34 --> 17 --> 52 --> 26 --> 13 --> 40 --> 20 --> 10 --> 5 --> 16 ... loop
	- Looking at the behaviour of the iterative function:
	--> Some numbers quickly converge to a loop
	--> Some numbers go up, then down, then up, then down etc.
	--> You wonder if some numbers ever end in a loop
	
	With LOOPS:
	- You can produce a program with quite complex results (even if starting from simple rules)
	- E.g. the 4004:
	--> An amazingly simple tool, with just a few rules (16 rules)
	--> Even with 16 bytes and simple instructions, the behaviour of that computer is astonishing
	--> The COMPLEXITY hiding in those 16 bytes is so vast that our minds can't comprehend the scope of it.
	--> The amount of programs that you could run = 16^16 (an enormous #) = 4^32 = 2^64 (64 bits)

	Even simple rules generate complex systems really quickly
	- Every program we build from now on is already too big to understand
	- We have to be suspicious of everything / have to be defensive when making things
*/


/*
	Combining LOOPS with LOOPS

	Things that would have that sort of behaviour:
	- Making a grid
	--> Doing it one time across, looping it around, doing it another time across, looping etc.
*/

/* <---------LYBIAN FLAG EXAMPLE (SOLID GREEN)----------->
	About 15 pixels across x 5 pixels down
	- How to make it:
	- print 15 stars, print 15 stars, print 15 stars, again, again

	What will be printed is just a SIDE-EFFECT (the stars). No actual output.
	- Humans can understand the printed out flag
	- Computers won't know what it is / what to do with it

	One method to check if flag is printed correctly = check # char's printed
	-  Modify the print flag function --> return # of stars that has been printed --> check if its right #
	One method to check = Manual human intervention
	- "What you're about to see should look like this"
	- You can eyeball comparison to see if its the same

	Dilemma: whenever we have to test smn that uses side-effects, its very hard to test.
	- If possible, we try to isolate all our side-effects + make all complexities / fcn's that we can test.
*/

void testLibya (void);
void showLibya (void);

int main(int argc, char * argv[]) {
	testLibya ();

	showLibya ();
	return EXIT_SUCCESS;
}

void testLibya (void) {
	printf ("Output should look like \n");
	printf ("***************\n");
	printf ("***************\n");
	printf ("***************\n");
	printf ("***************\n");
	printf ("***************\n");
	showLibya();
}

void showLibya (void) {

}

// <-----------Test Libya Function V1-------------->

#define WIDTH 15
#define HEIGHT 5

int main(int argc, char * argv[]) {

	int col = 0; // col = column
	while (col < WIDTH) { // Will print a line of 15 stars.
		printf ("*"),
		col++; // Including Progression
	}
	printf ("\n");

	return EXIT_SUCCESS;
}

// <-----------Test Libya Function V2--------------> // Refer to rowtest.c
// <-----------NESTED LOOP EXAMPLE----------------->

#define WIDTH 15
#define HEIGHT 5

int main(int argc, char * argv[]) {

	int col = 0;
	int row = 0;

	while (row < HEIGHT) { // Loop ends after HEIGHT = 5 is reached
		col = 0;
		while (col < WIDTH) { // Loop ends after WIDTH = 15 is reached
			printf ("*"),
			col++;
		}
		printf ("\n");
		row++;
	}
	return EXIT_SUCCESS;
}

// <----------Flag of Ireland------------->
// GREEN / WHITE / ORANGE
// COLUMN = 5G / 5W / 5O
// ROW = repeat above 5 times

See rowtest2.c for your own answer + compare with Richards answer.

// Richard's Answer:

#define WIDTH 15
#define HEIGHT 5
#define IRISH_WIDTH (WIDTH/3) // To split flag into 3 different colours

void showPixel (int col) { // Void Function --> Takes in a col
	char pixel; // Creates a local variable called "pixel"
	if (col < IRISH_WIDTH) { 			  // CASE #1
		pixel = "g";
	} else if (col < (2 x IRISH_WIDTH)) { // CASE #2
		pixel = "w";
	} else { 							  // CASE #3
		pixel = "o";
	}
	printf ("%c", pixel); // Prints whatever char the program inputs into the printf
}








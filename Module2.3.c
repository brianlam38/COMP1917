/*
	LECTURE 15 - ADDRESSES AND POINTERS

*/

/*

Variables only live as long as a FUNCTION lives.
Variables die when the function returns to the outside world.

When you call a function:
- The function sets some memory aside and copies the stuff you give it into that memory and then uses it.
- At the end of the function it throws it away.
- E.g. If you parse in 2 variables:
--> It copies the values of the 2 variables into the function
--> It works on those copies
--> When the function is finished, it throws those copies away
--> It's not actually working on the original data, but the COPY of the data

*/

// When the function is run, Y = a negative number
	// Because x has overflowed.
	// With a signed number that becomes too big, undefined things can happen
	// Have to be very careful with overflows
void exampleTwo (void) {
	printf ("Example 2\n");
	int x = 1000000000;
	int y;
	y = x + x + x + x;

	printf("x=%d y=%d\n", x, y);
}

<----------------------------------------------------------------------------------------------------->
ADD TO EXAM / STUDY NOTES

How to find out the size of your variable
	// SIZEOF(x) tells you "how many bytes that variable is"
	// In this example, sizeof(x) = 4 bytes
void exampleThree (void) {
	printf ("Example 3\n");
	int x = 1000000000;

	
	printf("sizeof (x) = %ld\n", sizeof(x));
	return;
}

Additional example: Size of characters
	// Sizeof CHAR's are defined to return 1 byte
void exampleThree (void) {
	printf ("Extra Example 3\n");
	char letter; // sets memory aside for it --> haven't written anything into the memory yet

	printf("sizeof (letter) = %ld\n", sizeof (letter));
	return;
}

// USING THE SAME LOGIC IN EXAMPLE THREE + EXTRA THREE, you can find out the size of SHORTS, LONGS, FLOATS, DOUBLES etc.

POINTER ADDRESS example
// The print result would be in HEXADECIMAL code (0xbffff70c to be precise)
	// This means that somewhere in memory, at an address cell called "0xbffff70c" is 1 byte of memory sitting there
	// and that is the first byte of the four byte INTEGER called X
// You can tell that it is HEX because it starts with "0x"
// If you find the ADDRESS of X, Y, Z you can tell that the storage is NOT random
	// hex....00, hex....04, hex....08 --> It's four bytes apart / using four byte integers
void exampleFour (void) {
	int x = 1;
	int y = 2;
	int z = 3;

	int *address; // * means "address of".
				  // E.g. 4004 microprocessor (0-15 cells: "whats the address?" --> "Value 6 is stored at address 10"
				  // (INT *) means a POINTER to an INT / the address of an INT in memory
				  // "Pointer to X" means "the address of X"

	address = &x; // Will tell you, the "address of the cell to store X"
				  // ADDRESS is a POINTER to an INT.
	printf("address of x is %p\n", address); // Use %p to print out a pointer
											 // Will print out the address
	printf("the value stored at %p is %u\n", address, *address); // Find the VALUE at an address
																 // *address = "tell me the value thats stored there"
																 // Answer should be x = 1. Similar if you do same for Y, Z.
}

/*

	EXTRA: Creating other files and #include them in your main file

- You can create a new file (e.g. main.h) where you can put declarations / functions / #defines / whatever else
  in it and then #include it into your main file so that it uses it.
--> Putting #include "main.h" = searches for a file called main.h in your CURRENT DIRECTORY
--> Putting #include <main.h> = searches for a LIBRARY file (which does not exist)
--> This is a good way to hide things that are annoying.

*/

/*

	EXTRA 2: Scanf

- Scanf has its effect NOT by returning a value.
- Scanf has its effect by ALTERING a value that you parse in.
- REMEMBER: When you parse something in, C makes a local copy of it.
--> This is so that the function cannot fool around and alter it
--> If you are given X, Y, Z into a function, and you are the function, you only get a COPY of X Y Z
--> You can change it as much as you want, but you will only be changing a LOCAL COPY of it.
--> It gets DESTROYED AT THE END.
- HOWEVER: Scanf is able to alter the value of X in the "REAL WORLD"
--> When a function can do that, we call it a "SIDE EFFECT" when a function can do that
--> Side effects are potentially very dangeorous.
*/

<----------------------------------------------------------------------------------------------------->

/*
	LECTURE 16 - TESTING

	How do we do testing in this course? --> You will start to do testing with everything in this course.

	We want to write a TOP SECRET FN / SPY PROGRAM = Take a message and turn it into a secret message (encryption):
													 We want to turn the letter "a" into the letter "b" etc.

*/

#include <stdio.h>
#include <stdlib.h>
#include "encode.h" // Header file
#include <assert.h> // For the tests

#define FIRST_LETTER 'a' // Assuming for this scenario that we don't encode uppercase letters, ONLY lower case.
#define LAST_LETTER 'z'

int isLetter (char letter);

void testEncode (void); // Declaring the test function

int main (int argc, char * argv[]) {

	testEncode (); // Putting it in the front of main to run the test silently	

	char plainText;
	char cipherText;

	printf ("Enter a plain text character:\n")

	scanf ("%c", &plainText); // Scan in the plain text + give it an address to go to
	cipherText = encode (plainText); 	// Calling the ENCODE function below rather than putting the function in the main program.

	printf ("Encrypted is %c\n", cipherText);
	return EXIT_SUCCESS;
}

// WRITING TESTS - Always write your test before writing your function
	// Write your tests with the ASSERT type (you need to #include <assert.h>)
	// To run tests first, you should insert the function in your main program at the very beginning "testEncode ();"
	// so that it runs before it runs anything else in your program.
	// EVERY TIME YOU WRITE A FUNCTION --> YOU WRITE A TEST FOR IT
void testEncode (void) { // REMEMBER: You need to declare the function before your INT MAIN
	assert (encode ('a') == 'b'); // NOTE: CHAR's go inside single quotations | STRINGS go inside double quotations
	assert (encode ('z') == 'a');
	assert (encode ('A') == 'A'); // remains the same because it shouldn't be encoded!
	assert (encode ('7') == '7');
	printf ("All tests passed!!!");
	printf ("You are awesome!\n");
}

// 1.0 ISLETTER FUNCTION
int isLetter (char letter) {
	int alpha = (letter >= FIRST_LETTER) && (letter <= LAST_LETTER);
	// &&: we want it to be greater or equal to the first letter + lesser or equal to the last letter
	return alpha;
}

// 2.0 ENCODE FUNCTION
char encode (char plainText) { // Encode function takes in a plainText -> returns a cipherText
	char cipherText;
	int toBeEncoded = isLetter (plainText);

	if (toBeEncoded) { // YES/NO function: If a letter, it is to be encoded. If not, it won't be encoded.
		cipherText = plainText + 1; // A character is treated like an INT in C. You can do math operations on it.
		if (cipherText > LAST_LETTER) { // If you reach the last letter, it will become the first letter A->Z
			cipherText = FIRST_LETTER;
		}
	} else {
		cipherText = plainText; // If not to be encoded, ciphertext = plaintext
	}

	printf ("Encrytped is %c\n", cipherText); // Print out what the ciphertext is
	return EXIT_SUCCESS;
}













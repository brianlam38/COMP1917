/*
	LECTURE 9 - Bits, Binary and Hexadecimal
*/

1 9 1 7 = 10^3 + 10^2 + 10^1 + 7^1

Binary = Base 2
// Made up of ZERO & ONES. Or could easily be BLACK/WHITE, NOUGHT/CROSS etc.
Decimal = Base 10
// Called decimal because DEC = 10 (1,2,3,4,5,6,7,8,9,10)
Hexadecimal = Base 16

/*
	BINARY Example:
   64 32 16 8 4 2 1
	  	  0 0 0 0 0    0
		  0 0 0 0 1    1
		  0 0 0 1 0    2
		  0 0 0 1 1    3		- 16 Possible numbers
		  0 0 1 0 0    4          with four binary digits
		  0 0 1 0 1    5        - BInary digiT (BIT)
		  0 0 1 1 0    6		- 64 bits = 16 cells x 4 bits each. (4004 microprocessor)
	      0 0 1 1 1    7		- If we can store 8 bits / cell = 255 bits. (8004 microprocessor)
    1  1  0 0 0 1 1   99 --> Writing "99" in BINARY 
			.......    .
			1 1 1 1   15
			.......    .

*/

/*
	HEXADECIMAL Example
	- Base 16 = 16 different digits.
	- 0 1 2 3 4 5 6 7 8 9 A(10) B(11) C(12) D(13) E(14) F(15)

	16^4 16^3 16^2 16 1
				B  A  D = (11 x 16^2) + (10 x 16) + (13 x 1) = 2989
*/

<------------------------------------------------------------------------------------>

/*
	LECTURE 10 - Memory Types
*/

- Each memory location / cell = BYTE
- 4004 chip = 16 cells x 4 BITS
--> "4 bit bytes"
- 8004 chip = 16 cells x 8 BITS
--> "8 bit bytes"

For the 4004: In C, how many bits are used to store an INT? (integer)
--> 4 bytes to store = 32 bits
For the 8004: In C, how many bits are used to store an INT?
--> 256 bits of memory / cells available.
--> 8 bits per cell.

// What's the effect of having more or less memory to store things?
	// SHORT int x = Say it can only use 2 bytes
		// 2 bytes can only store up to the number 65,000
		// but if you wanted to store 66,000, it won't fit in, will wrap around and become negative.
	// However, if you set LONG x (rather than LONG int x) so you want to store longer things / bigger keys
		// The actual size of a LONG x depends on the machine you're using.
	// LONG LONG x = Even more storage than a LONG x
		// If you're doing a massive set of numbers (maybe for cryptographic applications etc.)

USING INTS 
/*

- When dealing with numbers, you'd normally use INT.
- However, when you're dealing with cryptographic applications that need really big numbers,
  then you have have to think carefully about what you're doing an use whatever is appropriate
- INT is supposed to be the "natural size" of the CHIP that you're on.
--> When the computer needs to load and fetch numbers from the MICROPROCESSOR <--> MEMORY, you
	can move an INT-at-a-time.
--> E.g. if you pick something BIGGER than an INT, it might take a couple of operations to move
	it out and a couple to move it in.
--> E.g. if you pick something SMALLER than an INT, it will move an INT's worth of stuff anyway
	so you're not saving anything.
--> Therefore, INT is the NATURAL SIZE.

*/

FLOATING POINT NUMBERS
/*

	Floating Point Numbers = numbers with a decimal point
	ints = whole numbers

Float x = 3.14
- Computer will set an area of memory to store this in
- When dealing with Floating Point Numbers, you normally use DOUBLE.
--> DOUBLE (uses 8 bits) = 2 x memory to store numbers than FLOATS.
--> FLOAT (uses 4 bits)

How many decimals can you store in a FLOAT? (4 bytes = 32 bits)
- How would you use 32 bits to store a decimal number?
--> To store an INT, you just use binary
--> To store a DECIMAL, you use most of the bits to store the significant digits of the number
	and then the remaining bits to store the decimal point.
	--> To store the EXPONENT = 8 bits
	--> To store the SIGN (positive or negative) = 1 bit
- Example: Storing PI
--> First Part: It will store as a LONG = 314159265 etc.
--> Second Part: "Put the decimal place at there"
--> The number of SIGNIFICANT FIGURES will always be constant / The decimal point will just move around.

- Extra notes
--> It is possible to have variable lengths in numeric types later on
--> It is possible to store something and adjust its size dynamically to make it bigger / smaller
--> Advantage of the flexibility = ability to do amazing things
--> Disadvantage of the flexibility = tends to be slower, more error prone, more programming work
	so we only do it when we really need it
--> We will know how to do this by the end of the course
--> At the moment, we are just focusing on the basic stuff. (ints, doubles, floats)
--> Should always use a DOUBLE, not a FLOAT because it is usually never big enough and 
	you will get rounding errors.

*/

What if you set aside 4 bytes? And then put more in?
	// E.g you say int x; --> then you say x = 1000000000;
	// Might truncate it / wrap around

What is the difference between SIGNED / UNSIGNED
	// What if you want to represent negative numbers?
		// You can't just add a bit (to add a sign), because you only have 4 bits.
		// They usually SPLIT THEM -8 . . . . 0 . . . . . +7
	// (default INT) SIGNED INT = Both positive and negative numbers
	// UNSIGNED INT = You can get more positive numbers
	// FLOATING POINT NUMBER =

If someone gives you some BITS + asks you what its storing, to work it out you need to:
	// Know what TYPE its stored as
	// How the COMPILER REPRESENTS that TYPE (on your particular architecture)

How do you specify that you want it to be UNSIGNED?
	// You say "unsigned int x;"
	// Similarly, you can say "signed int x;"

CHAR type
/*
	CHAR type stores a CHARACTER (a letter/digit/symbol)

	Computers talk to us in both NUMBERS + LETTERS

	Each letter is given a code between 0 - 255

	ASCII
	--> 32 = space
	--> 65 = A (uppercase a)
	--> 66 = C (uppercase c)
	--> Lowercase etc.
*/

What if you want more than 255 characters? (E.g. ASIAN LANGAUGES)
	// UNICODE = bigger range of characters using more BITS

BOOLEANS type
/*
	BOOLEANS store a TRUE / FALSE

	Example: If (x > 400) { }
	--> It is an expression, that is either going to be TRUE or FALSE
	--> C needs to INTERNALLY or EXTERNALLY store this answer
	
	Example: boolean passed = (mark >= 50)
	--> You will get a YES/ NO
	--> YES / NO will be stored in the variable called "passed"
	--> Later on, you might want to test the "passed" variable
	if (passed) { do this }

	In most languages, there is a way to store these BOOLEANS (true/false)
	--> C programming doesn't have a way to store them.
	--> The only way to store TRUE/FALSES in C, is that you store them as a number
		--> Store FALSE = 0
		--> STORE TRUE = 1
	--> You can store any other number that's not zero / one. (E.g. YES = 7, No = 0)
		--> It is very wasteful because we store them as an INT (takes up 4 bytes)
		--> int passed (mark >= 50)
*/








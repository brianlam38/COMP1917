/*
	LECTURE 13 - FUNCTIONS PT 2.
*/

// ARGUMENTS = Actual values which are passed into a function call
// PARAMETER = Variables defined in the function to receive

// How would you a variable from one function and another function?
// E.g. Parsing "year" into two functions

int isLeapYear(int); // Will return 1 or 0 depending on true or false
int yearToDoomsday(int); // Will return number between 0 - 6 saying which day of the year it is. (7 days)

/////////////////////////////////////////////////////////////////////////////////////////////

// With writing big programs:
	// Get the BIG PICTURE first and then work out the specifics
	// TOP DOWN DESIGN --> Write the biggest thing first then break it down to slightly smaller problems.
// Best to actually SEPARATE THESE into sub-problems rather than putting them all together AS BELOW
	// Really hard to check a big problem that is put together (similar to Toast Estimation ex.)
	// You might think the program is right, but it might not be because of the COMPLEXITY
		// COMPLEXITY --> Hides potential for error
		// There might be something wrong with some test cases
	// Breaking it into sub-parts independently:
		// The COMPOSITE PROGRAM that you build using the sub-parts is much more reliable
		// GREAT FOR CLARITY.

// Finding out how many days until next Thursday?
	// eg for 16 March 2011 (2011,3,16) the function will return 1
	// eg for 17 March 2011 (2011,3,17) the funciton will return 7
int daysNextThursday(int year, int month, int day) {
	int doomsday = yearToDoomsday (year);
	int leapYear = isLeapYear (year);
	int weekDay = dayOfWeek (doomsday, leapYear, month, day);
	// When calling dayOfWeek, we need to do know:
		// What the DOOMSDAY of that year is (don't know / need calculation)
		// If the year is a LEAPYEAR or not (don't know / need calculation)
		// What the MONTH of the date is (already parsed / given by user asking the qn)
		// What the DAY of the date is (already parsed / given by user asking the qn)

	int daysToThursday = "SOME PRETTY SIMPLE CALCULATION;"

	return daysToThursday;
}

// In above main function, for dayOfWeek: (when below fn is called) value of Doomsday --> d / leapYear --> guy 2 etc.
// This can also be confusing because they should be meaningful.
	int daysOfWeek (int d, int guy2, int guy3, int guy1) {

	}

/////////////////////////////////////////////////////////////////////////////////////////////

/*
	LECTURE 14 - Bitmap Images

	BITMAP FILES = Just a collection of zeros and ones

When you store something in binary, the zeros and ones have no meaning until INTERPRETED in some way.
- If you look at a group of 8 zeroes and ones, you can interpret them as:
--> A character in the alphabet (using ASCII / UTF8 Encoding etc.)
--> A number between 0 to 255
--> A number between -128 to +127
--> TRUE / FALSE

A bitmap file (an image)
- A collection of ZEROES and ONES (Like any file on the computer)
- Normally, we group them into lumps of eight (a Byte)
- In a HEX EDITOR, it displays the Bytes as a NUMERICAL VALUE rather than CHARACTERS
  (What would happen if you opened them in a text editor/ word etc.)

33.bmp
- Shows 4 BYTE chunks at a time = 32 BITS
- First column = What number byte are we up to
- 42 in HEXADECIMAL: (14 x 16) + (2 x 1) = 66
- Goes from 00 to 89 = 90 bytes long file.
- First two bytes (42, 4D) = B(42) and M(4D)
--> File will CORRUPT if you try to change the B/M by changing the hexadecimal codes in the first two bytes.
*/

Structure of a BITMAP file
/*

Pixel Array = Data where the image is stored

# HEADER - 14 bytes - To store information about the Bitmap Image File
# DIB HEADER - 40 bytes but can vary - To store detailed information about the Bitmap Image File + define the PIXEL FORMAT
--> Width of the image in pixels
--> Height of the image in pixels
--> Number of colour planes being used. (must be 1)
--> Number of BITS per PIXEL (see below)

# First 2 bytes = header BM
# Next 4 bytes = size of bitmap file (in bytes)
# Next 2 bytes = reserved
# Next 2 bytes = reserved
# Next 4 bytes = where the data starts.

# There are extra bytes sometimes just sitting there.

*/

How many BITS are used to represent a PIXEL?
--> After 14 bytes into the header
--> 24 bits per pixel
-->	3 lots of 8 bits (R,B,G)
















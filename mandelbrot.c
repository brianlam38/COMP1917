/*
	Task 2B - Mandelbrot Set
*/

/*
	Notes on assignment

	- Possibly write it in pseudocode before you do the actual thing first?
	- This assignment doesn't need ARRAYS
	- All you're doing is a WHILE LOOP stepping over points.
	--> As soon as you get to each point, you know what colour to colour it, then you print the pixel out.
	--> Go to the next point, then print the pixel out, then the next point etc.

	- How to print a PIXEL / printing out a BITMAP.
	--> E.g. a 4 x 4 bitmap file
	--> Each file contains a header (54 bytes long)
	--> Then it contains an image with each of the pixels
	--> 3 bytes for the 1st pixel (thats the RGB) (colour of the 1st pixel is given by the first 3 bytes)
	--> Colour of the next pixel is given by the next 3 bytes.
	1st byte = Tells you how much BLUE is in the pixel (# between 0-255)
	2nd byte = Tells you how much GREEN is in the pixel (# between 0-255)
	3rd byte = Tells you how much RED is in the pixel (# between 0-255)
	--> Your program (the server) prints out the HEADER (which is just bytes) (using "write" command)
	--> "Write out that byte, write out that byte etc. and then you go to the end writing out all the bytes"

	To "Return" the program:
	--> You send it across the internet to the browser (write it to the port)
	--> Command to do that is already in the sample server given, called
		"write(insert arguments, such as array of all pixels you want to write out + give it socket number +
		how many bytes you want to write out")
	--> The actual argument is:
		char pixel [50]; (means "PIXEL is an array of CHARACTERS of size 50") (A char is just 1 byte, # between 0-255)
		write(clientSocket,pixels,50) (sends out 50 bytes to the web browser. We will be sending out 102 bytes with header etc.)
	--> Our code should be something like:
		char header [54]; // Create header 54 bytes big
		write(socket, header, sizeof header); // To print out the header
		LOOP
			char pixel [3]; // Each pixel is represented by 3 bytes
			pixel [0] = 10;
			pixel [1] = 10;
			pixel [2] = 255;
			write(socket, pixel, 3); // Writing to the internet rather than printf to screen
		Close(socket);

		--> Socket # means you program is communicating with the outside world
			E.g. Writing to the screen / Writing to an internet connection

	Header - You have to say the size of the file in bytes
	--> Header is always of size 54 bytes
	--> Work out the size of the image (Size of pixel data + 54 = size of whole image)
	--> 400 by 400 = 160,000 pixels
	--> 160,000 x 3 bytes = 480,054 bytes

	You could write the header out in chunks
	--> write(socket, size, 4);

	You can steal an existing header from an existing file
	--> Copy the first 54 bytes and paste it into your own
	--> Make sure you can read the header and understand what the different parts mean

	Another method:
	char blue;
	char green;
	char red;
	red = 10;
	blue = 10;
	green = 255;
	write(socket, &blue, 1);
	write(socket, &green, 1);
	write(socket, &red, 1);

What an array means / What a person expects to see:
- A colleciton of identical typed elements, all naturally belonging together
- When storing colours (storing as an array of colours):
--> You've got an array and you're storing R(1st element of array), G(2nd), B(3rd) {R, G, B}
--> ARRAY = All the elements are the "same sort of thing"
	E.g. PERSON HEIGHT 1, HEIGHT 2, HEIGHT 3
--> STRUCT = Grouping together a collection of things that BELONG TOGETHER, but each have a DIFFERENT.
	(NOT AN ARRAY)
	E.g. DAY / MONTH / YEAR
--> You can have an ARRAY of STRUCTS

Last part of TASK2
- When you print out the Mandelbrot set as a series of pixels, you're really just making a YES/NO decision
  (if its in the set / if its not in the set)
- If in the set: print out in BLACK
- If not in the set: print out in WHITE
- The Mandelbrot set is more interesting than that.
--> For each pixel, we calculate a centre point and we're interested in if that point is in the set or not
--> We iterate up to 255 times and it still doesn't move away (B)
--> The point next to it I iterate 250 times and it moves away (W)
--> The point next to it I iterate 3 times and it moves away (W)
--> Rather than saying B, W, W, I say: I'm going to colour every pixel differently, depending on the number of
	iterations it took to escape (at most iterate 255 times)
	--> R = B = G (makes it grey)
		--> (10,10,10) = 10 grey / (20,20,20) = 20 grey / (100,100,100) = 100 grey
	--> Make them all shades of grey
	--> The colour I use will be the # of steps it took until I discovered it moved out of the step
	--> If I went through all 255 iterations and it hasn't moved out of the set, I stop my loop
		and make everything (255,255,255) = makes it WHITE.
	--> If you print a picture with the colour of each pixel as shades of grey, it looks similar to the
		Mandelbrot set
	--> You can map the numbers however you like
		--> E.g. if it took 200 iterations, it will be this shade of grey.
		--> If it took 201 iterations, it will be this shade of grey.

TO MAKE YOUR MANDELBROT INTERESTING:
- You iterate each point and work out how many times it takes to escape
- For each possible number of times (going up to 255) pick a different colour for each one and colour your map in
  that way.
- It's called a COLOUR MAP


*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {



	return EXIT_SUCCESS;
}











#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {

	printf("argc = %d\n\n", argc);
/*
	Printing the integer value of argc

	When the program is run by typing in "./argc" command, terminal should output "argc = 1"
	because we entered one thing when running the program, just the prompt itself

	If we enter more things, e.g. "./argc brian programming", terminal should output "argc = 3"
	because we entered three things when running the program, the prompt, arg 1(brian), arg 2(programming).

	ARGC just represents the number of things entered into terminal when running the executable.
*/


	printf("Let's see what is in argv[]\n");
	int i; // declaring variable i
	int sum = 0; // declaring + initialising variable sum
	if (argc > 1) { // Execute function only when index > 1
		for (i = 0; i < argc; i++) { // i starting index 0, i < value of what is stored in argc, increment i
			printf("argv[%d] = %s\n", i, argv[i]);
			sum += atoi(argv[i]); // SAME AS: "Sum = Sum + atoi()" Converting string into integer using "atoi function"
		}
		printf("TOTAL = %d\n", sum);	
	} else {
		printf("Program can't be executed. There is only one command");
	}

/*

	Argv is an array. Char* is a string. "an array of strings"

	The things that argv will hold are essentially the things that were entered into the terminal.

	When the program is run by entering "./argc XXX XXX" into terminal, terminal will output the exact
	string of characters that you enter as commands.

	In the second part, the commands you type in are in string form (argc / characters) therefore need
	to be converted to integers using the "atoi" function. The program sums any numbers that you
	intput when you run the program, then prints the TOTAL VALUE.
*/

	return EXIT_SUCCESS;
}
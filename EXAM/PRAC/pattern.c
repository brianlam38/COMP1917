// pattern.c
// 1917 final exam 2015s1
// part P Q1
// 15 Marks
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "pattern.h"

// you can assume size is a positive value between 1 and 26 (inclusive)
// this function is to print on the screen a pattern of upper case 
// characters with an empty diamond shape in the center.
// The number of unique characters to be used is equal to "size" and 
// always start from 'A'. The pattern fits inside a square of side
// length "2*size". 
// NOTE: It is hard to describe the pattern in words but the examples 
// below should clarify what is expected.

// match the output shown below

/* 
compile and test your code as follows

$ gcc -O -o partP1 -Wall -Werror -std=c99  pattern.c testPattern.c

examples and how to run it:

$ ./partP1 5
ABCDEEDCBA
ABCD  DCBA
ABC    CBA
AB      BA
A        A
A        A
AB      BA
ABC    CBA
ABCD  DCBA
ABCDEEDCBA

$ ./partP1 8
ABCDEFGHHGFEDCBA
ABCDEFG  GFEDCBA
ABCDEF    FEDCBA
ABCDE      EDCBA
ABCD        DCBA
ABC          CBA
AB            BA
A              A
A              A
AB            BA
ABC          CBA
ABCD        DCBA
ABCDE      EDCBA
ABCDEF    FEDCBA
ABCDEFG  GFEDCBA
ABCDEFGHHGFEDCBA

$ ./partP1 11
ABCDEFGHIJKKJIHGFEDCBA
ABCDEFGHIJ  JIHGFEDCBA
ABCDEFGHI    IHGFEDCBA
ABCDEFGH      HGFEDCBA
ABCDEFG        GFEDCBA
ABCDEF          FEDCBA
ABCDE            EDCBA
ABCD              DCBA
ABC                CBA
AB                  BA
A                    A
A                    A
AB                  BA
ABC                CBA
ABCD              DCBA
ABCDE            EDCBA
ABCDEF          FEDCBA
ABCDEFG        GFEDCBA
ABCDEFGH      HGFEDCBA
ABCDEFGHI    IHGFEDCBA
ABCDEFGHIJ  JIHGFEDCBA
ABCDEFGHIJKKJIHGFEDCBA

$ ./partP1 1
AA
AA

$ ./partP1 2
ABBA
A  A
A  A
ABBA

$ ./partP1 3
ABCDEE   // print 3 char, then 3 char backwards
AB  BA   // print 2 char, then two spaces, then 2 char backwards
A    A   // print 1 char, then four spaces, then 1 char backwards
A    A   // repeat
AB  BA   // reverse print previous.
ABCCBA

submit with this command
$ submit partP1 pattern.c
*/
#define ALPHABET 26
void printPattern (int size) {
/* BRIAN'S SOLUTION */
	char alphabetArray[ALPHABET] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

/* TOP HALF CODE */
	int topLineNum = 0;
	while (topLineNum != size) {
		// PRINT LEFT SIDE
		if (topLineNum == 0) {								// FIRST LINE WITHOUT SPACES
			int lineWidth = 0;
			while (lineWidth != size) {
				printf("%c", alphabetArray[lineWidth]);
				lineWidth++;				
			}
		} else {											// ALL OTHER LINES
			// Print LHS chars
			int lineWidth = 0;
			while (lineWidth != (size - topLineNum)) {		// iterates to beginning of spaces
				printf("%c", alphabetArray[lineWidth]);
				lineWidth++;
			}
			// Print LHS spaces
			while (lineWidth != size) {						// iterates to end of spaces
				printf(" ");
				lineWidth++;
			}
		}
		// PRINT RIGHT SIDE (BACKWARDS)
		if (topLineNum == 0) {
			int lineWidth = size;
			while (lineWidth != 0) {
				printf("%c", alphabetArray[lineWidth - 1]);
				lineWidth--;
			}
			printf("\n");	// next row after completion of RHS LINE 0
		} else {
			// Print RHS spaces
			int lineWidth = size;
			while (lineWidth != (size - topLineNum)) {
				printf(" ");
				lineWidth--;
			}
			// Print RHS chars
			while (lineWidth != 0) {
				printf("%c", alphabetArray[lineWidth - 1]);
				lineWidth--;			
			}
			printf("\n");	// next row after completion of RHS
		}
	topLineNum++;
	}

/* BOTTOM HALF CODE */
	int botLineNum = 0;

	while (botLineNum != size) {
		// PRINT LEFT SIDE
		if (botLineNum < size) {
			// Print LHS chars
			int lineWidth = 0;
			while (lineWidth != (botLineNum + 1)) {
				printf("%c", alphabetArray[lineWidth]);
				lineWidth++;
			}
			// Print LHS space
			while (lineWidth != size) {
				printf(" ");
				lineWidth++;
			}
		} else {										// LAST LINE WITHOUT SPACES
			int lineWidth = 0;
			while (lineWidth != size) {
				printf("%c", alphabetArray[lineWidth]);
				lineWidth++;
			}
		}

		if (botLineNum < size) {
			// Print RHS space
			int lineWidth = size;
			while (lineWidth != (botLineNum + 1)) {
				printf(" ");
				lineWidth--;
			}
			// Print RHS chars
			while (lineWidth != 0) {
				printf("%c", alphabetArray[lineWidth - 1]);
				lineWidth--;
			}
			printf("\n");
		} else {
			int lineWidth = size;
			while (lineWidth != 0) {
				printf("%c", alphabetArray[lineWidth - 1]);
				lineWidth--;
			}
			printf("\n");
		}
	botLineNum++;
	}
}







/* JASON'S SOLUTION
void printPattern (int size) {
	char line[size][2*size+1];
	int row = 0;
	while (row < size) {
		int i = 0;
		while (i < size - row) {
			line[row][i] = 'A' + i;
			line[row][2*size-1-i] = 'A' + i;
			i++;
		}
		while (i < size) {
			line[row][i] = ' ';
			line[row][2*size-1-i] = ' ';
			i++;
		}
		line[2*size] = '\0';
		row++;
	}
	row = 0;
	int i = 0;
	while (row < size) {
		printf("%s\n", line[i]);
	}
	row = 0;
	while (row < size) {
		printf("%s\n", line[size-1-i]);
	}
}
*/

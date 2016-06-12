#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

char label1[] = "Single";		// abstract declr label
char label2[10] = "Married";	// static decl label2
char *labelPtr;					// pointer to char decl labelPtr

/* Set labelPtr to point to contents of label */
labelPtr = label1;
printf("%s\n", labelPtr);		// Single
printf("%p\n", &labelPtr);		// 0x7fff5c53ca40 (address of ptr labelptr)
printf("%p\n", labelPtr);		// 0x7fff5c53ca48 (address of first char label)
printf("%c\n", *labelPtr);		// S    (value stored at labelPtr)
printf("%c\n", labelPtr[1]);	// i    (value stored at element #2 of label)
printf("MAIN: %p\n\n", main);	// MAIN: 0x1036c3e10 (address of main f'n)

/* Set labelPtr to point to contents of label2 */
labelPtr = label2;
printf("%s\n", labelPtr);		// Married
printf("%p\n", &labelPtr);		// 0x7fff5c53ca40 (address of ptr labelptr)
printf("%p\n", labelPtr);		// 0x7fff5c53ca50 (address of first char label2)
printf("%c\n", *labelPtr);		// M    (value stored at labelPtr)
printf("%c\n", labelPtr[1]);	// a    (value stored at element #2 of label2)
printf("MAIN: %p\n\n", main);	// MAIN: 0x1036c3e10 (address of main f'n)

printf("The length of label2 is %lu\n\n", strlen(labelPtr));
// The length of label2 is 7

char *labelPtr2 = label1;	// declare new ptr to label1

if (strcmp(labelPtr, labelPtr2) == 0) {
	printf("label2 is equal to label1\n\n");
} else {
	printf("label2 is NOT equal to label1\n\n");
}

strcpy(labelPtr, labelPtr2);
printf("Destination labelPtr now stores %s and source labelPtr2 stores %s", labelPtr, labelPtr2);

// Function to use an initialised array to print out values in memory
    char things[100];
    int counter = 0;
    while (counter <= 100) {
        printf("%c", things[counter]);
        counter++;
    }
    printf("\n");


	return EXIT_SUCCESS;
}


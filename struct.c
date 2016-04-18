#include <stdio.h>
#include <stdlib.h>
 
#define MAX_LENGTH 255
 
typedef struct _person { 
	//the underscore is for us to distinguish between the structs, its not for c
	char firstName[MAX_LENGTH];
	char lastName[MAX_LENGTH];
	int age;
	short postCode;
} person;
 
// typedef will take everything from struct to } and call it person.
 
void shareLastName(person, toBeShared);
 
int main(int argc, char **argv) {
 
	person boring = { "Frederick", "Greenstone", 42, 2840 }; 
	//^Assign all the values of the struct
	printf("Boring's first name is %s.\n", boring.firstName); 
	//^Print a value of the struct
	printf("Boring's age is %d.\n", boring.age);
	printf("Boring's postcode is %d.\n\n", boring.postCode);
 
	printf("Boring has moved suburbs.\n");
	boring.postCode = 2460; //Change a value of the struct
	printf("Boring's postcode is now %d.\n", boring.postCode);
	printf("But he is usually found at %p.\n\n", &boring);
	shareLastName(boring); //Parse the struct to another function
	printf("Boring tried to make himself younger.\n");
	printf("Although, he is still %d!\n", boring.age); 
	//Demonstrates how structs are copied, not parsed by reference (i.e. arrays)
 
 return EXIT_SUCCESS;

}
 
void shareLastName(person, toBeShared) {
	printf("After being shared, he moved to %p\n", &toBeShared);
	printf("We can still share details about boring.\n");
	printf("I.e. His last name is %s.\n\n", toBeShared.lastName);
	toBeShared.age = 20; //Change a local (copied) version of the struct
}

// Typedef example

typedef [data type] [data name];
typedef unsigned int myNum;





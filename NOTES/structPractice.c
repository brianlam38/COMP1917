/*
Structs

- Structs are used when you need more than one piece of data to describe one thing.
- Arrays can only store one data type inside of it.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// dog struct #1
typedef struct dog {
	const char *name;
	const char *breed;
	int avgHeightCm;
	int avgWeightLbs;

	struct dogFavs favouriteThings;							// NESTED STRUCT
} dog;

// dog struct #2
struct dogFavs {
	char *food;
	char *friend;
} ;

/* EXAMPLE ONE: PRINTING STRUCT DATA */

void main() {
	struct dog cujo = {“Cujo”, “Saint Bernard”, 90, 264};
	
	getDogInfo (cujo); 										// DECLARING FUNCTION #1
}

void getDogInfo (struct dog theDog) { 						// FUNCTION TO PRINT DOG DATA
	printf (“The name of the dog is %s\n”, theDog.name);
	printf (“The breed of the dog is %s\n”, theDog.breed);
	printf (“The average height is %d\n”, theDog.avgHeightCm);
	printf (“The average weight is %d\n”, theDog.avgWeightLbs);
}

/* EXAMPLE TWO: PRINTING MEMORY LOCATIONS OF STRUCT DATA */

void main() {
	struct dog cujo = {“Cujo”, “Saint Bernard”, 90, 264};

	struct dog cujo2 = cujo; 								// declaring 2nd struct + copy/assigning data from struct cujo
	
	getMemoryLocations (cujo);
	getMemoryLocations (cujo2);								// DECLARATION FUNCTION #2
}

void getMemoryLocations (struct dog theDog) {				// FUNCTION TO PRINT MEMORY LOCATION OF DOG DATA
	printf ("Name Location: %d\n", theDog.name);
	printf ("Breed Location: %d\n", theDog.breed);
	printf ("Height Location: %d\n", &theDog.avgHeightCm);	// Not pointer, therefore need &
	printf ("Weight Location: %d\n", &theDog.avgWeightLbs); // Not pointer, therefore need &
}

/* EXAMPLE: NESTED STRUCT */

void main () {
	dog benji = {"Benji", "Silky Terrier", 25, 9, {"Meat", "Joe Camp"}};

	getDogsFavs(benji);
}

void getDogsFavs(dog theDog) {
	printf ("%s loves %s and his friend is %s\n\n",
		theDog.name,
		theDog.favouriteThings.food,
		theDog.favouriteThings.friend);
}

/* EXAMPLE: HOW TO CHANGE INFORMATION */

void main () {

	dog benji = {"Benji", "Silky Terrier", 25, 9, {"Meat", "Joe Camp"}};

	setDogWeightPtr(&benji, 11);
	printf ("The weight in Main() %d\n\n", benji.avgWeightLbs);
	assert (theDog->newWeight == 11);
}


void setDogWeightPtr(dog *theDog, int newWeight) {	// variable newWeight = new info
	theDog->avgWeightLbs = newWeight;

	printf ("The weight was changed to %d\n\n", theDog->newWeight);
	assert (theDog->newWeight == 11);
}





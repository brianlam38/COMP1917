Structs

- Structs are used when you need more than one piece of data to describe one thing.
- Arrays can only store one data type inside of it.

#include <stdio.h>

struct dog {
	const char *name;
	const char *breed;
	int avgHeightCm;
	int avgWeightLbs;
} ;

void getDogInfo (struct dog theDog) { // BUILDING FUNCTION
	printf (“\n”);

	printf (“The name of the dog is %s\n”, theDog.name);
	printf (“The breed of the dog is %s\n”, theDog.breed);
	printf (“The average height is %d\n”, theDog.avgHeightCm);
	printf (“The average weight is %d\n”, theDog.avgWeightLbs);
}

void getMemoryLocations (struct dog theDog) {
	printf (“Name Location: %d\n. theDog.name);
	printf (“Breed Location: %d\n. theDog.breed);
	printf (“Height Location: %d\n. &theDog.avgHeightCm); // Not pointer, therefore needs &
	printf (“Weight Location: %d\n. &theDog.avgWeightLbs); // Not pointer, therefore needs &
}	

void main() {
	struct dog cujo = {“Cujo”, “Saint Bernard”, 90, 264};
	struct dog cujo2 = cujo;
	
	getDogInfo (cujo); // DECLARING FUNCTION

	getMemoryLocations (cujo);
	getMemoryLocations (cujo2);

}
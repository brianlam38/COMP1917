#include <stdio.h>
#include <stdlib.h>

int turtle (int gamera, int achilles) {
	//printf ("call (%d,%d)\n", gamera, achilles);
	gamera = 2;
	achilles = 1;
	while (gamera != 0) {
		if (achilles > 0) {
			achilles = turtle (gamera, achilles-1);
        } else {
            achilles = 1;
		}
	gamera--;
	}
	printf ("%d", achilles);
    return (achilles+1);
}

int main (int argc, char *argv[]) {

	/*
	// QUESTION 11
	printf ("QUESTION 1 ANSWERS:\n");
    typedef unsigned char byte;
    unsigned int nines = 999;
    byte * ptr = (byte *) &nines;
    printf ("%x\n",nines);
    printf ("%x\n",nines * 0x10);
    printf ("%d\n",ptr[0]);
    printf ("%d\n",ptr[1]);
	printf ("%d\n",ptr[2]);
    printf ("%d\n",ptr[3]);

    // QUESTION 12
    int days = 100;
    days -= 365;
    printf("%d", days);
	*/

	return EXIT_SUCCESS;
}



#include <stdio.h>
#include <stdlib.h>

int lower();

int main(int argc, char * argv[]) {
	int count [256];
	int i = 'a';

	while (i <= 'z') {
		printf ("%c = %d\n", i, count[i]);
		i++;
	}

return EXIT_SUCCESS;
}

// Uppercase --> Lowercase function
int lower() {
	int a = 0; 

    if ((a >= 65) && (a <= 90)) {
        a = a + 32; 
    }

    return a;  
}

// Statistics Function

#include <stdio.h>
#include <stdlib.h>

char encode (char letter);

int main(int argc, char * argv[]) {
	if (letter <= 'm' && letter >= 'a') {
		letter += 13;
	} else if (letter >= 'n' && letter <= 'z') {
		letter -= 13;
	}

	if (letter <= 'M' && letter >= 'A') {
		letter += 13;
	} else if (letter >= 'N' && letter <= 'Z');
		letter -= 13;
	}

	return EXIT_SUCCESS;
}

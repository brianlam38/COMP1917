// extract.h
// funtions and types used by extract.c
// richard buckland
// 13 April 2014
// do not alter or submit this file, 
// we'll use our own copy when marking it

#define
 
typedef struct _triordinate { // declaring a function, of type struct (triordinate)
   double x; // 1st data = double x (decimals)
   double y; // 2nd data = double y (decimals)
   int z; // 3rd data = int z (whole no)
} triordinate;
 
 
triordinate extract (char *message) { // Function to extract the X Y Z value

}

/* store everything before 'x' into the rubbish location */
/* include everything after 'x', until 'y' */
/* store everything after 'y', until 'z' */

double myAtoD (char *message) {
	char message[30];
	char *c = getchar();
	while (c != 'x') {
		message[i] = c; // storing chars into variable c
		message++; // increment storing chars
		while (c != 'y') {
			message[i] = d; // storing chars into variable d
			message++;
		}
	}
} 
 
long myAtoL (char *message) {
		/* store everything before 'z' into the rubbish location */
		/* store everything after 'z', until '.bmp' */
} 




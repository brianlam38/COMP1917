#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {

int canaryA = 42;
int testArray[10] = {0,1,2,3,4,5,6,7,8,9};
int canaryB = 99;
 
int index;
printf ("Enter an array index between 0 and 9\n");
scanf ("%d", &index);
printf ("testArray[%d]=%d,\n",index, testArray[index]);
printf ("testCanaryB=%d, testCanaryA=%d", canaryB, canaryA);

return EXIT_SUCCESS;
}

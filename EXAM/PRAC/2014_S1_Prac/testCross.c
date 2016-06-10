#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "cross.h"

// you can assume size is an odd positive value
// your drawCross function is to print on the screen a cross 
// made of asterisks which fits inside a square of
// side length "size"

/* 
compile and test your code as follows

$ gcc -Wall -Werror -std=c99 -O -o partP1 cross.c testCross.c

examples

$ ./partP1 3
* *
 *
* *

$ ./partP1 5
*   *
 * *
  *
 * *
*   *

$ ./partP1 7
*     *
 *   *
  * *
   *
  * *
 *   *
*     *

$ ./partP1 1
*

*/

int main (int argc, char *argv[]) {
    assert (argc > 1);
    int size = atoi (argv[1]);
    assert ((size%2) != 0);
    drawCross (size);
    return EXIT_SUCCESS;
}

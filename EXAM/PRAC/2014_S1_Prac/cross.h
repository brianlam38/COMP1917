// cross.h
// don't alter this file


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

// you can assume size is an odd positive value
// this function is to print on the screen a cross 
// made of asterisks which fits inside a square of
// side length "size"
void drawCross (int size);

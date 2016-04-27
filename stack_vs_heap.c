/*  
	STACK EXAMPLE

	- On lines 10, 11, 12 three variables are declared: 1 x int, 1 x double, 1 x array of 3 doubles
	- These three variables are pushed onto the stack as soon as the main() function allocates them.
	- When the main() function exits (and the program stops), these variables are removed from the stack.
	- Similarly, in the multiplyByTwo function, the variable double "twice" is pushed onto the stack
	  as soon as multiplyByTwo() allocates it. As soon as the multiplyByTwo() function exits, the variable
	  is removed from the stack and is gone forever.

	- By using "static" when declaring your variables, the stack variable will stay even when the creator
	  function exits.
*/

#include <stdio.h>

double multiplyByTwo (double input) {
  double twice = input * 2.0;
  return twice;
}

int main (int argc, char *argv[])
{
  int age = 30;
  double salary = 12345.67;
  double myList[3] = {1.2, 2.3, 3.4};

  printf("double your salary is %.3f\n", multiplyByTwo(salary));

  return 0;
}

/*
	HEAP EXAMPLE

	- Using "malloc()" to allocate memory on the HEAP and then using "free()" to de-allocate it.
	- The malloc(), calloc(), free() functions deal with POINTERS rather than actual values.
	- Reminder: POINTERS are a data type in C that store addresses in memory instead of storing actual values
	  E.g. The variable *twice is not a double, but a POINTER TO A DOUBLE. It's an address in memory
	  	   where the double is stored.
*/

#include <stdio.h>
#include <stdlib.h>

double *multiplyByTwo (double *input) {
  double *twice = malloc(sizeof(double));
  *twice = *input * 2.0;
  return twice;
}

int main (int argc, char *argv[])
{
  int *age = malloc(sizeof(int));
  *age = 30;
  double *salary = malloc(sizeof(double));
  *salary = 12345.67;
  double *myList = malloc(3 * sizeof(double));
  myList[0] = 1.2;
  myList[1] = 2.3;
  myList[2] = 3.4;

  double *twiceSalary = multiplyByTwo(salary);

  printf("double your salary is %.3f\n", *twiceSalary);

  free(age);
  free(salary);
  free(myList);
  free(twiceSalary);

  return 0;
}




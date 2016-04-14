/*
	This is a demo C program
	By: Angela Finlayson
	Date: 29/02/2016
*/

#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1
#define LEGAL_AGE 18

int main(int argc, char ** argv) {

	printf("it is so good to C you! \n\n\n\n ");
	printf("Goodbye\n");

	return EXIT_SUCCESS;
}

/*
	Variables
	Setting age as the variable
*/

int main(int argc, char ** argv) {

	into age:
	age = 90;

	printf("I am %d years old \n",age);

	return EXIT_SUCCESS;
}

/*
	Variables
	Setting other variables
*/

int main(int argc, char ** argv) {

	int age:
	age = 90;

	int height = 170;

	printf("I am %d years old and %d cm tall\n",age,height);

	return EXIT_SUCCESS;
}

/*
	using scanf
	EXAMPLE FROM INTERNET
*/

#include <stdio.h>

	int main()
{
	int myvariable;

	printf("Enter a number:");
	scanf("%d",&myvariable);
	printf("%d",myvariable);

	return 0;

}

/*
	using scanf
	COMP1917 example
*/

int main(int argc, char ** argv) {

	scanf("%d,&age");

	printf("You are %d years old\n",age);

	return EXIT_SUCCESS
}

/*
	using scanf and IF statements
*/

int main(int argc, char ** argv) {

	scanf("%d,&age");

	if(age < 3) (
		printf("Are you sure?\n",age);
		printf("You are very clever\n");
	) else if (age < 10)
		printf("Would you like a softdrink?\n");
	) else if (age > 90) (
		printf("Would you like a sherry?\n");
	) else
		printf("Would you like a beer?\n");
	)

	return EXIT_SUCCESS;
}

/*
	True or False statements (Booleans)
*/

int main(int argc, char ** argv) {
	int age;
	int driving; //0 false = true

	printf("Please enter your age: ");
	scanf(%d,&age);
	printf("Are you driving (0 or 1 ) : ");
	scanf("%d",&driving);

	// < > <= >= == !==
	if(age < 3) (
		printf("Are you sure?\n",age);
		printf("You are very clever\n");
	) else if (age < 10)
		printf("Would you like a softdrink?\n");
	) else if (age > 90) (
		printf("Would you like a sherry?\n");
	// Alternate ELSE IF statement

	) else if (age > 90) (
		if(driving )

	// END of Alternate ELSE IF statement
	) else
		if(driving == 0) (
			printf("Would you like a beer?\n");
		) else (
			printf("Would you like a water?\n");
		)

	return EXIT_SUCCESS;
}

---------------------------------------------------------------------------------------------------------------------

/*
	Second demo program

	Doing maths / remainders
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
	into x = 15;
	int y;
	y = x/2;
	remainer = x%2;s

	printf("%d divided by 2 is is %d R %d\n",x,y,remainder);
	return EXIT_SUCCESS

}

/*
	Second demo program

	Doing maths / remainders
*/

int main(int argc, char ** argv) {
	int x;
	int y;
	scanf("%d",&x);

	r = x%2;

	if(r == 1);
		printf("Odd\n");
	} else {
		printf("Even\n");
	}

	return EXIT_SUCCESS;
}


---------------------------------------------------------------------------------------------------------------------

/*
	Practice Sesh
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
	if (r == 1);
		printf()
}




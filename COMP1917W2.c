
//Note: putting things through compiler: gcc -Wall -Werror -0 -o myProgram myProgram.c
//Using C Maths Library

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int maximum(int n1,int n2);

int main(int argc, char ** argc[]){
	double number;
	double result;
	printf("Enter a numer :");
	scanf("%lf",&number);
	result = pow(numer,2);

	printf("%.10lf is %lf\n",number,result);

	return EXIT_SUCCESS;
}

/*
	myFirstFunctions.c
	need to include -lm when compiling to find the math library
*/

/*
	This function asks the user to input two numnbers, then it tells
	the person which number is the bigger / biggest number.
*/

//	QUESTION: How can this function be modified, such that the program can still sort out the largest (and/ or) smallest
//	number, if the user puts in an X amount of numbers?

int main(int argc, char ** argc[]){

	int number1;
	int number2;
	int biggest;

	printf("Enter 2 numbers : ");
	scanf("%d %d",&number1,&number2);

	if(number1 > number2){
		biggest = number1;
	} else {
		biggest = number2;
	}
	printf("%d is the biggest\n",biggest);

	return EXIT_SUCCESS
}

int maximum(int n1, int n2){
	int biggest;
	if(n1 > n2){
		biggest = n1;
	} else {
		//MISSING STILL NEED INPUT
	}
}

/*
	Void Function

	printMessage: no need to give an input
	printNumber: relies on an input / number
	doCalculation: relies on an input
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printMessage(void);
void printNumber(int n);
int doCalculation(int n);

int main(int argc, char ** argv[]){
	int result;

	printMessage();
	printMessage();

	printNumber(2);
	printNumber(10);

	result = doCalculation(2);
	printf("Result is %d\n",result);

	result = doCalculation(3);
	printf("Result is %d\n",result);

	return EXIT_SUCCESS;
}

void printMessage(void){
	printf("I have no input. The same things...")
}

void printNumber(int n){

}

/*
	Creating maths functions with X and Y

	This function defines two integers "num1" and "num2", where:
	--> num1 = 10
	--> num2 = f1(10)

	f1 = (f2(x,x*2))
*/

int main(int argc, char ** argv[]){
	int num1 = 10;

	int num2 = f1(num1);
	printf("Answer is %d\n",num2);

	return 0;
}

int f1(int x){
	return (f2(x,x*2)+1);
}

int f2(int x,int y){
	return x+y;
}






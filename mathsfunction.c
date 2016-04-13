/*
	Maths Function
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char * argv[]){
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


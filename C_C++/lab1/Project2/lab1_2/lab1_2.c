//Chapter 3: Lab 1: Getting started
//Author: Kamila Shirinova.


#define _CRT_SECURE_NO_DEPRECATE

#include<stdio.h>
#include<conio.h>


int main()
{
	//Assignment 3.3.3:

	int variable1;
	int variable2;
	
	
	// Get user input
	printf("enter the operands (integers only), please:\n\n");
	printf("1st operand =\n");
	scanf("%d", &variable1);
	getchar();

	printf("2nd operand =\n");
	scanf("%d", &variable2);
	getchar();


	// ...
	printf("%d + %d = %d\n", variable1, variable2, variable1 + variable2);

	printf("%d - %d = %d\n", variable1, variable2, variable1 - variable2);

	printf("%d * %d = %d\n", variable1, variable2, variable1 * variable2);

	printf("%d / %d = %d\n", variable1, variable2, variable1 / variable2);

	printf("%d %% %d = %d\n", variable1, variable2, variable1 % variable2);

	getchar();
	return 0;
}
//Chapter 3: Lab 1: Getting started
//Author: Kamila Shirinova.

#include<stdio.h>
#include<conio.h>

#define _CRT_SECURE_NO_DEPRECATE

int main()
{
	//Assignment 3.3.3:

	int variable1;
	int variable2;

	

	printf("enter the operands (integers only), please:\n");

	printf("1st operand =\n");

	scanf("%d", &variable1);
	getchar();

	printf("2nd operand =\n");

	scanf("%d", &variable2);
	getchar();



	printf("%d + %d = %d\n", variable1, variable2, variable1 + variable2);

	printf("%d - %d = %d\n", variable1, variable2, variable1 - variable2);

	printf("%d * %d = %d\n", variable1, variable2, variable1 * variable2);

	printf("%d / %d = %d\n", variable1, variable2, variable1 / variable2);

	printf("%d %% %d = %d\n", variable1, variable2, variable1 % variable2);

	getchar();
	return 0;
}
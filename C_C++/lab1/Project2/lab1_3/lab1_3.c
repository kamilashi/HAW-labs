//Chapter 3: Lab 1: Getting started
//Author: Kamila Shirinova.


#define _CRT_SECURE_NO_DEPRECATE

#include<stdio.h>
#include<conio.h>


int main()
{
	//Assignment 3.3.3:

	int year;
	int copyYear;
	int sum = 0;
	
	

	printf("enter the year please:\n\n");


	scanf("%d", &year);
	getchar();

	copyYear = year;

	while(copyYear != 0)
	{
		int remainder = copyYear % 10;
		sum += remainder;
		copyYear /= 10;
	}

	printf("\n\nthe digit sum of %d is %d\n", year, sum);

	getchar();
	return 0;
}
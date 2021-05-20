//Chapter 3: Lab 1: Getting started
//Authors: Kamila Shirinova. Gyeongji Kang


#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdbool.h>											 //to use the bool type

int isNorthernHemisphere(double);
int isSouthernHemisphere(double);

int main()
{
	double latitude, longitude;
	int flag = 0;

	/* Get user input */
	printf("please, enter the coordinates\n");
	do                                                          //the loop to get the input values first and then check if those are correct
	{
		if (flag == 1)											//flag = 1 indicates that the previous attempt to get 
		{                                                       //the correct input data has failed (incorrect input activates the loop)
			printf("Wrong coordinates.Try again:\n");			 
		}
		printf("latitude:\n");
		scanf("%lf", &latitude);
		getchar();
		printf("longitude:\n");
		scanf("%lf", &longitude);
		getchar();
		flag = 1;												//flagthat was initially set to 0 is now set to 1 indicating 
																//that the first attempt to get input is over.
	} while ((latitude <= -90.0) || (latitude >= 90.0) || (longitude <= -180.0) || (longitude >= 180.0)); //cheching whether the input is correct. if not, ask user to do it again.

	/* Check hemisphere and print result */
	if (latitude == 0.0)
	{
		printf("on equator");                                  //checking whether the location is on the northern hemisphere, southern hemisphere or on the equator.
	}
	else if (isNorthernHemisphere(latitude))
	{
		printf("in northern hemisphere");
	}
	else if (isSouthernHemisphere(latitude))
	{
		printf("in southern hemisphere");
	}

	getchar();
	return 0;
}

int isNorthernHemisphere(double latitude)         //bool function that returns 1 if the location is on the northern hemisphere, 0 otherwise
{
	if (latitude > 0.0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isSouthernHemisphere(double latitude)        //bool function that returns 1 if the location is on the southern hemisphere, 0 otherwise
{
	if (latitude < 0.0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
// Date: 27.11.2019
// LAB 4: chapter6. Array and Pointers
// Task: 6.2.1 Route Distances
// Author: Gyeongji Kang, Kamila Shirinova
//

#define _CRT_SECURE_NO_DEPRECATE	// Else MSVC++ prevents using scanf() (concern: buffer overflow)
#define PI 3.14159265359

#include <stdio.h>
#include <math.h>

double deg2Rad(double degree);
double distanceKm(double lat1, double lat2, double lon1, double lon2);

int main(void)
{   //declaring arrays and variables
	double latitudes[] = { 53.557029, 53.557166, 53.557274, 53.560288, 53.561306, 53.562015, 53.558241, 53.557900, 53.557203 };
	double lon[] = { 10.022918, 10.021343, 10.020297, 10.014906, 10.015426, 10.016568, 10.023244, 10.022142, 10.022632 };
	int size = sizeof latitudes / sizeof latitudes[0];
	double sumDistance = 0.0;

	for (int i = 0; i < size - 1; i++)
	{
		sumDistance += distanceKm(latitudes[i], latitudes[i + 1], lon[i], lon[i + 1]); // Sum all of distances between two locations
	}

	printf("The overall distance in km is: %lf km", sumDistance);

	getchar();
	return 0;
}

/* Converting degree to Radian */
double deg2Rad(double degree)
{
	return (degree * PI) / 180;
}

/* Calculating a distance of two locations in km */
double distanceKm(double lat1, double lat2, double lon1, double lon2)
{
	return 6378.388*acos(sin(deg2Rad(lat1)) * sin(deg2Rad(lat2)) + cos(deg2Rad(lat1)) * cos(deg2Rad(lat2)) * cos(deg2Rad(lon2) - deg2Rad(lon1)));
}
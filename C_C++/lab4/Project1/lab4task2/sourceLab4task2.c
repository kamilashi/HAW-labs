//
// Date: 27.11.2019
// LAB 4: chapter6. Array and Pointers
// Task: 6.2.2 Maximum distance(2-D arrays)
// Author: Gyeongji Kang, Kamila Shirinova
//

#define _CRT_SECURE_NO_DEPRECATE	// Else MSVC++ prevents using scanf() (concern: buffer overflow)
#define PI 3.14159265359

#include <stdio.h>
#include <math.h>

double deg2Rad(double degree);
double distanceKm(double lat1, double lat2, double lon1, double lon2);
//double matrixMx2(double geoCoordinate[][2], double returnValue[3], int rows);
void matrixMx2(const double geoCoordinate[][2], int *pointerToA, int *pointerToB, double *pointerToLargestDistance, int rows);

int main(void)
{
	char *nameOfLocation[7] = { "hawHamburg", "eiffelTower", "palmaDeMallorca", "lasVegas", "copacabana", "waikikiBeach", "surfersParadise" };
	double geoCoordinate[7][2] = { { 53.557078, 10.023109 }, { 48.858363, 2.294481}, { 39.562553, 2.661947 }, { 36.156214, -115.148736},
									{ -22.971177, -43.182543 }, { 21.281004, -157.837456 }, { -28.002695, 153.431781 } };
	//variables to store the indexes of A and B and the distance and pointers to their address
	int largestDistanceA, largestDistanceB; // Store the index of location B
	double largestDistanceKm;

	matrixMx2(geoCoordinate, &largestDistanceA, &largestDistanceB, &largestDistanceKm, 7);

	printf("\n <%s> and <%s> have the largest distance (%lf km).\n\n", nameOfLocation[largestDistanceA], nameOfLocation[largestDistanceB], largestDistanceKm);
	printf(" You'd better not walk. Take a flight, instead.");

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
	double globladistance = 6378.388*acos(sin(deg2Rad(lat1)) * sin(deg2Rad(lat2)) + cos(deg2Rad(lat1)) * cos(deg2Rad(lat2)) * cos(deg2Rad(lon2 - lon1)));
	return globladistance;
}

/* A fuction that receives Mx2 matrix of coordinates as parameter
   - Decide the location that has the largest distance
   - Return the value of the largest distance and the index of two locations */

void matrixMx2(const double geoCoordinate[][2], int *indexA, int *indexB, double *pointerToLargestDistance, int rows)
{
	double maxDistance = 0;

	for (int i = 0; i < rows - 1; i++) //indexA = index of location A
	{
		for (int j = i + 1; j < rows; j++) //indexB = index of location B
		{
			double oneDistance = distanceKm(geoCoordinate[i][0], geoCoordinate[j][0], geoCoordinate[i][1], geoCoordinate[j][1]);

			if (maxDistance < oneDistance) // check whether it has largest distance comparing with before max value.
			{
				maxDistance = oneDistance;
				*indexA = i;         //storing the indexes
				*indexB = j;
				*pointerToLargestDistance = maxDistance;
			}
		}
	}
}
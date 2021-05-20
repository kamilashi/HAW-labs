// Date: 10.12.2019
// LAB 5: chapter6. Array and Pointers
// Task :7.2.1 Travel planning using double arrays
// Author: Gyeongji Kang, Kamila Shirinova
//

#define _CRT_SECURE_NO_DEPRECATE	// Else MSVC++ prevents using scanf() (concern: buffer overflow)
#define PI 3.14159265359

#include <stdio.h>
#include <math.h>

double deg2Rad(double degree);
double distanceKm(double lat1, double lat2, double lon1, double lon2);

struct geoCoord        //creating a structure to hold latitudes and longitudes
{
	double latitudeDeg, longitudeDeg;
};

int main(void)
{   //declaring arrays and variables
	double latitude, longitude;
	float numberOfWaypoints;

	printf("Enter the number of waypoints: ");
	int inputNumOfWp = scanf("%f", &numberOfWaypoints);
	while ((!inputNumOfWp) || (numberOfWaypoints != (int)numberOfWaypoints) || (numberOfWaypoints <= 0))    //checking if the input is correct
	{
		printf("Try again (expected number >= 0): ");
		if (!inputNumOfWp)
		{
			while (getchar() != '\n') {};						  //the scanf keeps looping until 
		}														  //the user inputs a correct value
		inputNumOfWp = scanf("%f", &numberOfWaypoints);
	}
	getchar();

	//Allocating array of structures dynamically
	struct geoCoord *waypoints = malloc(sizeof(struct geoCoord) * numberOfWaypoints);

	printf("Enter waypoints as <latitude> <longitude>:\n");

	for (int i = 0; i < (int)numberOfWaypoints; i++)
	{
		printf("Waypoint %d: ", i + 1);
		int inputLat = scanf("%lf", &latitude);
		while ((!inputLat) || (latitude < 0))    //checking if the input is correct
		{
			printf("Try again (expected number >= 0): ");
			if (!inputLat)
			{
				while (getchar() != '\n') {};						  //the scanf keeps looping until 	
			}														//the user inputs a correct value
			int inputLat = scanf("%lf", &latitude);
		}
		waypoints[i].latitudeDeg = latitude;
		getchar();

		int inputLon = scanf("%lf", &longitude);
		while ((!inputLon) || (longitude < 0))    //checking if the input is correct
		{
			printf("Try again (expected number >= 0): ");
			if (!inputLon)
			{
				while (getchar() != '\n') {};						  //the scanf keeps looping until 	
			}														//the user inputs a correct value
			int inputLon = scanf("%lf", &inputLon);
		}
		waypoints[i].longitudeDeg = longitude;
		getchar();
	}

	double sumDistance = 0.0;
	for (int i = 0; i < numberOfWaypoints - 1; i++)
	{
		sumDistance += distanceKm(waypoints[i].latitudeDeg, waypoints[i + 1].latitudeDeg, waypoints[i].longitudeDeg, waypoints[i + 1].longitudeDeg); // Sum all of distances between two locations
	}

	printf("By taking this route you will travel %lf km", sumDistance);

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
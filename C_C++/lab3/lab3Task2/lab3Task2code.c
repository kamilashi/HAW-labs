//Chapter 3: Lab 1: Getting started
//Authors: Kamila Shirinova. Gyeongji Kang

#define _CRT_SECURE_NO_DEPRECATE
#define PI 3.1415926535
#include <stdio.h>
#include <math.h>

double degreesToRadians(double);
double localDistanceKm(struct location a, struct location b);
double distanceKm(struct location a, struct location b);

struct location          //creating a template for data type Location, which has 4 properties - latitude and longitute in degrees and in radioans.
{                         
	double latDeg, lonDeg;
	double latRad, lonRad;
};

int main()
{
	/*declaring variables*/
	double localDistanceTempKm, distanceTempKm;
	struct location haw;
	struct location eiffelTower;
	struct location palmaDeMallorca;
	struct location lasVegas;
	struct location copacabana;
	struct location waikikiBeach;
	struct location surfersParadise;

	/*instanciating the objects of type location */
	haw.latDeg = 53.557078;
	haw.lonDeg = 10.023109;
	haw.latRad = degreesToRadians(haw.latDeg);
	haw.lonRad = degreesToRadians(haw.lonDeg);

	eiffelTower.latDeg = 48.858363;
	eiffelTower.lonDeg = 2.294481;
	eiffelTower.latRad = degreesToRadians(eiffelTower.latDeg);
	eiffelTower.lonRad = degreesToRadians(eiffelTower.lonDeg);

	palmaDeMallorca.latDeg = 39.562553;
	palmaDeMallorca.lonDeg = 2.661947;
	palmaDeMallorca.latRad = degreesToRadians(palmaDeMallorca.latDeg);
	palmaDeMallorca.lonRad = degreesToRadians(palmaDeMallorca.lonDeg);

	lasVegas.latDeg = 36.156214;
	lasVegas.lonDeg = -115.148736;
	lasVegas.latRad = degreesToRadians(lasVegas.latDeg);
	lasVegas.lonRad = degreesToRadians(lasVegas.lonDeg);

	copacabana.latDeg = -22.971177;
	copacabana.lonDeg = -43.182543;
	copacabana.latRad = degreesToRadians(copacabana.latDeg);
	copacabana.lonRad = degreesToRadians(copacabana.lonDeg);

	waikikiBeach.latDeg = 21.281004;
	waikikiBeach.lonDeg = -157.837456;
	waikikiBeach.latRad = degreesToRadians(waikikiBeach.latDeg);
	waikikiBeach.lonRad = degreesToRadians(waikikiBeach.lonDeg);

	surfersParadise.latDeg = -28.002695;
	surfersParadise.lonDeg = 153.431781;
	surfersParadise.latRad = degreesToRadians(surfersParadise.latDeg);
	surfersParadise.lonRad = degreesToRadians(surfersParadise.lonDeg);
	
	/* calculating and printing the local ang global distances */
    localDistanceTempKm = localDistanceKm(haw, eiffelTower);
	printf("\nlocal distance between HAW Hamburg and the Eiffel Tower =  %4.1f\n", localDistanceTempKm);
																														//haw - Eiffel Tower
	distanceTempKm = distanceKm(haw, eiffelTower);
	printf("distance between HAW Hamburg and the Eiffel Tower =  %4.1f\n", distanceTempKm);

	localDistanceTempKm = localDistanceKm(haw, palmaDeMallorca);
	printf("\nlocal distance between HAW Hamburg and Palma De Mallorca =  %4.1f\n", localDistanceTempKm);
																														//haw - Palma De Mallorca
	distanceTempKm = distanceKm(haw, palmaDeMallorca);
	printf("distance between HAW Hamburg and Palma De Mallorca =  %4.1f\n", distanceTempKm);

	localDistanceTempKm = localDistanceKm(haw, lasVegas);
	printf("\nlocal distance between HAW Hamburg and Las Vegas =  %4.1f\n", localDistanceTempKm);
																														//haw - Las Vegas
	distanceTempKm = distanceKm(haw, lasVegas);
	printf("distance between HAW Hamburg and Las Vegas =  %4.1f\n", distanceTempKm);

	localDistanceTempKm = localDistanceKm(haw, copacabana);
	printf("\nlocal distance between HAW Hamburg and Copacabana =  %4.1f\n", localDistanceTempKm);
																														//haw - Copacabana
	distanceTempKm = distanceKm(haw, copacabana);
	printf("distance between HAW Hamburg and Copacabana =  %4.1f\n", distanceTempKm);

	localDistanceTempKm = localDistanceKm(haw, waikikiBeach);
	printf("\nlocal distance between HAW Hamburg and Waikiki Beach =  %4.1f\n", localDistanceTempKm);
																														//haw - Waikiki Beach
	distanceTempKm = distanceKm(haw, waikikiBeach);
	printf("distance between HAW Hamburg and Waikiki Beach =  %4.1f\n", distanceTempKm);

	localDistanceTempKm = localDistanceKm(haw, surfersParadise);
	printf("\nlocal distance between HAW Hamburg and Surfer’s Paradise =  %4.1f\n", localDistanceTempKm);
																														//haw - Surfer’s Paradise
	distanceTempKm = distanceKm(haw, surfersParadise);
	printf("distance between HAW Hamburg and Surfer’s Paradise =  %4.1f\n", distanceTempKm);

	getchar();
	return 0;
}

/*converting degrees to radians*/
double degreesToRadians(double deg)
{
	return (deg * PI) / 180.0;
}

/*function to calculate local distances*/
double localDistanceKm(struct location a, struct location b)
{
	double y = 111.3 * fabs(a.latDeg - b.latDeg);
	double x = 111.3 * cos((a.latRad + b.latRad) / 2) * fabs(a.lonDeg - b.lonDeg);

	return sqrt(x * x + y * y);
//	return sqrt(pow(x, 2) + pow(y, 2));
}

/*function to calculate global distances*/
double distanceKm(struct location a, struct location b)
{
	return 6378.388 * (acos(sin(a.latRad) * sin(b.latRad) + cos(a.latRad) * cos(b.latRad) * cos(degreesToRadians(b.lonDeg - a.lonDeg))));
}
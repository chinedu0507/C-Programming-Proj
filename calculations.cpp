#include <stdlib.h>
#include "calculations.h"
#define SIZE 720

double getTotalWaterUsage(double waterUsage[])
{
	int i;
	double sum = 0.0;

	for (i = 0; i < SIZE; i++)
	{
		sum = sum + waterUsage[i];
	}

	return sum;
}

double getTotalBill(double waterUsage[], double tariff)
{
	int i;
	double sum = 0.0;

	for (i = 0; i < SIZE; i++)
	{
		sum = sum + waterUsage[i];
	}

	return sum*tariff;
}

int checkForLeak(double waterUsage[])
{
	//int j, counter = 4;

	//for()








/*	int i, j, counter = 4;

	for (i = 1; i < SIZE; i = i + 24)
	{
		for (j = i; j < i + counter; j++)
		{
			if (waterUsage[j] != 0)
				return monthHourToDay(j);
		}
	}

	return 0;*/
}
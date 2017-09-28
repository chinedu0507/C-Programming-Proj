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

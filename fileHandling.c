#include "fileHandling.h"
#include <stdlib.h>
#include <stdio.h>
#include "stringHandling.h"
#include "calculations.h"
//#define _CRT_SECURE_NO_WARNINGS

void readMetadataFromFile(ApartmentData *data1, ApartmentData *data2, ApartmentData *data3)
{
	FILE *aptPtr; // apartment file pointer

	// Check if file opens
	if ((aptPtr = fopen("apartments_metadata.txt", "r")) == NULL)
	{
		puts("File could not be opened");
	}
	else { // Read names and tariffs from file

		fscanf(aptPtr, "%s%s%lf", data1->ownerName, data1->ownerSurname, &data1->tariff);
		fscanf(aptPtr, "%s%s%lf", data2->ownerName, data2->ownerSurname, &data2->tariff);
		fscanf(aptPtr, "%s%s%lf", data3->ownerName, data3->ownerSurname, &data3->tariff);
	}
	fclose(aptPtr);
}

void readUsageFromFile(double usage1[], double usage2[], double usage3[])
{
	FILE *water_usage;

	char *day = malloc(sizeof(char) * 2);
	char *time = malloc(sizeof(char) * 5);
	char *uusage1 = malloc(sizeof(char) * 6);
	char *uusage2 = malloc(sizeof(char) * 6);
	char *uusage3 = malloc(sizeof(char) * 6);
	char csvstring[50];
	char header[50];
	char *css;
	int i;

	if ((water_usage = fopen("water_usage.csv", "r")) == NULL)
	{
		puts("Did not open the file");
	}
	else
	{
		// scan the first line of the file into the variable, header
		fscanf(water_usage, "%s", header);
		for (i = 0; i < 720; i++)
		{
			// now the fscanf reads in values
			fscanf(water_usage, "%s", csvstring);
			css = csvstring;
			csvToStrings(css, day, time, uusage1, uusage2, uusage3);

			usage1[i] = strtod(uusage1, NULL);
			usage2[i] = strtod(uusage2, NULL);
			usage3[i] = strtod(uusage3, NULL);

		//	printf("%.3lf %.3lf %.3lf\n", usage1[i], usage2[i], usage3[i]);
		}
	}
	fclose(water_usage);
}

void writeBuildingReport(double apartment1Usage[], double apartment2Usage[], double apartment3Usage[], ApartmentData apartment1Data, ApartmentData apartment2Data, ApartmentData apartment3Data, char *filename)
{
	FILE *reportPtr;
	double total_usage = 0.0;
	double total_bill = 0.0;

	// Calculations
	total_usage = getTotalWaterUsage(apartment1Usage) + getTotalWaterUsage(apartment2Usage) + getTotalWaterUsage(apartment3Usage);
	total_bill = getTotalBill(apartment1Usage, apartment1Data.tariff) + getTotalBill(apartment2Usage, apartment2Data.tariff) + getTotalBill(apartment3Usage, apartment3Data.tariff);

	double temp = getTotalWaterUsage(apartment1Usage);
	if (temp < getTotalWaterUsage(apartment2Usage))
	{
		temp = getTotalWaterUsage(apartment2Usage);
	}
	else if (temp < getTotalWaterUsage(apartment3Usage))
		temp = getTotalWaterUsage(apartment3Usage);

	if ((reportPtr = fopen(filename, "w")) == NULL)
	{
		puts("File could not be opened");
	}
	else {
		fprintf(reportPtr, "Total usage: %.3lf kl\n", total_usage);
		fprintf(reportPtr, "Total bill: R%.2lf\n", total_bill);
		if (temp == getTotalWaterUsage(apartment1Usage))
		{
			fprintf(reportPtr, "Most usage: %s %s (%.3lf kl)\n", apartment1Data.ownerName, apartment1Data.ownerSurname, getTotalBill(apartment1Usage, apartment1Data.tariff));
		}
		else if (temp == getTotalWaterUsage(apartment2Usage))
		{
			fprintf(reportPtr, "Most usage: %s %s (%.3lf kl)\n", apartment2Data.ownerName, apartment2Data.ownerSurname, getTotalBill(apartment2Usage, apartment2Data.tariff));
		} else
			fprintf(reportPtr, "Most usage: %s %s (%.3lf kl)\n", apartment3Data.ownerName, apartment3Data.ownerSurname, getTotalBill(apartment3Usage, apartment3Data.tariff));
	}
	fclose(reportPtr);

}

void saveCompactUsage(double usage[], int apartment)
{
	int i;
	FILE *PtrToBin;
	char filename[40];

	// Assigning the apartment number to the bin file
	sprintf(filename, "compact_usage_%d.bin", apartment);

	if ((PtrToBin = fopen(filename, "wb")) == NULL)
	{
		puts("Could not open file for writing");
	}
	else
	{
		for (i = 0; i < 720; i++)
		{
			if (usage[i] != 0) // if usage is not equals to zero
			{
				// Write to binary file
				fwrite(&i, sizeof(int), 1, PtrToBin);
				fwrite(&usage[i], sizeof(double), 1, PtrToBin);
			}
		}
	}

	fclose(PtrToBin);
	
}
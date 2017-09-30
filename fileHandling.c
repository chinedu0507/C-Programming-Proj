#include "fileHandling.h"
#include <stdlib.h>
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

void readMetadataFromFile(ApartmentData *data1, ApartmentData *data2, ApartmentData *data3)
{
	FILE *aptPtr; // apartment file pointer

	// Check if file opens
	if ((aptPtr = fopen("apartments_metadata.txt", "r")) == NULL)
	{
		puts("File could not be opened");
	}
	else { // Read names and tariffs from file
		printf("%-6s%-8s%s\n", "Name", "Surname", "Tariff");
		fscanf(aptPtr, "%7s%7s%3.2lf\n", &data1->ownerName, &data1->ownerSurname, &data1->tariff);
		printf("%s %s %.2lf", &data1->ownerName, &data1->ownerSurname, &data1->tariff);

		/*while (!feof(aptPtr)) // while not at the end of the file
		{
			printf("%-10s%-13s%s\n", "Name", "Surname", "Tariff");
			printf("%s %s %lf", &data1->ownerName, &data1->ownerSurname, &data1->tariff);
			//fscanf(aptPtr, "%7s%7s%lf", &data1->ownerName, &data1->ownerSurname, &data1->tariff);
		}*/
	}
	fclose(aptPtr);

	// Print the data to confirm that the data was indeed read in...TEST FOR APARTMENT DATA 1 FIRST
}

void readUsageFromFile(double usage1[], double usage2[], double usage3[])
{

}
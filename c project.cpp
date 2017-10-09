// This will be my main file

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "time.h"
#include "apartments.h"
#include "calculations.h"
#include "fileHandling.h"

#define SIZE 720
void printApartmentReport(double waterUsage[], ApartmentData data);

int main()
{
	// Program variables
	int option;
	int menu_seven;
	int apartment;
	int i, j, k;
	char filename[50];

//	setbuf(stdout, 0);

	// Occupants data
	ApartmentData AptOne;
	ApartmentData AptTwo;
	ApartmentData AptThree;
	double apartment1Usage[SIZE];
	double apartment2Usage[SIZE];
	double apartment3Usage[SIZE]; 

	// Reading in data from files
	readMetadataFromFile(&AptOne, &AptTwo, &AptThree);
	readUsageFromFile(apartment1Usage, apartment2Usage, apartment3Usage);

	// Menu
	puts("\nRP143 Water Calculator");
	puts("1. Print usage patter for apartment");
	puts("2. Calculate and print total usage for apartment (in kl)");
	puts("3. Calculate and print total bill for apartment (in R)");
	puts("4. Print apartment usage report to screen");
	puts("5. Check building for leaks and print leak report");
	puts("6. Write building water usage report to text file");
	puts("7. Save or print compact binary usage file for apartment");
	puts("8. Determine and print hour with greatest usage for apartment");
	puts("10. Exit");

	printf("\nChoose an item from the menu: ");
	scanf_s(" %d", &option);

	while (option != 10)
	{
		printf("\nChoose apartment(1, 2 or 3): ");
		scanf_s(" %d", &apartment);

		switch (option)
		{
		case 1:
			puts("\nActive water usage report:");
			if (apartment == 1)
			{
				for (i = 0; i < SIZE; i++)
				{
					if (apartment1Usage[i] != 0)
					{
						printf("Day %02d %02d:00 : %.3f kl\n", monthHourToDay(i), monthHourToDailyHour(i), apartment1Usage[i]);
					}
				}
			}
			else if (apartment == 2)
			{
				for (j = 0; j < SIZE; j++)
				{
					if (apartment2Usage[j] != 0)
					{
						printf("Day %02d %02d:00 : %.3f kl\n", monthHourToDay(j), monthHourToDailyHour(j), apartment2Usage[j]);
					}
				}
			} else if (apartment == 3)
			{
				for (k = 0; k < SIZE; k++)
				{
					if (apartment3Usage[k] != 0)
					{
						printf("Day %02d %02d:00 : %.3f kl\n", monthHourToDay(k), monthHourToDailyHour(k), apartment3Usage[k]);
					}
				}
			}
			break;
		case 2:
			if (apartment == 1)
			{
				printf("\nTotal usage from apartment %d: %.3f kl\n ", apartment, getTotalWaterUsage(apartment1Usage));
			}
			else if (apartment == 2)
			{
				printf("\nTotal usage from apartment %d: %.3f kl\n ", apartment, getTotalWaterUsage(apartment2Usage));
			}
			else if (apartment == 3)
			{
				printf("\nTotal usage from apartment %d: %.3f kl\n ", apartment, getTotalWaterUsage(apartment3Usage));
			}
			break;
		case 3:
			if (apartment == 1)
			{
				printf("\nTotal bill for apartment %d for this month: R%.2f\n ", apartment, getTotalBill(apartment1Usage, AptOne.tariff));
			}
			else if (apartment == 2)
			{
				printf("\nTotal bill for apartment %d for this month: R%.2f\n ", apartment, getTotalBill(apartment2Usage, AptTwo.tariff));
			}
			else if (apartment == 3)
			{
				printf("\nTotal bill for apartment %d for this month: R%.2f\n ", apartment, getTotalBill(apartment3Usage, AptThree.tariff));
			}
			break;
		case 4:
			if (apartment == 1)
			{
				printApartmentReport(apartment1Usage, AptOne);
			}
			else if (apartment == 2)
			{
				printApartmentReport(apartment2Usage, AptTwo);
			}
			else if (apartment == 3)
			{
				printApartmentReport(apartment3Usage, AptThree);
			}
			break;
		case 5:
			if (apartment == 1)
			{
				if (checkForLeak(apartment1Usage) == 0)
					printf("Apartment %d: No leak\n", apartment);
				else printf("Apartment %d: Leak on day %d\n", apartment, checkForLeak(apartment1Usage));
			}
			else if (apartment == 2)
			{
				if (checkForLeak(apartment2Usage) == 0)
					printf("Apartment %d: No leak\n", apartment);
				else printf("Apartment %d: Leak on day %d\n", apartment, checkForLeak(apartment2Usage));
			} 
			else if (apartment == 3)
			{
				if (checkForLeak(apartment3Usage) == 0)
					printf("Apartment %d: No leak\n", apartment);
				else printf("Apartment %d: Leak on day %d\n", apartment, checkForLeak(apartment3Usage));
			}
			break;
		case 6:
			printf("Enter a filename: ");
			scanf(" %s", filename);
				writeBuildingReport(apartment1Usage, apartment2Usage, apartment3Usage, AptOne, AptTwo, AptThree, filename);
			break;
		case 7: 

			// Binary file

			printf("\nSave(1) or print (2) compact usage file: ");
			scanf(" %d", &menu_seven);
			printf("\n");

			if (menu_seven == 1)
			{
				if (apartment == 1)
				{ 
					saveCompactUsage(apartment1Usage, apartment);
				}

				if (apartment == 2)
				{
					saveCompactUsage(apartment2Usage, apartment);
				}

				if (apartment == 3)
				{
					saveCompactUsage(apartment3Usage, apartment);
				}
			}

			else if (menu_seven == 2)
			{
				if (apartment == 1)
				{
					
					double usage1; // to save usage not equals 0
					int i; // index variable

					FILE *ReadPtr;
					
					if ((ReadPtr = fopen("compact_usage_1.bin", "rb")) == NULL)
					{
						puts("WARNING: Save compact usage to file before printing");
					}

					else
					{
						printf("\Active water usage report:\n");

						while (!feof(ReadPtr))
						{
							fread(&i, sizeof(int), 1, ReadPtr);
							fread(&usage1, sizeof(double), 1, ReadPtr);

							printf("Day %02d %02d:00 : %.3lf kl\n", monthHourToDay(i), monthHourToDailyHour(i), usage1);
						}
					}
					fclose(ReadPtr);
				}

				if (apartment == 2)
				{
					
					double usage2; // to save usage not equals 0
					int i; // index variable

					FILE *ReadPtr;

					if ((ReadPtr = fopen("compact_usage_2.bin", "rb")) == NULL)
					{
						puts("WARNING: Save compact usage to file before printing");
					}

					else
					{
						printf("\Active water usage report:\n");

						while (!feof(ReadPtr))
						{
							fread(&i, sizeof(int), 1, ReadPtr);
							fread(&usage2, sizeof(double), 1, ReadPtr);

							printf("Day %02d %02d:00 : %.3lf kl\n", monthHourToDay(i), monthHourToDailyHour(i), usage2);
						}
					}
					fclose(ReadPtr);
				}

				if (apartment == 3)
				{

					double usage3; // to save usage not equals 0
					int i; // index variable

					FILE *ReadPtr;

					if ((ReadPtr = fopen("compact_usage_3.bin", "rb")) == NULL)
					{
						puts("WARNING: Save compact usage to file before printing");
					}

					else
					{
						printf("\Active water usage report:\n");

						while (!feof(ReadPtr))
						{
							fread(&i, sizeof(int), 1, ReadPtr);
							fread(&usage3, sizeof(double), 1, ReadPtr);

							printf("Day %02d %02d:00 : %.3lf kl\n", monthHourToDay(i), monthHourToDailyHour(i), usage3);
						}
					}
					fclose(ReadPtr);
				}
			}
			break;
		case 8:

			// Linked Lists

			break;
		}

		puts("\nRP143 Water Calculator");
		puts("1. Print usage patter for apartment");
		puts("2. Calculate and print total usage for apartment (in kl)");
		puts("3. Calculate and print total bill for apartment (in R)");
		puts("4. Print apartment usage report to screen");
		puts("5. Check building for leaks and print leak report");
		puts("6. Write building water usage report to text file");
		puts("7. Save or print compact binary usage file for apartment");
		puts("8. Determine and print hour with greatest usage for apartment");
		puts("10. Exit");

		printf("\nChoose an item from the menu: ");
		scanf_s(" %d", &option);
	} 
	return 0;
}

void printApartmentReport(double waterUsage[], ApartmentData data)
{
	printf("\nApartment water usage report\n");
	printf("Owner: %s %s\n", data.ownerName, data.ownerSurname);
	printf("Tariff for apartment: R%.2f per kl\n", data.tariff);
	printf("Total usage for this month: %.3f kl\n", getTotalWaterUsage(waterUsage));
	printf("Total bill for this month: R%.2f\n", getTotalBill(waterUsage, data.tariff));
}


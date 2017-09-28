// This will be my main file

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "time.h"
#include "apartments.h"
#include "calculations.h"
#include "week1Usages.h"

#define SIZE 720
void printApartmentReport(double waterUsage[], ApartmentData data);

int main()
{
	// Program variables
	int option;
	int apartment;
	int i, j, k;
//	setbuf(stdout, 0);

	// Occupants data
	ApartmentData AptOne = { "JP", "Duminy", 5.14 };
	ApartmentData AptTwo = { "Imran", "Tahir", 16.88 };
	ApartmentData AptThree = { "Sunette", "Loubser", 5.04 };
	double apartment1Usage[SIZE] = APARTMENT1_USAGES;
	double apartment2Usage[SIZE] = APARTMENT2_USAGES;
	double apartment3Usage[SIZE] = APARTMENT3_USAGES;

	puts("just adding this to test cloning");

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
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
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


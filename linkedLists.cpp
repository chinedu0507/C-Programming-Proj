#include "linkedLists.h"
#include <stdlib.h>
#include <stdio.h>


void addNode(ListNodePtr *startPtrPtr, int monthHour, double usage)
{
	ListNodePtr newPtr;      // pointer to new node
	ListNodePtr previousPtr; // pointer to previous node in list
	ListNodePtr currentPtr;  // pointer to current node in list

	newPtr = malloc(sizeof(ListNode)); // create node

	if (newPtr != NULL) // If there is space
	{
		newPtr->monthHour = monthHour; // Place passed in monthHour value into newPtr's member variable, monthHour
		newPtr->usage = usage; // Place passed in usage value into newPtr's member variable, usage
		newPtr->nextPtr = NULL; // does not link to another node

		previousPtr = NULL;
		currentPtr = *startPtrPtr;

		// loop to arrange list in ascending order according to monthHour
		while (currentPtr != NULL && monthHour > currentPtr->monthHour)
		{
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr; // move to next node
		}

		// Insert node at the beginning of list
		if (previousPtr == NULL) // meaning that this is at the beginning of the list
		{
			// NEED TO GO OVER THIS SECTION AGAIN WITH PICS
			newPtr->nextPtr = *startPtrPtr;
			*startPtrPtr = newPtr;
		}
		else {

			// NEED TO GO OVER THIS SECTION AGAIN WITH PICS
			previousPtr->nextPtr = newPtr;
			newPtr->nextPtr = currentPtr;
		}
		
	} // HOW TO END THE LIST...NEED TO REMEMBER TO ADD NULL
	else puts("No memory available");

	
}
void printList(ListNodePtr startPtr)  // can define this function to use for debugging
{
	while (startPtr != NULL)
	{
		printf("%02d %.3lf\n", startPtr->monthHour, startPtr->usage);
		startPtr = startPtr->nextPtr; // NEED TO REVIEW THIS
	}
}

int monthHourOfMaxUsage(ListNodePtr startPtr)  // returns the hour in the month with the maximum usage
{
	double max = 0.0; // initial max usage value
	int hour = 0;    // initial monthHour

	ListNodePtr previousPtr;
	ListNodePtr currentPtr;

	previousPtr = NULL;
	currentPtr = startPtr;

	while (currentPtr != NULL)
	{
		if (max < currentPtr->usage)
		{
			max = currentPtr->usage;
			hour = currentPtr->monthHour;
		}
		previousPtr = currentPtr;
		currentPtr = currentPtr->nextPtr;
	}

	return hour;
}
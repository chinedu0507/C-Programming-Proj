#include "time.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int monthHourToDay(int monthHour)  // takes the hour of the month, and converts that to the day
{
	return ceil((double)monthHour / 24);
}


int monthHourToDailyHour(int monthHour)  // takes the hour of the month, and converts that to the specific hour on that day of the month
{
	int day, hour;

	if (monthHour < 24)
	{
		return monthHour;
	}
	else
	{
		day = monthHour / 24;
		hour = monthHour % (day * 24);

		return hour;
	}
}


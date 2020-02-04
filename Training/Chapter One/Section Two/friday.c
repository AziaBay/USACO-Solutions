/*
	Azia Bay-Asen
	February 4, 2020
*/

#include <stdio.h>

int isleapyear(int year)
{
	if((year % 100 == 0 && year % 400 == 0) ||
	(year % 100 != 0 && year % 4 == 0))
		return 1;
	else
		return 0;
}

int main(void)
{
	FILE *fin = fopen("friday.in", "r");
	FILE *fout = fopen("friday.out", "w");
	
	int N;
	fscanf(fin, "%i", &N);
	
	enum monthsoftheyear { nothing1, January, February, March, April, May, June, July, August, September, October, November, December };
	enum monthsoftheyear month = January;
	
	enum daysoftheweek { nothing2, Saturday, Sunday, Monday, Tuesday, Wednesday, Thursday, Friday };
	enum daysoftheweek dayoftheweek = Monday;
	int day = 1;
	
	int year = 1900;
	int targetyear = 1900 + N - 1;
	
	int thirteenths[8] = { NULL, 0, 0, 0, 0, 0, 0, 0 };
	
	while(month != December || day != 31 || year != targetyear)
	{
		day++;
		
		if(dayoftheweek == Friday)
			dayoftheweek = Saturday;
		else
			dayoftheweek++;
		
		if(((month == April || month == June || month == September || month == November) && day > 30) ||
		(month == February && ((isleapyear(year) && day > 29) || (!isleapyear(year) && day > 28))) ||
		day > 31)
		{
			month++;
			day = 1;
		}
		
		if(month > 12)
		{
			year++;
			month = January;
		}
		
		if(day == 13)
			thirteenths[dayoftheweek]++;
	}
	
	int index;
	for(index = 1; index <= 7; index++)
	{
		if(index == 7)
			fprintf(fout, "%i\n", thirteenths[7]);
		else
			fprintf(fout, "%i ", thirteenths[index]);
	}
}

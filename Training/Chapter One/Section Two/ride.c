/*
	Azia Bay-Asen
	February 3, 2020
*/

#include <stdio.h>
#include <string.h>

int hash(char *name)
{
	int number = 1;
	int size = strlen(name);
	
	int index;
	for(int index = 0; index < size; index++)
	{
		number *= name[index] - 'A' + 1;
	}
	
	return number;
}

int main(void)
{
	FILE *fin = fopen("ride.in", "r");
	FILE *fout = fopen("ride.out", "w");
	
	char comet[8], group[8];
	fscanf(fin, "%s %s", &comet, &group);
	
	if(hash(comet) % 47 == hash(group) % 47)
		fprintf(fout, "GO\n");
	else
		fprintf(fout, "STAY\n");
}

/*
	Azia Bay-Asen
	February 4, 2020
*/

#include <stdio.h>
#include <string.h>

struct Person
{
	char name[14];
	int balance;
};

int getcurrentP(struct Person *P, int NP, char *name)
{
	int index;
	for(index = 0; index < NP; index++)
	{
		if(strcmp(P[index].name, name) == 0)
			return index;
	}
}

int main(void)
{
	FILE *fin = fopen("gift1.in", "r");
	FILE *fout = fopen("gift1.out", "w");
	
	int NP;
	fscanf(fin, "%i", &NP);
	
	struct Person P[NP];
	
	int index;
	for(index = 0; index < NP; index++)
	{
		fscanf(fin, " %s", &P[index].name);
		P[index].balance = 0;
	}
	
	for(index = 0; index < NP; index++)
	{	
		char currentname[14];
		fscanf(fin, " %s", &currentname);
		
		int currentP = getcurrentP(P, NP, currentname);
		
		int G, NG;
		fscanf(fin, " %i %i", &G, &NG);
		
		if(NG != 0)
		{
			P[currentP].balance -= G;
			P[currentP].balance += G % NG;
		}
		
		int jndex;
		for(jndex = 0; jndex < NG; jndex++)
		{
			fscanf(fin, " %s", &currentname);
			currentP = getcurrentP(P, NP, currentname);
			P[currentP].balance += G / NG;
		}
	}
	
	for(index = 0; index < NP; index++)
	{
		fprintf(fout, "%s %i\n", P[index].name, P[index].balance);
	}
}

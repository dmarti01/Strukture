#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct {
	char imeprez[50];
	double bod;
}studenti;


int main() {
	

	FILE* dat;
	studenti* osoba=NULL;
	int i, br = 0;
	double bodovi;
	char impr[50];
	char ime[25];
	char prez[25];

	dat = fopen("studenti.txt", "w");
	
	printf("Koliko studenata zelite unijeti:");
	scanf_s("%d", &br);
	osoba = (studenti*)malloc(br * sizeof(studenti));

	if (feof(dat) == NULL)
	{
		printf("Greska u ispisu datoteke!!!\n");
	}

	for (i = 0;i < br;i++)
	{
		printf("Unose se podaci za %d. studenta\n", i + 1);
		printf("Unesi ime i prezime studenta\n");
		scanf("%s %s", ime,prez);
		strcpy(impr, ime);
		strcat(impr, " ");
		strcat(impr, prez);
		strcpy(osoba[i].imeprez, impr);
		printf("Unesi bodove: ");
		scanf_s("%lf", &bodovi);
		osoba[i].bod = bodovi;
	}
	fprintf(dat,"Ime i prezime:\tBodovi:\n");
	for (i = 0;i < br;i++)
	{
		fprintf(dat,"%s \t    %.2lf\n", osoba[i].imeprez, osoba[i].bod);
	}

	

	fclose(dat);
	
	return 0;
}
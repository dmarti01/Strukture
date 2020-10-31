#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct {
	char imeprez[50];
	double bod;
}studenti;

float brbod(float bd);
int count(char* fp);

int main() {


	
	FILE* fr;
	studenti* osoba = NULL;
	int  br = 0;
	double bodovi;
	char impr[50];
	char ime[25];
	char prez[25];
	double relbod;
	int line=0;
	char ch;

	fr = fopen("studenti.txt", "r");
	
	if (fr == NULL) {
		printf("Error! Ne moze se otvoriti datoteka!\n");
		return 0;
	}
	
	while (fgetc(fr) != '\n') {};//preskakanje prvog retka

	line = count(fr);
	printf("U datoteci ima %d studenata.\n", line);



	printf("Ime i prezime:\tBodovi:\tRelativni:\n");
	while (1) {
		if (feof(fr))
			break;
		br++;
		osoba = (studenti*)malloc(br * sizeof(studenti));
		
		fscanf(fr, "%s %s", ime, prez);
		fscanf(fr, "%lf", &bodovi);
		
		osoba[br - 1].bod = bodovi;

	//	while (fgetc(fr) != '\n' || feof(fr)) {};

		strcpy(impr, ime);
		strcat(impr, " ");
		strcat(impr, prez);
		strcpy(osoba[br - 1].imeprez, impr);
		
		if (feof(fr))
			break;
		relbod= brbod((float)bodovi);
		printf("%s\t%.2lf\t%.2lf\n", impr, bodovi,relbod);
		
		if (fgetc(fr)!='\n'||feof(fr))
			break;

	}
	//printf("U datoteci ima %d studenata.\n", br-1);
	

	fclose(fr);
	return 0;
}

float brbod(float a) {
	float rel, max = 10;
	rel = (a/max) * 100;
	return rel;
}
int count(char* fp) {
	fp = fopen("studenti.txt", "r");

	if (fp == NULL) {
		printf("Error! Ne moze se otvoriti datoteka!\n");
		return 0;
	}
	char ch;
	int redak = 0;
	while (!feof(fp)) {
		ch = fgetc(fp);
		if (ch == '\n')
			redak++;

		if (feof(fp))
			break;
	}
	return redak-1;
	fclose(fp);
}
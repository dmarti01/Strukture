#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student* Pozicija;

struct student {
	char ime[25];
	char prezime[25];
	int matbr;
	Pozicija next;
};

int hash(char* slovo, int velTab);

void dodaj(Pozicija H, char* ime, char* prezime, int x, int velTab);
void ispis(Pozicija head[]);
void trazi(Pozicija head[]);

int main() {
	char c, * ime = NULL, * prezime = NULL;
	int velTab = 11;
	int i = 0, j = 0;
	int kljuc, mb;
	Pozicija root[11];

	ime = (char*)malloc(25 * sizeof(char));
	prezime = (char*)malloc(25 * sizeof(char));

	while (i < 11) {
		root[i] = NULL;
		root[i] = (Pozicija)malloc(sizeof(struct student));
		root[i]->next = NULL;
		i++;
	}
	//root = inicijalizacija();

	printf("Upisi 11 studenata!\n");

	while (j < 11) {
		printf("Unesi ime:");
		scanf("%s", ime);
		printf("Unesi prezime:");
		scanf("%s", prezime);
		printf("Unesi maticni broj:");
		scanf("%d", &mb);
		kljuc = hash(prezime, velTab);
		dodaj(root[kljuc], ime, prezime, mb, velTab);
		j++;
	}
	ispis(root);

	printf("\nAko zelis pronaci element stisni 1, a za kraj programa 2!\n");
	/*while (1) {
		printf("\nIzbor:");
		scanf("%c", &c);
		switch (c) {
		case's':
		case'S':
			trazi(root);
			break;
		case'i':
		case'I':
			return 0;
			break;
		default:
			printf("Potkrala se greskica!\n");
			break;
		}
	}*/

	while (1) {
		printf("\nIzbor:");
		scanf("%c", &c);
		switch (c) {
		case 's':
			trazi(root);//viidi ovdje za kljuc
			break;
		case 'i':
			return 0;
			break;
		default:
			printf("Potkrala se grasekica!!!\n");
			break;
		}
	}
}

int hash(char* slovo, int velTab) {
	int i = 0, hash_value = 0;
	int rez;
	for (i = 0;i < 5;i++) {
		if (slovo[i] != '\0')
		{
			hash_value += (int)slovo[i];
		}
	}
	rez = hash_value % velTab;
	return rez;
}
void dodaj(Pozicija H, char* ime, char* prezime, int x, int velTab)
{	
	int i;

	if (H->next == NULL) {
		Pozicija tmp = malloc(sizeof(struct student));

		if (!tmp) {
			printf("Greska pri alokaciji memorije!\n");
			return NULL;
		}
		strcpy(tmp->ime, ime);
		strcpy(tmp->prezime, prezime);
		tmp->matbr = x;
		tmp->next = H->next;
		H->next = tmp;
	}

	i = 0;
	while (H->next != NULL && i < velTab) {
		if (strcmp(H->prezime, prezime) > 0) {
			Pozicija tmp1 = malloc(sizeof(struct student));

			if (!tmp1) {
				printf("Greska pri alokaciji memorije!\n");
				return NULL;
			}
			strcpy(tmp1->ime, ime);
			strcpy(tmp1->prezime, prezime);
			tmp1->matbr = x;
			tmp1->next = H->next;
			H->next = tmp1;
			return;
		}
		else if (strcmp(H->ime, ime) > 0) {
				Pozicija tmp2 = malloc(sizeof(struct student));

				if (!tmp2) {
					printf("Greska pri alokaciji memorije!\n");
					return NULL;
				}
				strcpy(tmp2->ime, ime);
				strcpy(tmp2->prezime, prezime);
				tmp2->matbr = x;
				tmp2->next = H->next;
				H->next = tmp2;
				return;
			}
		
		H = H->next;
		i++;
	}
}
void ispis(Pozicija head[]) {
	int i;
	
	printf("Ispis liste!\n\n");
	printf("Key\tIme\tPrezime\tMaticni broj\n");

	for (i=0; i < 11; i++) {
		printf("%d", i);
		if (head[i]->next == NULL) {
			printf("\tPrazan slot!\n");
		}
		else {
			
			while (head[i]->next->next != NULL) {
				printf("   \t%s\t%s\t%d \n", head[i]->next->ime, head[i]->next->prezime, head[i]->next->matbr);
				head[i]->next = head[i]->next->next;
			}
			printf("\n");
		}
	}
}
void trazi(Pozicija head[]) {
	int kljuc, i;
	int velTab = 11;
	Pozicija c=(Pozicija)malloc(sizeof(struct student));

	

	char ime[30], prezime[30];
	printf("Unesi ime:");
	scanf("%s", ime);
	strcpy(c->ime, ime);
	printf("Unesi prezime:");
	scanf("%s", prezime);
	strcpy(c->prezime, prezime);

	kljuc = hash(prezime, velTab);
	//i = kljuc % velTab;
	//i = kljuc;

	if (head[kljuc] == NULL)
		printf("\nElement ne postoji u listi!!!\n");
	else {
		for (c = head[kljuc];c != NULL;c = c->next)
		{
			if ((strcmp(c->prezime,prezime)==0)&&(strcmp(c->ime,ime)==0))
			{
				printf("\nStudent %s %s pronadjen!\n",c->ime,c->prezime);
				printf("Njegov maticni broj: %d", c->matbr);
				break;
			}
		}
		if (c == NULL)
			printf("\nElement ne postoji u listi!!!\n");

	}
}

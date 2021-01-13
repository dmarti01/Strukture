#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student* Pozicija;

struct student {
	char ime[30];
	char prezime[30];
	int matbr;
	Pozicija next;
};

int hash(char*, int);
void dodaj(Pozicija, char*, char*, int);
void dodajN(Pozicija, char*, char*, int);
void pronadji(Pozicija, char*, char*);
void ispisi(Pozicija);

int main()
{
	int velTab = 11;
	char c;
	char ime[30], prezime[30];
	int matBroj, kljuc;
	Pozicija head[11];

	for (int i = 0; i < 11; i++) {
		head[i] = NULL;
		head[i] = malloc(sizeof(struct student));
		head[i]->next = NULL;
	}

	printf(" Za dodati studenta - 'd'\n Za pronaci mat.broj odredjenog studenta - 'b'\n Za izaci - 'e'\n Za ispisati - 'i'\n");

	while (1) {
		scanf(" %c", &c);

		switch (c) {
		case 'd':
			printf("Unesite ime, prezime i maticni broj studenta: ");
			scanf("%s %s %d", ime, prezime, &matBroj);
			kljuc = hash(prezime, velTab);
			dodaj(head[kljuc], ime, prezime, matBroj);
			break;
		case 'b':
			printf("Unesite ime i prezime studenta: ");
			scanf("%s %s", ime, prezime);
			kljuc = hash(prezime, velTab);
			pronadji(head[kljuc], ime, prezime);
			break;
		case 'e':
			return 0;
		case 'i':
			ispisi(head);
			break;
		default:
			printf("Upisali ste krivu komandu, pokusajte ponovno...\n");
			break;
		}
	}

	return 0;
}

int hash(char* slovo, int velTab)
{
	int HashV = 0;
	int i = 0;
	for (i; i < 5; i++) {
		if (slovo[i] != '\0')
			HashV += slovo[i];
	}
	return (HashV % velTab);
}

void dodaj(Pozicija hash, char* i, char* p, int m)
{
	if (hash->next == NULL) {
		//dodajN(hash, p, i, m);
		Pozicija novi = malloc(sizeof(struct student));

		if (novi == NULL)
			return;

		strcpy(novi->ime, i);
		strcpy(novi->prezime, p);
		novi->matbr = m;
		novi->next = hash->next;
		hash->next = novi;
	}

	while (hash->next != NULL) {
		if (hash->matbr == m) {
			printf("Student s ovakvim maticnim brojem vec postoji...");
			return;
		}
		else if (strcmp(p, hash->prezime) < 0) {
			//dodajN(hash, i, p, m);
			Pozicija novi = malloc(sizeof(struct student));

			if (novi == NULL)
				return;

			strcpy(novi->ime, i);
			strcpy(novi->prezime, p);
			novi->matbr = m;
			novi->next = hash->next;
			hash->next = novi;
			return;
		}
		else if (!strcmp(p, hash->prezime)) {
			if (!strcmp(i, hash->ime)) {
				printf("Student postoji. ");
				return;
			}
			else if (strcmp(i, hash->ime) < 0) {
				//dodajN(hash, i, p, m);
				Pozicija novi = malloc(sizeof(struct student));

				if (novi == NULL)
					return;

				strcpy(novi->ime, i);
				strcpy(novi->prezime, p);
				novi->matbr = m;
				novi->next = hash->next;
				hash->next = novi;
				return;
			}
		}
		hash = hash->next;
	}
}

void dodajN(Pozicija hash, char* i, char* p, int m)
{
	Pozicija novi = malloc(sizeof(struct student));

	if (novi == NULL)
		return;

	strcpy(novi->ime, i);
	strcpy(novi->prezime, p);
	novi->matbr = m;
	novi->next = hash->next;
	hash->next = novi;
}


void pronadji(Pozicija head, char* ime, char* prezime)
{
	while (head != NULL) {
		if (!strcmp(head->prezime, prezime))
			if (!strcmp(head->ime, ime)) {
				printf("Maticni broj studenta %s %s: %d\n", ime, prezime, head->matbr);
				return;
			}
	}
	printf("Student ne postoji.\n");
}

void ispisi(Pozicija head[])
{
	int i = 0;

	printf(" KLJUC\tPREZIME\t IME \tMATICNI BROJ\n");

	for (i; i < 11; i++) {
		printf(" %d", i);
		if (head[i]->next == NULL) {
			printf("\tPrazno...\n\n");
		}
		else {
			Pozicija temp = head[i]->next;
			while (temp->next != NULL) {
				printf("\t%s\t %s \t%d \n", temp->prezime, temp->ime, temp->matbr);
				temp = temp->next;
			}
			printf("\n");
		}
	}
}
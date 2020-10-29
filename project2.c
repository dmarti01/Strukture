#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M (256)

struct osoba;
typedef struct osoba* Position;
typedef struct osoba {
	char ime[M];
	char prezime[M];
	int godina;
	Position next;
}osoba;

Position novaOsoba(char*, char*, int);
void Ispis(Position);
void unosPocetak(Position, Position);
void unosKraj(Position, Position);
Position pronadi(Position, char*);
Position pronadiPret(Position, char*);
void izbrisi(Position, char*);

int main() {
	Position head = NULL, p, n;
	char Ime[M], Prezime[M], prezimen[M];
	int god;
	char s;

	while (1) {

		printf("MENU:\nNovi element na pocetak liste->P\nNovi element na kraj liste->K\nPronadi element->N\nObrisi element->b\nKraj->E\n");
		scanf(" %c", &s);
		switch (s) {
		case 'p':
			printf("unesite ime:\t");
			scanf(" %s", Ime);

			printf("unesite prezime:\t");
			scanf(" %s", Prezime);

			printf("unesite godinu rodjenja:\t");
			scanf(" %d", &god);

			printf("\n");

			p = novaOsoba(Ime, Prezime, god);
			unosPocetak(&head, p);
			Ispis(&head);
			break;
		case 'k':
			printf("Unesite ime:\t");
			scanf(" %s", Ime);

			printf("Unesite prezime:\t");
			scanf(" %s", Prezime);

			printf("Unesite godinu rodjenja:\t");
			scanf(" %d", &god);

			printf("\n");

			p = novaOsoba(Ime, Prezime, god);
			unosKraj(&head, p);
			Ispis(&head);
			break;
		case 'n':
			printf("Unesite prezime osobe koju zelite naci: ");
			scanf(" %s", prezimen);
			n = pronadi(&head, prezimen);
			printf("\n%s %s %d\r\n", n->ime, n->prezime, n->godina);
			break;
		case 'b':

			printf("Unesite prezime osobe koje zelite izbrisati: ");
			scanf(" %s", prezimen);
			izbrisi(&head, prezimen);
			Ispis(&head);
			break;
		case 'e':
			return 0;
			break;
		}
	}

	return 0;
}

Position novaOsoba(char* Ime, char* Prezime, int god)
{
	Position p;

	p = (Position)malloc(sizeof(struct osoba));

	p->godina = god;
	strcpy(p->ime, Ime);
	strcpy(p->prezime, Prezime);
	p->next = NULL;

	return p;
}

void Ispis(Position head)
{
	Position p = NULL;

	printf("Sadrzaj liste:\n\n");
	for (p = head->next; p != NULL; p = p->next) {
		printf("\t %s %s %d \n", p->ime, p->prezime, p->godina);
	}
	printf("\r\n");
}

void unosPocetak(Position head, Position p)
{
	p->next = head->next;
	head->next = p;
}

void unosKraj(Position q, Position p)
{
	while (q->next != NULL) {
		q = q->next;
	}
	unosPocetak(q, p);
}

Position pronadi(Position q, char* prez) {
	while (q->next != NULL && strcmp(q->prezime, prez))
		q = q->next;
	return q;
}

Position pronadiPret(Position p, char* prezimen) {
	Position pret = p;
	p = p->next;

	while (p->next != NULL && strcmp(p->prezime, prezimen)) {
		pret = p;
		p = p->next;
	}
	if (p->next == NULL) {
		printf("ne postoji!\n");
		return NULL;
	}
	return pret;
}

void izbrisi(Position p, char* prezimen) {
	Position prev;
	prev = pronadiPret(p, prezimen);

	if (prev != NULL) {
		p = prev->next;
		prev->next = p->next;
		free(p);
	}
}
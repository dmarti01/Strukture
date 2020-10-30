#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M (256)

struct osoba;
typedef struct osoba* Pozicija;
typedef struct osoba {
	char ime[M];
	char prezime[M];
	int godina;
	Pozicija next;
}osoba;

Pozicija novaOsoba(char*, char*, int);
void Ispis(Pozicija);
void unosPocetak(Pozicija, Pozicija);
void unosKraj(Pozicija, Pozicija);
Pozicija pronadi(Pozicija, char*);
Pozicija pronadiPret(Pozicija, char*);
void izbrisi(Pozicija, char*);

int main() {
	Pozicija head = NULL, p, n;
	char Ime[M], Prezime[M], prezimen[M];
	int god;
	char s;

	while (1) {

		printf("Izaberite:\n\tNovi element na pocetak liste->P\n\tNovi element na kraj liste->K\n\tPronadi element->N\n\tObrisi element->b\n\tIzlaz iz programa->I\n");
		printf("Vas izbor: ");
		scanf(" %c", &s);
		switch (s) {
		case 'p':
		case 'P':
			printf("Unesite ime: ");
			scanf(" %s", Ime);

			printf("Unesite prezime: ");
			scanf(" %s", Prezime);

			printf("Unesite godinu rodjenja: ");
			scanf(" %d", &god);

			printf("\n");

			p = novaOsoba(Ime, Prezime, god);
			unosPocetak(&head, p);
			Ispis(&head);
			break;
		case 'k':
		case 'K':
			printf("Unesite ime: ");
			scanf(" %s", Ime);

			printf("Unesite prezime: ");
			scanf(" %s", Prezime);

			printf("Unesite godinu rodjenja: ");
			scanf(" %d", &god);

			printf("\n");

			p = novaOsoba(Ime, Prezime, god);
			unosKraj(&head, p);
			Ispis(&head);
			break;
		case 'n':
		case 'N':
			printf("Unesite prezime osobe koju zelite naci: ");
			scanf(" %s", prezimen);
			n = pronadi(&head, prezimen);
			printf("\n%s %s %d\r\n", n->ime, n->prezime, n->godina);
			break;
		case 'b':
		case 'B':
			printf("Unesite prezime osobe koje zelite izbrisati: ");
			scanf(" %s", prezimen);
			izbrisi(&head, prezimen);
			Ispis(&head);
			break;
		case 'i':
		case 'I':
			return 0;
			break;
		}
	}

	return 0;
}

Pozicija novaOsoba(char* Ime, char* Prezime, int god)
{
	Pozicija p;

	p = (Pozicija)malloc(sizeof(struct osoba));

	p->godina = god;
	strcpy(p->ime, Ime);
	strcpy(p->prezime, Prezime);
	p->next = NULL;

	return p;
}

void Ispis(Pozicija head)
{
	Pozicija p = NULL;

	printf("Sadrzaj liste:\n\n");
	for (p = head->next; p != NULL; p = p->next) {
		printf("\t %s %s %d \n", p->ime, p->prezime, p->godina);
	}
	printf("\r\n");
}

void unosPocetak(Pozicija head, Pozicija p)
{
	p->next = head->next;
	head->next = p;
}

void unosKraj(Pozicija q, Pozicija p)
{
	while (q->next != NULL) {
		q = q->next;
	}
	unosPocetak(q, p);
}

Pozicija pronadi(Pozicija q, char* prez) {
	while (q->next != NULL && strcmp(q->prezime, prez))
		q = q->next;
	return q;
}

Pozicija pronadiPret(Pozicija p, char* prezimen) {
	Pozicija pret = p;
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

void izbrisi(Pozicija p, char* prezimen) {
	Pozicija prev;
	prev = pronadiPret(p, prezimen);

	if (prev != NULL) {
		p = prev->next;
		prev->next = p->next;
		free(p);
	}
}

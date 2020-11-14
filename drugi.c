#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct osoba* Pozicija;
struct osoba {
	char ime[100];
	char prezime[100];
	int godina;
	Pozicija next;
};
void unosP(char* i, char* p, int g, Pozicija P);
void unosK(char* i, char* p, int g, Pozicija P);
void ispis(Pozicija);
Pozicija trazi(char pp[100], Pozicija P);
Pozicija traziPret(char pp[100], Pozicija P);
Pozicija brisi(char tp[100], Pozicija P);

int main() {
	struct osoba Head;
	Head.next = NULL;
	char* ime = NULL, * prezime = NULL, * p_prezime = NULL;
	char* b_prezime;
	int god;
	char s;
	ime = (char*)malloc(50 * sizeof(char));
	prezime = (char*)malloc(50 * sizeof(char));
	p_prezime = (char*)malloc(50 * sizeof(char));
	b_prezime = (char*)malloc(50 * sizeof(char));
	while (1) {
		printf("Izaberite:\n\tNovi element na pocetak liste->P\n\tNovi element na kraj liste->K\n\tPronadi element->N\n\tObrisi element->b\n\tIzlaz iz programa->I\n");
		printf("Input:");
		scanf(" %c", &s);

		switch (s) {
		case'p':
		case'P':
			printf("Unesite ime:");
			scanf("%s", ime);
			printf("Unesite prezime:");
			scanf("%s", prezime);
			printf("Unesite godinu rodjenja:");
			scanf("%d", &god);
			unosP(ime, prezime, god, &Head);
			ispis(Head.next);
			break;
		case'k':
		case'K':
			printf("Unesite ime:");
			scanf("%s", ime);
			printf("Unesite prezime:");
			scanf("%s", prezime);
			printf("Unesite godinu rodjenja:");
			scanf("%d", &god);
			unosK(ime, prezime, god, &Head);
			ispis(Head.next);
			break;
		case'n':
		case'N':
			printf("Unesi prezime za pretragu:");
			scanf("%s", p_prezime);
			trazi(p_prezime, &Head);
			break;
		case'b':
		case'B':
			printf("Unesite prezime za brisanje:");
			scanf("%s", b_prezime);

			brisi(b_prezime, &Head);
			ispis(Head.next);
			break;
		case'i':
		case'I':
			return 0;
			break;

		}
	}
}
void ispis(Pozicija P) {
	while (P != NULL)
	{
		printf("%s\t%s\t%d", P->ime, P->prezime, P->godina);
		P = P->next;
		printf("\n");
	}


}

void unosP(char* i, char* p, int g, Pozicija P) {
	Pozicija q = NULL;
	q = (Pozicija)malloc(sizeof(struct osoba));
	strcpy(q->ime, i);
	strcpy(q->prezime, p);
	q->godina = g;

	q->next = P->next;
	P->next = q;
}
void unosK(char* i, char* p, int g, Pozicija P) {
	Pozicija q = NULL;

	q = (Pozicija)malloc(sizeof(struct osoba));
	strcpy(q->ime, i);
	strcpy(q->prezime, p);
	q->godina = g;

	while (P->next != NULL)
		P = P->next;

	q->next = P->next;
	P->next = q;
}
Pozicija trazi(char* pp, Pozicija P) {
	while (P != NULL)
	{
		if (strcmp(P->prezime, pp) == 0) {
			printf("Pronadjena je osoba:\n");
			printf("\n%s\t%s\t%d\n", P->ime, P->prezime, P->godina);
		}
		P = P->next;

	}
	if (P == NULL) {
		printf("Osoba ne postoji u listi!\n");
	}

}
Pozicija traziPret(char* pp, Pozicija P) {
	Pozicija prev = P;
	P = P->next;

	while (P->next != NULL && strcmp(P->prezime, pp)) {
		prev = P;
		P = P->next;
	}
	if (P->next == NULL) {
		printf("Ne postoji!\n");
		return NULL;
	}
	return prev;
}
Pozicija brisi(char* tp, Pozicija P) {
	Pozicija prev;

	prev = traziPret(tp, P);
	if (prev != NULL) {
		P = prev->next;
		prev->next = P->next;
		free(P);
	}
}
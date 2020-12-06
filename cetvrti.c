#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct polinom* Pozicija;

struct polinom {
	int koef;
	int exp;
	Pozicija next;
};

void citaj(Pozicija, char*);

void ispis(Pozicija);
void sortUnos(Pozicija, int, int);
void popravi(Pozicija);
void zbroji(Pozicija, Pozicija, Pozicija);
void pomnozi(Pozicija, Pozicija, Pozicija);

int main() {
	struct polinom P1, P2, Z, U;
	P1.next = NULL;
	P2.next = NULL;
	Z.next = NULL;
	U.next = NULL;

	citaj(&P1, "P1.txt");
	printf("Prvi polinom: ");
	ispis(&P1);

	citaj(&P2, "P2.txt");
	printf("Drugi polinom: ");
	ispis(&P2);
	
	printf("\nZbroj:");
	zbroji(&Z, &P1, &P2);
	ispis(&Z);

	printf("\nUmnozak: ");
	pomnozi(&U, &P1, &P2);
	ispis(&U);
}
void citaj(Pozicija P, char* ime) {
	FILE* dat;
	int k, e;

	Pozicija q = NULL;
	q = (Pozicija)malloc(sizeof(struct polinom));
	
	dat = fopen(ime, "r");
	if (dat == NULL)
		printf("Greska!\n");
	else {
		while (feof(dat) == 0) {
			fscanf(dat, "%d %d", &k, &e);
			
		    sortUnos(P, k, e);
			//q->koef = k;
			//q->exp = e;
		}
	}
	fclose(dat);
}
void ispis(Pozicija P) {
	P = P->next;
	while (P != NULL)
	{
		printf("%dx^%d", P->koef, P->exp);
		P = P->next;
		if (P != NULL)
			printf("+");
	}
	printf("\n");
}

void sortUnos(Pozicija P, int k, int e) {
	Pozicija q;
	
	while (P->next != NULL && P->next->exp > e)
		P = P->next;
	q = (Pozicija)malloc(sizeof(struct polinom));

	q->exp = e;
	q->koef = k;

	q->next = P->next;
	P->next = q;
}
void zbroji(Pozicija Z, Pozicija P, Pozicija Q) {
	P = P->next;
	Q = Q->next;
	while (P != NULL && Q != NULL) {
		if (P->exp == Q->exp)
		{
			Z->koef = P->koef + Q->koef;
			Z->exp = P->exp;
			sortUnos(Z, Z->koef, Z->exp);
			P = P->next;
			Q = Q->next;
		}
		else if (P->exp < Q->exp) {
			Z->koef = Q->koef;
			Z->exp = Q->exp;
			sortUnos(Z, Z->koef, Z->exp);
			Q = Q->next;
		}
		else if (P->exp > Q->exp) {
			Z->koef = P->koef;
			Z->exp = P->exp;
			sortUnos(Z, Z->koef, Z->exp);
			P = P->next;
		}
	}
	if (P == NULL) {
		while (Q != NULL) {
			Z->koef = Q->koef;
			Z->exp = Q->exp;
			sortUnos(Z, Z->koef, Z->exp);
			Q = Q->next;
		}
	}
	else if (Q == NULL) {
		while (P != NULL)
		{
			Z->koef = P->koef;
			Z->exp = P->exp;
			sortUnos(Z, Z->koef, Z->exp);
			P = P->next;
		}
	}	
}
void pomnozi(Pozicija Z, Pozicija P, Pozicija Q) {
	Pozicija temp1,temp2,temp3;
	temp1 = P->next;
	temp2 = Q->next;
	temp3 = NULL;
	P = P->next;
	Q = Q->next;
	while (temp1 != NULL) {
		while (temp2 != NULL) {
				Z->koef = temp1->koef * temp2->koef;
				Z->exp = temp1->exp + temp2->exp;
				sortUnos(Z, Z->koef, Z->exp);		
				temp3 = Z->next;
			temp2 = temp2->next;
		}
		temp2 = Q;
		temp1 = temp1->next;
		
	}
	popravi(temp3);
}
void popravi(Pozicija Z) {
	Pozicija t1, t2, dup;
	t1 = Z;

	while (t1 != NULL&&t1->next!=NULL) {
		t2 = t1;
		while (t2->next != NULL) {
			if (t1->exp == t2->next->exp) {
				t1->koef = t1->koef + t2->next->koef;
				dup = t2->next;
				t2->next = t2->next->next;
			}
			else
				t2 = t2->next;
		}
		t1=t1->next;
	}
}
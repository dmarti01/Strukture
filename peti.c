#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct lista* Pozicija;
struct lista {
	int el;
	Pozicija next;
};

void sortUnos(Pozicija, int);
void ispis(Pozicija);
void unija(Pozicija,Pozicija,Pozicija);
void presjek(Pozicija, Pozicija, Pozicija);
void del_dupli(Pozicija);


int main() {
	struct lista L1, L2,U,D;
	L1.next = NULL;
	L2.next = NULL;
	U.next = NULL;
	D.next = NULL;
	int e,x,y,i;

	printf("Unesi broj elemenata prve liste:");
	scanf("%d", &x);
	printf("Unesi elemente:\n");
	for (i = 0;i < x;i++)
	{
		scanf("%d", &e);
		sortUnos(&L1, e);
	}
	ispis(L1.next);

	printf("\nUnesi broj elemenata druge liste:");
	scanf("%d", &y);
	printf("Unesi elemente:\n");
	for (i = 0;i < y;i++)
	{
		scanf("%d", &e);
		sortUnos(&L2, e);
	}
	ispis(L2.next);

	unija(&U, &L1, &L2);
	printf("\nUnija je: ");
	ispis(U.next);

	presjek(&D, &L1, &L2);
	printf("\nPresjek je:");
	ispis(D.next);
	

}
void sortUnos(Pozicija P, int e) {
	Pozicija q;
	q = (Pozicija)malloc(sizeof(struct lista));
	while (P->next != NULL && P->next->el <e)
		P = P->next;
	q->el = e;

	q->next = P->next;
	P->next = q;
}
void ispis(Pozicija P) {
	while (P != NULL) {
		printf("%d ", P->el);
		P = P->next;
	}
}
void unija(Pozicija U, Pozicija L1, Pozicija L2){
	L1 = L1->next;
	L2 = L2->next;
	Pozicija t1, t2,t3;
	t1 = L1;
	t2 = L2;
	t3 = NULL;
	while (t1 != NULL)
	{
		sortUnos(U, t1->el);
		t1 = t1->next;
		t3 = U->next;
	}
	while (t2 != NULL) {
		sortUnos(U, t2->el);
		t2 = t2->next;
		t3 = U->next;
	}
	del_dupli(t3);
}
void del_dupli(Pozicija U) {
	Pozicija t1, t2;
	t1 = U;
	while (t1 != NULL && t1->next != NULL) {
		t2 = t1;
		while (t2->next != NULL) {
			if (t1->el == t2->next->el)
				t2->next = t2->next->next;
			else
				t2 = t2->next;
		}
		t1 = t1->next;
	}
}
void presjek(Pozicija D, Pozicija L1, Pozicija L2) {
	L1 = L1->next;
	L2 = L2->next;
	Pozicija t1, t2, t3;
	t1 = L1;
	t2 = L2;
	t3 = NULL;
	
	while (t1 != NULL) {
		while (t2 != NULL) {
			if (t1->el == t2->el)
				sortUnos(D, t1->el);
			t3 = D->next;
			t2 = t2->next;
		}
		t2 = L2;
		t1 = t1->next;
	}
}

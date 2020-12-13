#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

#define MAX 100
#define MIN 10

typedef struct cvor* Stog;

struct cvor {
	int el;
	Stog next;
};

void push(int x,Stog S);
int pop(Stog S);
void ispis(Stog S);


int main() {
	int sl;
	char c;

	struct cvor Head;
	Head.next = NULL;
	
	srand(time(0));
	
	while (1) {
		printf("STOG\n\t->D za push\n\t->I za pop\n\t\n\t->E za izlaz\n\t->Vas izbor: ");
		scanf("%c", &c);
		switch (c) {
		case'd':
		case'D':
			sl = MIN + rand() % ((MAX - MIN) + 1);
			push(sl, &Head);
			ispis(Head.next);
			break;
		case'i':
		case'I':
			pop(&Head);
			printf("Nakon popa\n");
			ispis(Head.next);
			break;
		case'e':
		case'E':
			return 0;
			break;
		default:
			printf("Potkrala se greska.\n");
		}
	}
	return 0;
}
void push(int x, Stog S) {
	Stog q;
	q = (Stog)malloc(sizeof(struct cvor));

	q->el = x;
	q->next = S->next;
	S->next = q;
}
int pop(Stog S) {
	int x = -1;
	Stog temp;
	if (S->next != NULL) {
		x = S->next->el;
		temp = S -> next;
		S->next = temp->next;
		free(temp);
	}
	return x;
}
void ispis(Stog S) {
	while (S != NULL)
	{
		printf("%d", S->el);
		S = S->next;
		printf("\n");
	}
}
//ZADATAK S DIREKTORIJIMA
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#define MAX_DIR_LENGTH (256)

typedef struct dir* Position;
typedef struct stack* StackPosition;

struct dir {
	char name[MAX_DIR_LENGTH];
	Position sibling;
	Position child;
};
struct stack {
	Position data;
	StackPosition next;
};

/*void remove(Position current) {
	if (current == NULL)
		return;
	remove(current->sibling);
	remove(current->child);
	free(current);
}*/
void push(char, StackPosition);
int pop(stackPosition);

void unos(char, Position);

int main() {
	char c;
	char ime[15];
	struct dir Head;
	Head.sibling = NULL;
	Head.child = NULL;

	push(&Head);//TREBA SE ROOT PRIJE SLATI 

	//c:->ANTE->Marica antu saljemo na stog kad smo u marici 
	while (1)
	{
		printf("1->mkdir\n2->cd dir\n3->cd..\n4->dir\n5->Izlaz\nVas izbor: ");
		scanf("%c", &c);

		switch (c) {
		case'1':
			printf("Unesi ime:");
			scanf("%s", ime);

			unos(ime, &Head);
			break;
		case'2':
			break;
		case'3':
			break;
		case'4':
			break;
		case'5':
			return 0;
			break;
		}
	}
}
void push(char x, StackPosition S) {
	StackPosition q;
	q = (StackPosition)malloc(sizeof(struct stack));

	q->data = x;

	q->next = S->next;
	S->next = q;
}
int pop(StackPosition S) {
	int x = -1;
	StackPosition temp;
	if (S->next != NULL) {
		x = S->next->data;
		temp = S->next;
		S->next = temp->next;
		free(temp);
	}
	return x;
}
void unos(char i, Position P) {
	Position q = NULL;

	q = (Position)malloc(sizeof(struct dir));
	strcpy(q->name, i);

	while (P->sibling != NULL)
		P = P->sibling;

	q->sibling = P->sibling;
	P->sibling = q;
}
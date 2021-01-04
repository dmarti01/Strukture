#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct cvor* Stog;

struct cvor {
	char el;
	Stog next;
};

void push(char x, Stog S);
char pop(Stog S);
void ispis(Stog S);


int main() {
	struct cvor Head;
	Head.next = NULL;

	FILE* dat;
	char a[15],b[15];
	int i,j,p,x,y,temp;
	dat = fopen("datoteka.txt", "r");
	fgets(a, 15, dat);
	//sscanf(dat, "%s", b);
	printf("%s", a);
	//printf("\n%s", b);
	printf("\n");
	j = 0;
	for (i = 0;a[i] != NULL;i++)
	{
		if (a[i] <= '9' && a[i] >= '1')
			//printf("%c", a[i]); provjera
			push(a[i]-48, &Head);
		else {
			x = pop(&Head);
			y = pop(&Head);
			switch (a[i]) {
			case'+':
				temp = y + x;
				break;
			case'-':
				temp = y - x;
				break;
			case'/':
				temp = y/x;
				break;
			case'*':
				temp = y * x;
				break;
			default:
				printf("Greska!\n");
				break;
			}
			push(temp,&Head);
		}
	}
	j = pop(&Head);
	printf("Rezultat je %d ", j);
   
	fclose(dat);
}

void push(char x, Stog S) {
	Stog q;

	q = (Stog)malloc(sizeof(struct cvor));

	q->el = x;
	q->next = S->next;
	S->next = q;
}
char pop(Stog S) {
	int x = -1;
	Stog temp;
	if (S->next != NULL)
	{
		x = S->next->el;
		temp = S->next;
		S->next = temp->next;
		free(temp);
	}
}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct cvor* Stog;

struct cvor {
	int el;
	Stog next;
};

void push(int x, Stog S);
int pop(Stog S);
void ispis(Stog S);


int main() {
	struct cvor Head;
	Head.next = NULL;

	FILE* dat;
	char a[15];
	int j,x,y,temp,k;

	dat = fopen("datoteka.txt", "r");

	j = 0;
	while(!feof(dat))
	{
		fscanf(dat,"%s",a);
		if (sscanf(a,"%d",&k)==1)
			//printf("%c", a[i]); provjera
			push(k, &Head);
		else {
			x = pop(&Head);
			y = pop(&Head);
			switch (a[0]) {
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
	if (S->next != NULL)
	{
		x = S->next->el;
		temp = S->next;
		S->next = temp->next;
		free(temp);
	}
	return x;
}

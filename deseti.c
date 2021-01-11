#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node* Position;
struct node {
	int c;
	Position L;
	Position R;
};


typedef struct stack* stackPosition;
struct stack {
	int data;
	stackPosition next;
};
void ispis(Position current);
Position umetni(Position current, int br);
void ispis(Position current, FILE* dat2);
void infixtofile(int x, FILE* dat2);


void push(int, stackPosition);
Position pop(stackPosition);


int main() {
	FILE* dat1;
	FILE* dat2;
	char a[15];
	int j, d, l, tmp, k;
	Position root;
	root = NULL;
	char b[15];
	

	stackPosition stog = (stackPosition)malloc(sizeof(struct stack));
	stog->data = NULL;
	stog->next = NULL;

	dat1 = fopen("datoteka.txt", "r");
	dat2 = fopen("infiks.txt", "w");

	j = 0;
	while (!feof(dat1)) {
		fscanf(dat1, "%s", a);
		Position new = (Position)malloc(sizeof(struct node));
		//fscanf(dat1, " %s", new->c);
		new->L = NULL;
		new->R = NULL;
		
		
		
		if (sscanf(a, "%d", &k) == 1) {
			//printf("%d", k);
			push(k, stog);
			root = umetni(root, k);
		}
		else{
			new->R = pop(stog);
			new->L = pop(stog);
			switch (a[0]) {
			case'+':
				tmp = (int)new->L + (int)new->R;
				break;
			case'-':
				tmp = (int)new->L - (int)new->R;
				break;
			case'/':
				tmp = (int)new->L / (int)new->R;
				break;
			case'*':
				tmp = (int)new->L * (int)new->R;
				break;
			default:
				printf("Greska!\n");
				break;
			}
			push(tmp, stog);
		}
	}
	j = pop(stog);
	printf("Rezultat:%d\n", j);
	fclose(dat1);
		
	//root = pop(stog);

	printf("Infix ispis:");
	printf("\n");
	ispis(root,dat2);
	

	fclose(dat2);
}
void push(int x, stackPosition S) {
	stackPosition q;

	q = (stackPosition)malloc(sizeof(struct stack));

	q->data = x;
	q->next = S->next;
	S->next = q;
}
Position pop(stackPosition S) {
	stackPosition tmp;
	Position x=(Position)malloc(sizeof(struct node));
	if (S->next != NULL)
	{
		x = S->next->data;
		tmp = S->next;
		S->next = tmp->next;
		free(tmp);
	}
	return x;
}
void ispis(Position current,FILE* dat2) {
	if (current == NULL)return NULL;

	//inorder ispis
	/*ispis(current->L);
	printf("%d", current->c);
	ispis(current->R);*/

	//infix je ovo
	printf("%d ", current->c);
	infixtofile(current->c, dat2);
	ispis(current->L,dat2);
	ispis(current->R,dat2);

}
Position umetni(Position current, int br)
{

	if (current == NULL)
	{
		current = (Position)malloc(sizeof(struct node));
		current->L = NULL;
		current->R = NULL;
		current->c = br;
	}
	else if (br > current->c)
		current->R = umetni(current->R, br);
	else if (br < current->c)
		current->L = umetni(current->L, br);

	return current;
}
void infixtofile(int x,FILE* dat2) {
	fprintf(dat2, "%d ",x);
}
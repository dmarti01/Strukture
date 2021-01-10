#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX_DIR_LENGTH (256)


typedef struct cvorStabla* Stablo;
struct cvorStabla {
	char ime[MAX_DIR_LENGTH];
	Stablo dijete;
	Stablo brat;
};

typedef struct stog* Pozicija;
struct stog {
	Stablo data;
	Pozicija next;
};


void push(int x, Pozicija S);
Stablo pop(Pozicija S);
Stablo inicijalizacija(char* ime);
void md(Stablo current, char* ime);//napravi
Stablo cd(Stablo current, char* ime);//promijeni 
Stablo cdBack(Stablo current,Pozicija stack);//nazad
void dir(Stablo current);//ispisi dir
void brisi(Stablo current);

int main() {
	char c[MAX_DIR_LENGTH];
	char ime[MAX_DIR_LENGTH];

	Stablo root = NULL;
	Stablo current = NULL;
	struct stog stack;
	stack.next = NULL;

	root = inicijalizacija("C:");
	current = root;

	//md(current, "John");

	//current = cdBack(&stack, current);
	printf("KOMANDE:\n");
	printf("mkdir (ime direktorija)->napravi direktorij\n");
	printf("cd (ime direktorija)->udi u direktorij\n");
	printf("cd..->idi nazad\n");
	printf("dir->ispis direktorija\n");
	printf("izlaz->izlaz logicno :D:D\n\n");


	while (1)
	{
		printf("C:\%s\>", current->ime);

		scanf("%s", c);

		if (strcmp(c, "mkdir")==0){
			scanf("%s", ime);
			md(current, ime);
		}
		else if (strcmp(c, "cd") == 0) {
			printf("Unesi ime direktorija:");
			scanf("%s", ime);
			current = cd(current, ime, &stack);
		}
		else if (strcmp(c, "cd..") == 0) {
			current = cdBack(current, &stack);
		}
		else if (strcmp(c, "dir")==0) {
			dir(current->dijete);
		}
		else if (strcmp(c, "izlaz")==0) {
			/*while (stack.next != NULL)
				current = cdBack(current, &stack);
			free(&stack.next);
			free(&stack);
			brisi(current);*/
			return 0;
		}
		else {
			printf("Unesi normalnu komandu!\n");
		}
	}
	return 0;
}
Stablo inicijalizacija(char* ime) {
	Stablo dir = (Stablo)malloc(sizeof(struct cvorStabla));
	if (!dir) {
		printf("Greska pri alokaciji memorije!\n");
		return NULL;
	}
	strcpy(dir->ime, ime);
	dir->dijete = NULL;
	dir->brat = NULL;
	
}
void md(Stablo current, char* ime) {
	if (current->dijete == NULL) {
		current->dijete = inicijalizacija(ime);
	}
	else {
		Stablo dir = inicijalizacija(ime);
		if (!dir)return -1;
		
		 if (!strcmp(current->dijete->ime, ime))
		{
			printf("Direktorij postoji!\n");
		}
		else if (strcmp(current->dijete->ime, ime) > 0) {
			dir->brat = current->dijete;
			current->dijete = dir;
		}
		else {//treba ovo opravit, negdje je sakrivena greska
			Stablo tmp = current->dijete;
			Stablo tmp1 = current->dijete->brat;
			while (tmp1 != NULL) {
				if (strcmp(tmp1->ime, ime) > 0) {
					break;
					tmp = tmp->brat; 
					tmp1 = tmp1->brat;
				}
			}
			strcpy(dir->ime, ime);
			dir->dijete = NULL;
			dir->brat = tmp->brat;
			tmp->brat = dir;
			/*dir->next = tmp->next;
			tmp->next = dir;*/
		}
	}


}
Stablo cd(Stablo current, char* ime,Pozicija stog) {
	Stablo p = current->dijete;
	while (p != NULL) {
		if (!strcmp(p->ime, ime)) {
			push(p, stog);//mislim da je dobro
			return p;//check dis
		}
		p = p->brat;
	}
	printf("Direktorij ne postoji...\n");
	return current;
}
Stablo cdBack(Stablo current, Pozicija stack) {
	/*strcmp(stack->next->data->ime, "") != 0 ovo je bilo u if :D*/
	if (stack->next!=NULL) {
		/*Pozicija temp = stack->next;
		Stablo p = temp->next->data;
		stack->next = temp->next;
		free(temp);
		return p;*/
		current = pop(stack);
	}
	//takodjer se negdje skriva greska
	return current;
}
void dir(Stablo current) {
	printf("\n");
	while (current != NULL) {
		printf("\t\t\t-%s\n", current->ime);
		current = current->brat;
	}
}

void brisi(Stablo current) {
	if (!current) return;

	brisi(current->brat);
	brisi(current->dijete);
	free(current);
}
void push(Stablo x, Pozicija S) {
	Pozicija q;

	q = (Pozicija)malloc(sizeof(struct stog));

	q->data = x;
	q->next = S->next;
	S->next = q;
}
Stablo pop(Pozicija S) {
	int x = -1;
	Pozicija temp;

	if (S->next != NULL)
	{
		x = S->next->data;
		temp = S->next;
		S->next = temp->next;
		free(temp);
	}
	return x;
}

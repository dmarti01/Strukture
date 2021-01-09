#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct cvor* Pozicija;
struct cvor {
	int broj;
	Pozicija lijevo;
	Pozicija desno;
};



Pozicija umetni(Pozicija current, int el);
Pozicija trazi(Pozicija current, int broj);
Pozicija brisi(Pozicija current, int broj);
Pozicija traziMax(Pozicija current);
Pozicija traziMin(Pozicija current);
void ispis(Pozicija current);

int main(void) {
	Pozicija root = NULL;
	Pozicija temp;
	int x,y,z;
	int o;

	while (1)
	{
		printf("\tIzbornik:");
		printf("\n\t1->Umetanje novog elementa");
		printf("\n\t2->Ispis stabla");
		printf("\n\t3->Trazenje elementa");
		printf("\n\t4->Brisanje elementa");
		printf("\n\t5->Izlaz");
		printf("\n\tOdabir:");
		scanf("%d", &o);

		switch (o) {
		case 1:
			printf("Unesi broj koji zelis unijeti:");
			scanf("%d", &x);
			root=umetni(root, x);
			break;
		case 2:
			ispis(root);
			break;
		case 3:
			printf("Koji broj zelis naci:");
			scanf("%d", &y);
			temp=trazi(root, y);
			if (temp != NULL)
				printf("Element %d se nalazi na %d", temp->broj, temp);
			else
				printf("Broj ne postoji!\n");
			break;
		case 4:
			printf("Koji broj zelis izbrisati:");
			scanf("%d", &z);
			root = brisi(root, z);
			break;
		case 5:
			return 0;
			break;
		default:
			printf("\n\tPotkrala se greska, izaberi validnu operaciju!\n\n");
		}
		
	}

	return EXIT_SUCCESS;
}

Pozicija umetni(Pozicija current,int br)
{

	if (current==NULL)
	{
		current = (Pozicija)malloc(sizeof(struct cvor));
		current->lijevo = NULL;
		current->desno = NULL;
		current->broj = br;
	}
	else if (br > current->broj)
		current->desno = umetni(current->desno,br);
	else if (br < current->broj)
		current->lijevo = umetni(current->lijevo, br);

	return current;
}
Pozicija trazi(Pozicija current, int broj) {
	if (current == NULL)return NULL;

	if (current->broj > broj) {
		return trazi(current->lijevo, broj);
	}
	else if (current->broj < broj) {
		return trazi(current->desno, broj);
	}
	else {
		return current;
	}
}
Pozicija brisi(Pozicija current, int broj) {
	if (current == NULL)return NULL;
	if (current->broj == broj) {
		if (current->lijevo != NULL) {
			Pozicija tmp = traziMax(current->lijevo);
			current->broj = tmp->broj;
			current->desno = brisi(current->desno, tmp->broj);
		}
		else if (current->desno != NULL) {
			Pozicija tmp = traziMin(current->desno);
			current->broj = tmp->broj;
			current->desno = brisi(current->desno, tmp->broj);
		}
		else {
			free(current);
			return NULL;
		}
	}
	else if (current->broj > broj) {
		current->lijevo = brisi(current->lijevo, broj);
	}
	else {
		current->desno = brisi(current->desno, broj);
	}
	return current;
}
Pozicija traziMax(Pozicija current) {
	if (current == NULL)return NULL;
	while (current->desno != NULL) current = current->desno;
	return current;
}
Pozicija traziMin(Pozicija current) {
	if (current == NULL)return NULL;
	while (current->lijevo != NULL)current = current->lijevo;
	return current;
}
void ispis(Pozicija current) {
	if (current == NULL)return NULL;
	 
	//inorder ispis
	ispis(current->lijevo);
	printf("%d ",current->broj);
	ispis(current->desno);
	
	//infix je ovo
	/*printf("%d", current->broj);
	ispis(current->lijevo);
	ispis(current->desno);*/
	
}
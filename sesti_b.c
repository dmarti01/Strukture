#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

#define MAX 100
#define MIN 10

typedef struct cvor* Red;

struct cvor {
	int el;
	Red next;
};

void stavi(int x, Red S);
void skini(Red S);
void ispis(Red S);


int main() {
	int sl;
	char c;

	struct cvor Head;
	Head.next = NULL;

	srand(time(0));

	while (1) {
		printf("Red\n\t->D za staviti\n\t->I za skinuti\n\t\n\t->E za izlaz\n\t->Vas izbor: ");
		scanf("%c", &c);
		switch (c) {
		case'd':
		case'D':
			sl = MIN + rand() % ((MAX - MIN) + 1);
			stavi(sl, &Head);
			ispis(Head.next);
			break;
		case'i':
		case'I':
			skini(&Head);
			printf("Nakon Skidanja:\n");
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
  void stavi(int x, Red S) {
	Red q;
	q = (Red)malloc(sizeof(struct cvor));

	q->el = x;
	q->next = S->next;
	S->next = q;
}
  void skini(Red S) {
	  Red temp, pre;
	
	  temp = S->next;
	  pre = NULL;
	  while (temp && temp->next) {
		 
		  pre = temp;
		  temp = temp->next;
	  }
	  if (pre) {
		  free(pre->next);
		  pre->next = NULL;
	  }
  }
void ispis(Red S) {
	while (S != NULL)
	{
		printf("%d", S->el);
		S = S->next;
		printf("\n");
	}
}
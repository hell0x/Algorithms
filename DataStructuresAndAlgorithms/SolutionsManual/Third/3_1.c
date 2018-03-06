#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

#ifndef _List_H
#define _List_H

struct Node;
typedef struct Node *PtrNode;
typedef PtrNode List;
typedef PtrNode Position;

void Insert(ElementType X, List L, Position P);
#endif

struct Node{
	ElementType Element;
	Position Next;
};

void Insert(ElementType X, List L, Position P){
	Position TmpCell;

	TmpCell = malloc(sizeof(struct Node));
	if(TmpCell == NULL)
		fprintf(stderr, "%s\n", "Out of space"),exit(1);
	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
}

int main(){
	int i;
	List L;
	Position P;
	L = malloc(sizeof(struct Node));
	L->Next = NULL;
	P = L;
	while(scanf("%d", &i) == 1)
		Insert(i, L, P);
	
	while(P->Next != NULL){
		printf("%d",P->Next->Element);
        P = P->Next;
	}
	return 0;
}
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
void PrintList(List L);
Position Tail(List L);
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

void PrintList(List L){
	while(L->Next != NULL){
		printf("%d ", L->Next->Element);
		L = L->Next;
	}
}

Position Tail(List L){
	Position P;
	P = L;
	while(P->Next != NULL)
		P = P->Next;
	return P;
}

int main(){
	int i;
	List L;
	Position P;
	L = malloc(sizeof(struct Node));
	L->Next = NULL;
	P = Tail(L);
	while(scanf("%d", &i) == 1){
		Insert(i, L, P);
		P = Tail(L);
	}
	PrintList(L);
	return 0;
}
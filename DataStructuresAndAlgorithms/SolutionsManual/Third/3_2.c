#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElementType;

#ifndef _List_H
#define _List_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List InitList(List L);
void Insert(ElementType X, List L, Position P);
Position Tail(List L);
void PrintList(List L);
void PrintLots(List L, List P);

#endif

struct Node{
	ElementType Element;
	Position    Next;
};

List InitList(List L){
	L = malloc(sizeof(struct Node));
	if(L == NULL)
		fprintf(stderr, "%s\n", "Out of space"),exit(1);
	L->Next = NULL;
	return L;
}

void Insert(ElementType X, List L, Position P){
	Position TmpCell;

	TmpCell = malloc(sizeof(struct Node));
	if(L == NULL)
		fprintf(stderr, "%s\n", "Out of space"),exit(1);

	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
}

Position Tail(List L){
	Position P;
	P = L;
	while(P->Next != NULL)
		P = P->Next;
	return P;
}

void PrintList(List L){
	while(L->Next != NULL){
		printf("%d ", L->Next->Element);
		L = L->Next;
	}
	printf("\n");
}

void PrintLots(List L, List P){
	int PreviousCell, Count;
	Position Psn;
	PreviousCell = 0;
	Psn = P->Next;
	while(Psn != NULL){
		Count = Psn->Element - PreviousCell;
		PreviousCell = Psn->Element;
		while(Count){
			L = L->Next;
			Count--;
		}
		printf("%d ", L->Element);
		Psn = Psn->Next;
	}
}

int main(){
	double start, end;
	int i, j;
	List L, P;
	Position Psn;
	L = InitList(L);
	P = InitList(P);
	Psn = L;
	for(i=0; i<128; i++){
		Insert(i, L, Psn);
		Psn = Tail(L);
	}
	Psn = P;
	while(scanf("%d", &j) == 1){
		Insert(j, P, Psn);
		Psn = Tail(P);
	}
	// PrintList(L);
	// PrintList(P);
	start = clock();
	PrintLots(L, P);
	end = clock();
	printf( "%f seconds\n",(end - start) / CLOCKS_PER_SEC);
	return 0;
}
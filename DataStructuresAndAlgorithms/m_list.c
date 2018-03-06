#include "m_list.h"
#include "fatal.h"
#include <stdlib.h>

struct Node{
	ElementType Element;
	Position Next;
};

List MakeEmpty(List L){
	if(L != NULL)
		DeleteList(L);
	L = malloc(sizeof(struct Node));
	if(L == NULL)
		FatalError("Out of memory");
	L->Next = NULL;
	return L;
}

int IsEmpty(List L){
	return L->Next == NULL;
}

int IsLast(Position P, List L){
	return P->Next == NULL;
}

void Insert(ElementType X, List L, Position P){
	Position TmpCell;

	TmpCell = malloc(sizeof(struct Node));
	if(TmpCell == NULL)
		FatalError("Out of memory");
	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
}

void Delete(ElementType X, List L){
	Position P, TmpCell;

	P = FindPrevious(X, L);
	if(!IsLast(P, L)){
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free(TmpCell);
	}
}

void DeleteList(List L){
	Positon P, Tmp;

	P = L->Next;
	L->Next = NULL;
	while(P != NULL){
		Tmp = P->Next;
		free(P);
		P = Tmp;
	}
}

Position Find(ElementType X, List L){
	Position P;

	P = L->Next;
	while(P != NULL && P->Element != X)
		P = P->Next;
	return P;
}

Position FindPrevious(ElementType X, List L){
	Position P;

	P = L;
	while(P != NULL && P->Next->Element != X)
		P = P->Next;
	return P;
}

Position Header(List L){
	return L;
}

Position First(List L){
	return L->Next;
}

Position Advance(Position P){
	return P->Next;
}

ElementType Retrieve(Position P){
	return P->Element;
}
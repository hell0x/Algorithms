#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

#ifndef _List_H
#define _List_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

void InitList(List L);
void Insert(ElementType X, List L, Position P);
void PrintLots(List L, List P);

#endif

struct Node{
	ElementType Element;
	Position    Next;
};

void InitList(List L){
	L = malloc(sizeof(struct Node));
	if(L == NULL)
		fprintf(stderr, "%s\n", "Out of space"),exit(1);
}
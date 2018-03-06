#include "treap.h"
#include "fatal.h"
#include <stdlib.h>

struct TreapNode{
	ElementType Element;
	Treap Left;
	Treap Right;
	int Priority;
};

Position NullNode = NULL;

Treap Initialize(void){
	if(NullNode == NULL){
		NullNode = malloc(sizeof(struct TreapNode));
		if(NullNode == NULL)
			FatalError("Out of space");
		NullNode->Left = NullNode->Right = NullNode;
		NullNode->Priority = Infinity;
	}
	return NullNode;
}

int Random(void){
	return rand() - 1;
}

Treap MakeEmpty(Treap T){
	if(T != NullNode){
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NullNode;
}

void PrintTree(Treap T){
	if(T != NullNode){
		PrintTree(T->Left);
		printf("%d ", T->Element);
		PrintTree(T->Right);
	}
}

Position Find(ElementType X, Treap T){
	if(T == NullNode)
		return NullNode;
	if(X < T->Element)
		return find(X, T->Left);
	else if(X > T->Element)
		return Find(X, T->Right);
	else
		return T;
}
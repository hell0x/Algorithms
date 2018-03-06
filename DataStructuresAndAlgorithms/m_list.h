		typedef int ElemnetType;
/*Start*/
		#ifndef _List_H
		#define _List_H

		struct Node;
		typedef struct Node *PtrToNode;
		typedef PtrToNode List;
		typedef PtrToNode Position;

		List MakeEmpty(List L);
		int IsEmpty(List L);
		int IsLast(Position P, List L);
		void Insert(ElementType X, List L, Position P);
		void Delete(Position P, List L);
		void DeleteList(Position P, List L);
		Position Find(ElemnetType X, List L);
		Position FindPrevious(ElementType X, List L);
		Position Header(List L);
		Position First(List L);
		Position Advance(Position P);
		ElementType Retrieve(Position P);

		#endif
/*End*/
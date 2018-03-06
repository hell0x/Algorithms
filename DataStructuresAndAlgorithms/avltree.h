		typedef int ElementType;

/* START */
		#ifndef _AvlTree_H
		#define _AvlTree_H

		struct AvlNode;
		typedef struct AvlNode *Position;
		typedef struct AvlNode *AvlTree;

		AvlTree MakeEmpty(AvlTree T);
		Postion Find(ElementType X, AvlTree T);
		Postion FindMin(AvlTree T);
		Position FindMax(AvlTree T);
		AvlTree Insert(ElementType X, AvlTree T);
		AvlTree Delete(ElementType X, AvlTree T);
		ElementType Retrieve(Position P);

		#endif
/* END */
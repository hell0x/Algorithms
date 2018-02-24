		typedef int ElementType;
/*Start*/
		#ifndef _Stack_H
		#define _Stach_H

		struct Node;
		typedef struct Node *PtrToNode;
		typedef PtrToNode Stack;

		int IsEmpty(Stack S);
		void MakeEmpty(Stack S);
		Stack CreateStack(void);
		void DisposeStack(Stack S);
		void Push(ElementType X, Stack S);
		void Pop(Stack S);
		ElementType Top(Stack S);

		#endif
/*End*/
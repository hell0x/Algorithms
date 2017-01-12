#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OK 1;
#define ERROR 0;

typedef int ElemType;
typedef int Status;

typedef struct Node{
	ElemType data;
	struct Node *next;
}Node, *LinkList;

Status CreateListTail(LinkList *L, int n){
	LinkList p, r;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	r = *L;
	for(i=0; i<n; i++){
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand()%100 + 1;
		r->next = p;
		r = p;
	}
	r->next = NULL;
}

Status ClearList(LinkList *L){
	LinkList p, q;
	p = (*L)->next;
	while(p){
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;
	return OK;
}

void visit(ElemType e){
	printf("%d ", e);
}

void TraverseList(LinkList L, void (*visit)(ElemType)){
	LinkList p = L->next;
	while(p){
		visit(p->data);
		p = p->next;
	}
}

//反转单链表
LinkList ReserseList(LinkList L){
	LinkList p = NULL;
	LinkList q = L;

	while(q){
		LinkList nextq = q->next;
        q->next = p;
        p = q;
        q = nextq;
	}
	return p;
}   

int main(){
	LinkList L, *head, newHead, newList;
	CreateListTail(&L, 5);
	printf("List:");
	TraverseList(L, visit);

	L = ReserseList(L);
	printf("\nList:");
	TraverseList(L, visit);
	ClearList(&L);
}
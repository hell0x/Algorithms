#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OK 1;
#define ERROR 0;

typedef int ElemType;
typedef int Status;

/*线性表的单链表储存结构*/
typedef struct Node{
	ElemType data;
	struct Node *next;
}Node;
typedef struct Node *LinkList;   /*定义LinkList*/

/*头插法创建单链表*/
Status CreateListHead(LinkList *L, int n){
	LinkList p;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
	for(i=0; i<n; i++){
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand()%100 + 1;
		p->next = (*L)->next;
		(*L)->next = p;
	}
}

/*尾插法创建单链表*/
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

/*单链表的整表删除*/
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

/*获取元素*/
Status GetElem(LinkList L, int i, ElemType *e){
	int j;
	LinkList p;
	p = L->next;
	j = 1;
	while(p && j < i){
		p = p->next;
		j++;
	}
	if(!p || j > i){
		return ERROR;
	}
	*e = p->data;
	return OK;
}

/*插入元素*/
Status ListInsert(LinkList L, int i, ElemType e){
	int j;
	LinkList p = L, s;
	j = 1;
	while(p && j < i){
		p = p->next;
		j++;
	}
	if(!p || j > i){
		return ERROR;
	}
	s = (LinkList)malloc(sizeof(Node));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

/*删除元素*/
Status ListDelete(LinkList L, int i, ElemType *e){
	int j;
	LinkList p = L, q;
	j = 1;
	while(p && j < i){
		p = p->next;
		j++;
	}
	if(!p || j > i){
		return ERROR;
	}
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	return OK;
}

/**
 * 访问元素
 */
void visit(ElemType e){
	printf("%d ", e);
}

/**
 * 遍历线性表
 */
void TraverseList(LinkList L, void (*visit)(ElemType)){
	LinkList p = L->next;
	while(p){
		visit(p->data);
		p = p->next;
	}
}

int main(){
	LinkList L;
	ElemType e;
	CreateListTail(&L, 10);

	GetElem(L, 4, &e);
	printf("%d\n", e);

	ListInsert(L, 8, 666);
	ListDelete(L, 10, &e);

	printf("list:");
	TraverseList(L, visit);

	ClearList(&L);

	return OK;
}

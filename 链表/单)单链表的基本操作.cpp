#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int ElemType;
typedef int Status;

/**
 * 储存结构
 */
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

/**
 * 初始化线性表
 */
void InitList(LinkList *L){
	*L = (LinkList)malloc(sizeof(LNode));
	if(!L){
		exit(OVERFLOW);
	}
	(*L)->next = NULL;
}

/**
 * 销毁线性表
 */
void DestroyList(LinkList *L){
	LinkList temp;
	while(*L){
		temp = (*L)->next;
		free(*L);
		*L = temp;
	}
}

/**
 * 判断是否为空
 */
Status isEmpty(LinkList L){
	if(L->next){
		return FALSE;
	}else{
		return TRUE;
	}
}

/**
 * 获取长度
 */
int GetLength(LinkList L){
	int i = 0;
	LinkList p = L->next;
	while(p){
		i++;
		p = p->next;
	}
	return i;
}

/**
 * 根据位置获取元素
 */
Status GetElem(LinkList L, int i, ElemType *e){
	int j = 1;
	LinkList p = L->next;
	while(p && j < i){
		j++;
		p = p->next;
	}
	if(!p || j > i){
		return ERROR;
	}
	*e = p->data;
	return OK;
}

/**
 * 插入元素
 */
Status InsertElem(LinkList L, int i, ElemType e){
	int j = 0;
	LinkList s, p = L;
	while(p && j < i){
		j++;
		p = p->next;
	}
	if(!p || j > i){
		return ERROR;
	}
	s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

/**
 * 删除元素并返回值
 */
Status DeleteElem(LinkList L, int i, ElemType *e){
	int j = 0;
	LinkList q, p = L;
	while(p->next && j < i - 1){
		j++;
		p = p->next;
	}
	if(!p && j > i - 1){
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
	InitList(&L);
	ElemType e;
	int i;
	if(L){
		printf("Init success\n");
	}
	if(isEmpty(L)){
		printf("list is empty\n");
	}

	for(i = 0; i < 10; i++){
		InsertElem(L, i, i);
	}

	if(GetElem(L, 1, &e)){
		printf("The first element is %d\n", e);
	}

	printf("length is %d\n", GetLength(L));

	DeleteElem(L, 1, &e);
	printf("delete first element is %d\n", e);

	printf("list:");
	TraverseList(L, visit);

	DestroyList(&L);
	if(!L){
		printf("\ndestroy success\n");
	}
}
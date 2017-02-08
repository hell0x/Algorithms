#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int SElemType;

typedef struct StackNode{
	SElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef struct LinkStack{
	LinkStackPtr top;
	int count;
}LinkStack;

//栈的初始化
Status init(LinkStack *S){
	S->top = NULL;
	return OK;
}

//是否为空
Status StackEmpty(LinkStack *S){
	if(S->top == NULL)
		return TRUE;
	else
		return FALSE;
}

//入栈
Status Push(LinkStack *S, SElemType e){
	LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
	s->data = e;
	s->next = S->top;
	S->top = s;
	S->count++;
	return OK;
}

//获取栈顶元素
Status Top(LinkStack *S){
	if(S->top == NULL){
		return NULL;
	}
	return S->top->data;
}

//出栈
Status Pop(LinkStack *S, SElemType *e){
	LinkStackPtr p;
	if(StackEmpty(S))
		return ERROR;
	*e = S->top->data;
	p = S->top;
	S->top = S->top->next;
	free(p);
	S->count--;
	return OK;
}

//遍历
Status traverse(LinkStack *S){
	LinkStackPtr p = S->top;
	if(StackEmpty(S))
		return OK;
	printf("Elements:");
	while(p){
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}

//清空栈
Status clearStack(LinkStack *S){
	if(StackEmpty(S))
		return OK;
	else{
		LinkStackPtr p = S->top, q;
		while(p->next){
			q = p;
			p = p->next;
			free(q);
		}
		S->top = NULL;
	}
	return OK;
}

int main(void){
	LinkStack S;
	SElemType e;
	init(&S);
	for(int n=0; n<10; n++){
		Push(&S, n+1);
	}
	traverse(&S);
	Pop(&S, &e);
	printf("%d\n", e);
	traverse(&S);
	printf("%d\n",Top(&S));
	clearStack(&S);
	traverse(&S);

	return 0;
}
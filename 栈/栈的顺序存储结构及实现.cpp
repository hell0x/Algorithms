#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define OK 1
#define ERROR 0

typedef int SElemType;
typedef int Status;
typedef struct{
	SElemType data[MAXSIZE];
	int top;
}SqStack;

//入栈
Status Push(SqStack *S, SElemType e){
	if(S->top == MAXSIZE - 1){
		return ERROR;
	}
	S->top++;
	S->data[S->top] = e;
	return OK;
}

//出栈
Status Pop(SqStack *S, SElemType *e){
	if(S->top == -1)
		return ERROR;
	*e = S->data[S->top];
	S->top--;
	return OK;
}
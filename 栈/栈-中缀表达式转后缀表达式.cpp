#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

/*链式栈的实现*/
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
	while(p){
		printf("%c ", p->data);
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
/*链式栈的实现*/

/**
 * isNumber 
 * 判断元素是否是数字
 */
int isNumber(char c){
	int ret = 0;
	ret = (c >= '0') && (c <= '9');
	return ret;
}

/**
 * isMark
 * 判断元素是否是加减乘除这四个运算符
 */
int isMark(char c){
	int ret = 0;
	ret = ((c == '+') || (c == '-') || (c == '*') || (c == '/'));
	return ret;
}

/**
 * isLBracket
 * 判断元素是否是左括号
 */
int isLBracket(char c){
	int ret = 0;
	ret = (c == '(');
	return ret;
}

/**
 * isRBracket
 * 判断元素是否是右括号
 */
int isRBracket(char c){
	int ret = 0;
	ret = (c == ')');
	return ret;
}

/**
 * priority
 * 对传进来的元素划分优先级
 */
int priority(char c){
	int ret = 0;
	if(c == '+' || c == '-')
		ret = 2;
	else if(c == '*' || c == '/')
		ret = 3;
	else
		ret = 1;
	return ret;
}

int infixToSuffix(char *c){
	int ret = 0;
	int i = 0;
	LinkStack S;
	SElemType e;
	init(&S);

	while(c[i] != '\0'){
		if(isNumber(c[i])){
			printf("%c ", c[i]);
		}else if(isLBracket(c[i])){
			Push(&S, c[i]);
		}else if(isMark(c[i])){
			if(StackEmpty(&S)){
				Push(&S, c[i]);
			}else{
				while(priority(c[i]) <= priority(Top(&S))){
					Pop(&S, &e);
					printf("%c ", e);
				}
				Push(&S, c[i]);
			}
		}else if(isRBracket(c[i])){
			while(Top(&S) != '('){
				Pop(&S, &e);
				printf("%c ", e);
			}
			Pop(&S, &e);
		}else{
			printf("input error\n");
		}
		i++;
	}
	traverse(&S);
	clearStack(&S);
	return OK;
}

int main(void){
	char *c;
	scanf("%s", c);
	infixToSuffix(c);
	return 0;
}
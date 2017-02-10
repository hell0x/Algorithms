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
	printf("Elements:");
	while(p){
		printf("%c ", p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}

//栈里面的元素数量
Status stackSize(LinkStack *S){
	LinkStackPtr p = S->top;
	int n = 0;
	if(StackEmpty(S))
		return 0;
	while(p){
		n++;
		p = p->next;
	}
	return n;
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

char* infixToSuffix(char *c){
	LinkStack S;
	SElemType e;
	int i = 0;
	char a[100], *p;
	p = a;
	init(&S);
	// init(&Ret);

	while(c[i] != '\0'){
		if(isNumber(c[i])){
			// Push(&Ret, c[i]);
			*p = c[i];
			*p = *(p+1);
		}else if(isLBracket(c[i])){
			Push(&S, c[i]);
		}else if(isMark(c[i])){
			if(StackEmpty(&S)){
				Push(&S, c[i]);
			}else{
				while(priority(c[i]) <= priority(Top(&S))){
					Pop(&S, &e);
					// Push(&Ret, e);
					*p = e;
					*p = *(p+1);
				}
				Push(&S, c[i]);
			}
		}else if(isRBracket(c[i])){
			while(Top(&S) != '('){
				Pop(&S, &e);
				// Push(&Ret, e);
				*p = e;
				*p = *(p+1);
			}
			Pop(&S, &e);
		}else{
			printf("input error\n");
		}
		i++;
	}
	// printf("%d\n", stackSize(&S));
	// printf("%d\n", stackSize(&Ret));
	while(stackSize(&S) > 0 && c[i] == '\0'){
		Pop(&S, &e);
		// Push(&Ret, e);
		*p = e;
		*p = *(p+1);
	}
	// traverse(&Ret);
	// clearStack(&S);
	return p;
}

int main(void){
	char *c, *r;
	scanf("%s", c);
	r = infixToSuffix(c);
	printf("%s\n", r);
	return 0;
}
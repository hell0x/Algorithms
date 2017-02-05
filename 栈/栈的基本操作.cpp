#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define true 1
#define false 0


typedef struct Node
{
    int data;
    struct Node *pNext;
}NODE, *PNODE;

typedef struct Stack
{
    PNODE pTop;
    PNODE pBottom;
}STACK, *PSTACK;

void init(PSTACK pS);
void push(PSTACK pS, int val);
void traverse(PSTACK pS);
int pop(PSTACK pS , int *val);
void clear(PSTACK pS);
int empty(PSTACK pS);

int main(void)
{
    STACK S ;
    int val;
    int i;
    
    init(&S);
    
    push(&S,1);
    push(&S,2);
    push(&S,3);
    push(&S,4);
    push(&S,5);
    push(&S,6);

    traverse(&S);
    
    if(pop(&S ,&val))
    {
        printf("%d\n",val);
    }
    else
    {
        printf("pop error\n");
    }
    traverse(&S);

    clear(&S);
    
    traverse(&S);
    
    return 0 ;
}

//栈的初始化
void init(PSTACK pS)
{
    pS -> pTop = (PNODE)malloc(sizeof(NODE));
    
    if(NULL == pS -> pTop)
    {
        printf("error");
        exit(-1);
    }
    else
    {
        pS -> pBottom = pS -> pTop;
        pS -> pTop -> pNext = NULL;
    }
    
    return ;
}

//入栈
void push(PSTACK pS , int val)
{
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    
    pNew -> data = val;
    pNew -> pNext = pS -> pTop;
    pS -> pTop = pNew;
    
    return ;
}

//遍历
void traverse(PSTACK pS)
{
    PNODE p = pS -> pTop;
    
    printf("element:");
    while(p != pS -> pBottom)
    {
        printf("%d\t", p -> data);
        p = p -> pNext;
    }
    
    printf("\n");
    return ;
}

//是否为空
int empty(PSTACK pS)
{
    if(pS -> pTop == pS -> pBottom)
    {
        return true;
    }
    else
        return false;
}

//出栈
int pop(PSTACK pS , int *val)
{
    if(empty(pS))
    {
        return false;
    }
    else
    {
        PNODE r = pS -> pTop;
        *val = r -> data;
        pS -> pTop = r -> pNext;
        free(r);
        r = NULL;
    }
}

//清空栈
void clear(PSTACK pS)
{
    if(empty(pS))
    {
        return;
    }
    else
    {
        PNODE p = pS -> pTop;
        PNODE q = NULL;
        
        while(p != pS -> pBottom)
        {
            q = p -> pNext;
            free(p);
            p = q ;
        }
        
        pS -> pTop = pS -> pBottom;
        
        return;
    }
}
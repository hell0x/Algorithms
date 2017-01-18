#include<iostream>
using namespace std;

/*定义双链表结构*/
typedef struct node{
	int data;
	struct node *prior;   //指向前驱节点
	struct node *next;   //指向后继结点
}DNode;

/*创建双链表*/
DNode* CreateDLink(){
	int x;
	DNode *head, *p, *r;
	head = new node;
	r = head;
	while(scanf("%d", &x) != EOF){
		p = new node;
		p->data = x;
		r->next = p;
		r = p;
	}
	r->next = NULL;
	return head;
}

/*双链表插入*/
DNode* DListInsert(DNode* head, int i, int x){
	DNode *p, *s;
	p = head;
	int j = 1;
	while(p && j < i){
		p = p->next;
		j++;
	}
	if(!p || j > i){
		return 0;
	}
	s = new node;
	s->data = x;
	s->next = p->next;
	p->next->prior = s;
	s->prior = p;
	p->next = s;
	return head;
}

/*双链表删除*/
DNode* DListDelete(DNode* head, int i){
	DNode *p, *q;
	p = head;
	int j = 1;
	while(p && j < i){
		p = p->next;
		j++;
	}
	if(!p || j > i){
		return 0;
	}
	q = p->next;
	p->next = q->next;
	q->next->prior = p;
	free(q);
	return head;
}

void TraverseList(DNode* head){
	DNode *p = head->next;
	while(p){
		cout<<p->data<<" ";
		p = p->next;
	}
	cout<<endl;
}

int main(){
	DNode *L;
	L = CreateDLink();
	TraverseList(L);
	L = DListInsert(L, 3, 99);
	TraverseList(L);
	L = DListDelete(L, 4);
	TraverseList(L);
	return 0;
}
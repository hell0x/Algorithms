#include<iostream>
using namespace std;

struct node{
	int co;   //系数
	int exp;   //指数
	struct node *next;
};

node* CreateList(){
	node *head;
	node *s, *p;
	int c, e;
	head = new node;   //定义头节点
	head->next = NULL;
	cout<<"请输入系数、指数(以输入9999结束):"<<endl;
	cin>>c>>e;
	p = head;
	while(c!=9999 && e!=9999){
		s = new node;   //定义新节点
		s->co = c;
		s->exp = e;
		p->next = s;
		p = s;
		p->next = NULL;
		cout<<"请输入系数、指数(以输入9999结束):"<<endl;
		cin>>c>>e;
	}
	return head;
}

void Display(node *head){
	if(head == NULL){
		cout<<"多项式不存在!"<<endl;
		return ;
	}
	node* p;
	p = head->next;
	while(p){
		if(p->co > 0)
			cout<<p->co<<"x^"<<p->exp;
		else
			cout<<"("<<p->co<<")"<<"x^"<<p->exp;
		if(p->next)
			cout<<"+";
		p = p->next;
	}
	cout<<endl<<endl;
}

node* Add(node *A, node *B){
	node *C = new node;
	C->next = NULL;
	node *p1 = A->next;
	node *p2 = B->next;
	node *p3;
	node *rearC = C;
	while(p1 != NULL && p2 != NULL){
		if(p1->exp < p2->exp){
			p3=new node;
			p3->co=p1->co;
			p3->exp=p1->exp;
			p3->next=NULL;
			rearC->next=p3;
			rearC=p3;
			p1=p1->next;
		}else if (p1->exp > p2->exp){
			p3=new node;
			p3->co=p2->co;
			p3->exp=p2->exp;
			p3->next=NULL;
			rearC->next=p3;
			rearC=p3;
			p2=p2->next;
		}
		else{
			if((p1->co + p2->co) != 0){
				p3=new node;
				p3->co = p1->co + p2->co;
				p3->exp= p1->exp;
				p3->next=NULL;
				rearC->next=p3;
				rearC=p3;
			}
			p1=p1->next;
			p2=p2->next;
		}
	}
	if(p1==NULL)
	{
		while(p2!=NULL)
		{
			p3=new node;
			p3->co=p2->co;
			p3->exp=p2->exp;
			p3->next=NULL;
			rearC->next=p3;
			rearC=p3;
			p2=p2->next;
		}
	}
	else //p2==NULL
	{
		while(p1!=NULL)
		{
			p3=new node;
			p3->co=p1->co;
			p3->exp=p1->exp;
			p3->next=NULL;
			rearC->next=p3;
			rearC=p3;
			p1=p1->next;
		}
	}
	return C;
}

int main(){
	cout<<"多项式A:"<<endl;
	node *PL1;
	PL1 = CreateList();
	cout<<"多项式A=";
	Display(PL1);

	count<<"多项式B:"<<endl;
	node *PL2;
	PL2 = CreateList();
	cout<<"多项式B=";
	Display(PL2);

	count<<"多项式A+B=";
	node *PL3;
	PL3 = Add(PL1, PL2);
	Display(PL3);

	return 0;
}
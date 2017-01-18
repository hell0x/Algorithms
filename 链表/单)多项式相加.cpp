/*实验2
3. 试写出两个一元多项式相加的算法。
用链表来存储一元多项式，并且要在程序中验证其功能实现。
此题的源程序保存为2_e1.cpp
*/
#include<iostream>
using namespace std;

struct node
{
	int co;    //系数
	int exp;   //指数
	struct node * next;
};

node* Creat() 
{//尾插法建表，有头结点
	node* head; 
	node* s, *p; 
	int c, e;
	head=new node; 		//生成头结点
	head->next=NULL;
	cout<<"请分别输入新的一项的系数、指数(以输入9999作为结束):"<<endl;
	cin>>c>>e;
	while(c!=9999 && e!=9999) //输入并检测结束
	{
		s=new node;			//生成新结点
		s->co = c;			//装入数据
		s->exp = e;
		p=head;
		while(p->next!=NULL)
		{
			p=p->next;
		}		 
		p->next = s;  //插到最后一个结点后
		s->next = NULL;  
		cout<<"请分别输入新的一项的系数、指数(以输入9999作为结束):"<<endl;
		cin>>c>>e;	
	}
	return  head;
}

void Display(node * head)
{
	if(head==NULL)
	{
		cout<<"多项式不存在！"<<endl;
		return ;
	}	
	node* p;
	p=head->next;
	while(p!=NULL)
	{
		if(p->co>0)
			cout<<p->co<<"x^"<<p->exp;
		else
			cout<<"("<<p->co<<")"<<"x^"<<p->exp;
		if(p->next!=NULL)
			cout<<"+";
		p=p->next;
	}
	cout<<endl<<endl;

}

node* Add(node * A, node * B)
{
	node * C=new node;
	C->next=NULL;
	node * p1=A->next;
	node * p2=B->next;
	node * p3;
	node * rearC=C;
	while(p1!=NULL && p2!=NULL)
	{
		if(p1->exp < p2->exp)
		{
			p3=new node;
			p3->co=p1->co;
			p3->exp=p1->exp;
			p3->next=NULL;
			rearC->next=p3;
			rearC=p3;
			p1=p1->next;
		}
		else if (p1->exp > p2->exp)
		{
			p3=new node;
			p3->co=p2->co;
			p3->exp=p2->exp;
			p3->next=NULL;
			rearC->next=p3;
			rearC=p3;
			p2=p2->next;
		}
		else //p1->exp == p2->exp
		{
			if((p1->co + p2->co) != 0)
			{
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
int main()
{
	cout<<"多项式A："<<endl;
	node * PL1;
	PL1=Creat();
	cout<<"多项式A=";
	Display(PL1);

	cout<<"多项式B："<<endl;
	node * PL2;
	PL2=Creat();
	cout<<"多项式A=";
	Display(PL2);

	cout<<"多项式A+B=";
	node * PL3;
	PL3=Add(PL1,PL2);
	Display(PL3);

	return 0;
}
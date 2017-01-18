#include<iostream>
using namespace std;

struct node{
	int co;   //ϵ��
	int exp;   //ָ��
	struct node *next;
};

node* CreateList(){
	node *head;
	node *s, *p;
	int c, e;
	head = new node;   //����ͷ�ڵ�
	head->next = NULL;
	count<<"����˳��ָ���ɴ�С����"<<endl;
	cout<<"������ϵ����ָ��(������9999����):"<<endl;
	cin>>c>>e;
	p = head;
	while(c!=9999 && e!=9999){
		s = new node;   //�����½ڵ�
		s->co = c;
		s->exp = e;
		p->next = s;
		p = s;
		p->next = NULL;
		cout<<"������ϵ����ָ��(������9999����):"<<endl;
		cin>>c>>e;
	}
	return head;
}

void Display(node *head){
	if(head == NULL){
		cout<<"����ʽ������!"<<endl;
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
	while(p1 && p2){
		if(p1->exp > p2->exp){
			//�������ʽA��ָ������B��ָ������ȡA��ָ����ϵͳ��A��ָ�����
			p3 = new node;
			p3->co = p1->co;
			p3->exp = p1->exp;
			p3->next = NULL;
			rearC->next = p3;
			rearC = p3;
			p1 = p1->next;
		}else if(p1->exp < p2->exp){
			//�������ʽA��ָ��С��B��ָ������ȡB��ָ����ϵͳ��B��ָ�����
			p3 = new node;
			p3->co = p2->co;
			p3->exp = p2->exp;
			p3->next = NULL;
			rearC->next = p3;
			rearC = p3;
			p2 = p2->next;
		}else{
			//�����ǰ����ʽA����Ͷ���ʽB����ָ����Ȳ�����Ӳ�����0����p3��ϵ��ȡp1��p2�ĺͣ�ָ��ȡp1��p2��ָ��
			if((p1->co + p2->co) != 0){
				p3 = new node;
				p3->co = p1->co + p2->co;
				p3->exp = p1->exp;
				p3->next = NULL;
				rearC->next = p3;
				rearC = p3;
			}
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	//���p1�����Ѿ������꣬��rearCָ��p2ʣ����
	if(!p1){
		rearC = p2;
	}
	//���p2�����Ѿ������꣬��rearCָ��p1ʣ����
	if(!p2){
		rearC = p1;
	}
	return C;
}

int main(){
	cout<<"����ʽA:"<<endl;
	node *PL1;
	PL1 = CreateList();
	cout<<"����ʽA=";
	Display(PL1);

	cout<<"����ʽB:"<<endl;
	node *PL2;
	PL2 = CreateList();
	cout<<"����ʽB=";
	Display(PL2);

	cout<<"����ʽA+B=";
	node *PL3;
	PL3 = Add(PL1, PL2);
	Display(PL3);

	return 0;
}
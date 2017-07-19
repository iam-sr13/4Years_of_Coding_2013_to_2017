#ifndef _MYSTACK_
#define _MYSTACK_

#include<iostream>
using namespace std;

struct node
{	
	int data;
	node* next;	
	node(){this->next=NULL; this->data=0;}	
};
class stack
{
	node* top;
	
	public:
	stack()	{ top=NULL;}
	~stack() {
		while(top!=NULL) {
			node* tmp=top->next;			
			delete top;
			top=tmp;
		}	
	}
	
	void push(int a);
	int pop();
	int topelem(){return top->data;}
	
	void show();
	bool empty(){if(top==NULL) return true; else return false;}
	int size();		
};
int stack::size()
{
	int i;
	node* p=top;
	for(i=0;p!=0;i++,p=p->next);
	return i;
}
void stack::show()
{
	node* p=top;
	cout<<"\nYour Stack:\n";	
	for(;p!=NULL;p=p->next) cout<<endl<<p->data;	
}
void stack::push(int a)
{
	if(top==NULL){
		top=new node;
		top->data=a;
	}
	else {
		node* p=new node;
		if(!p) cerr<<endl<<"STACK OVERFLOW!!"<<endl;
		else {
			p->data=a;
			p->next=top;
			top=p;
		}
	} 		
}
int stack::pop()
{
	int a;
	if(top==NULL) cerr<<endl<<"STACK UNDERFLOW!!"<<endl;
	else {
		a=top->data;
		node* p=top;
		top=top->next;
		p->next=NULL;
		delete p;		
	}	
	return a;	
}

#endif

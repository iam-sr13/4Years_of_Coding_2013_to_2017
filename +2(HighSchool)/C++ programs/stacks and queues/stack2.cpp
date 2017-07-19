#include<iostream>
#include<iomanip>
#include<algorithm>
#include<conio.h>
#define CLR (system("cls"))
#define MAX 10
#define nullptr 0
using namespace std;
class node
{
	public:
	int data;
	node* next;	
	node(){this->next=nullptr; this->data=0;}	
};
class stack
{
	node* top;
	void push(int a);
	int pop();
	void show();
	public:
	stack()	{ top=nullptr;}
	~stack() {while(top!=nullptr){node* t=top->next; delete top; top=t;}}
	void menu()
	{
		int ch,x;
		do {
			CLR;
			cout<<"\nWelcome to Stack Program....\n\n  MAIN MENU\n\n1. Push\n2. Pop\n3. Exit\n";
			show();
			cout<<"\n\nYour choice: ";
			cin>>ch;
			switch(ch) {
				case 1:cout<<"\n\nPush value: ";cin>>x;push(x);
					break;
				case 2:x=pop();cout<<"\n\nPopped value: "<<x; getch();
					break;
				case 3: break;
				default: cerr<<"\nInvalid Choice!!!\n";getch();
			}
		}while(ch!=3);
	}
};
void stack::show()
{
	node* p=top;
	cout<<"\nYour Stack:\n";	
	for(;p!=nullptr;p=p->next) cout<<endl<<p->data;	
}
void stack::push(int a)
{
	if(top==nullptr){
		top=new node;
		top->data=a;
	}
	else {
		node* p=new node;
		if(!p) cerr<<endl<<endl<<"STACK OVERFLOW!!"<<endl;
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
	if(top==nullptr) cerr<<endl<<endl<<"STACK UNDERFLOW!!"<<endl;
	else {
		a=top->data;
		node* p=top;
		top=top->next;
		p->next=nullptr;
		delete p;
	}
	return a;	
}

main()
{
	stack candy;
	candy.menu();
}

#include<iostream>
#include<algorithm>
#include<conio.h>
#define CLR (system("cls"))
#define nullptr NULL
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
	bool empty(){if(top==nullptr) return true; else return false;}
	int size(){
		int i;
		node* p=top;
		for(i=0;p!=0;i++,p=p->next);
		return i;
	}
	int topelem(){return top->data;}
	public:
	stack()	{ top=nullptr;}
	~stack() {
		while(top!=nullptr) {
			node* tmp=top;
			top=top->next;
			delete tmp;
		}	
	}
	void menu()
	{
		int c,x;
		do{
			CLR;
			cout<<"\nWELCOME to Stack Program!\n\n#Main Menu:\n "; show(); 
			cout<<"\n\n1.Push Element\n2.Pop Element\n3.Top element\n4.Size\n5.IsEmpty\n6.Quit\n\nYour choice: ";
			cin>>c;
			
			switch(c) {
				case 1:{
					cout<<"\nPlease enter any integer value: "; cin>>x;				
					push(x);
					break;
				}
				case 2:{				
					pop();
					getch();
					break;
				}
				case 3:{
					if(empty())cout<<"\nStack is empty";
					else cout<<"\nTop Element: "<<topelem();
					getch();
					break;
				}
				case 4:{
					cout<<"\nStack current size: "<<size(); getch();
					break;
				}
				case 5:{
					if(empty())cout<<"\nStack is empty!";
					else cout<<"\nStack is not empty!";
					getch();
					break;
				}
				case 6:{				
					break;
				}
				default: cout<<"\nWrongChoice!!";getch();				
			}		
		}while(c!=6);
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
	if(top==nullptr) cerr<<endl<<"STACK UNDERFLOW!!"<<endl;
	else {
		a=top->data;
		node* p=top;
		top=top->next;
		p->next=nullptr;
		delete p;
		cout<<"\nPopped Value: "<<a<<endl;
	}	
	return a;	
}

main()
{
	stack candy;
	candy.menu();
}

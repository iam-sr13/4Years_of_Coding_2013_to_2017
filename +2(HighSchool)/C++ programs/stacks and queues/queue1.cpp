#include<iostream>
#include<iomanip>
#include<algorithm>
#include<conio.h>
#define CLR (system("cls"))//use system("clear") for linux
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
class queue
{
	node* front,*rear;
	void push(int a);
	int pop();
	void show();
	int size();
	public:
	queue()	{ front=rear=nullptr;}
	~queue() {delete front,rear;}
	void menu()
	{
		int ch,x;
		do {
			CLR;
			cout<<"\nWelcome to Queue Program....\n\n  MAIN MENU\n\n1. Push\n2. Pop\n3. Exit\n";
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
int queue::size()
{
	int i;
	node* p=front;
	for(i=0;p!=0;i++,p=p->next);
	return i;
}
void queue::show()
{
	node* p=front;
	cout<<"\nYour Queue:\n";
	cout<<"\n\\";for(int q=0;q<size();q++) cout<<"__";cout<<"/\n";	
	for(;p!=nullptr;p=p->next) cout<<" "<<p->data;
	cout<<"\n/";for(int q=0;q<size();q++) cout<<"--";cout<<"\\";	
}
void queue::push(int a)
{
	if(front==nullptr){
		rear=new node;
		rear->data=a;
		front=rear;		
	}
	else {
		rear->next=new node;
		if(!(rear->next)) {
			cerr<<endl<<endl<<"QUEUE OVERFLOW!!"<<endl;			
		}
		else {
			rear=rear->next;
			rear->data=a;
		}
	} 		
}
int queue::pop()
{
	int a;
	if(front==nullptr) {
		cerr<<endl<<endl<<"QUEUE UNDERFLOW!!"<<endl;		
	}
	/*else if(front==rear){
		a=front->data;		
		delete front;
		front=rear=nullptr;
	}*/
	else {
		a=front->data;
		node* t=front;
		front=front->next;
		t->next=nullptr;
		delete t;
	}
	return a;	
}

main()
{
	queue message;
	message.menu();
}

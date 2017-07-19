#include<iostream>
#include<iomanip>
#include<algorithm>
#include<conio.h>
#define CLR (system("cls"))//use system("clear") for linux

using namespace std;
class node
{
	public:
	int data;
	node* next;	
	node(){this->next=NULL; this->data=0;}	
};
class queue
{
	node* front,*rear;
	int length;	
	
	public:
	queue()	{ front=rear=NULL; length=0;}
	~queue() {node* t; while(front!=NULL){t=front->next;delete front;front=t;} front=rear=NULL; length=0;}
	
	void push(int a);
	int pop();
	
	bool empty() { return !length;}
	void show();
	int size(){return length;}
	int frontel() {return front->data;}
	int rearel() {return rear->data;}
};

void queue::show()
{
	node* p=front;
	cout<<"\nYour Queue:\n";
	cout<<"\n\\";for(int q=0;q<size();q++) cout<<"__";cout<<"/\n";	
	for(;p!=NULL;p=p->next) cout<<" "<<p->data;
	cout<<"\n/";for(int q=0;q<size();q++) cout<<"--";cout<<"\\";	
}
void queue::push(int a)
{
	if(front==NULL){
		rear=new node;
		rear->data=a;
		front=rear;
		length++;		
	}
	else {
		rear->next=new node;
		if(!(rear->next)) {
			cerr<<endl<<endl<<"QUEUE OVERFLOW!!"<<endl;			
		}
		else {
			rear=rear->next;
			rear->data=a;
			length++;
		}
	} 		
}
int queue::pop()
{
	int a;
	if(front==NULL) {
		cerr<<endl<<endl<<"QUEUE UNDERFLOW!!"<<endl;		
	}	
	else {
		a=front->data;
		node* t=front;
		front=front->next;
		t->next=NULL;
		delete t;
		length--;
	}
	return a;	
}

main()
{
	queue msg;
	int ch,x;
	do {
		CLR;
		cout<<"\nWelcome to Queue Program....\n\n  MAIN MENU\n ___________\n\n1. Push\n2. Pop\n3. Size\n4. Front Element\n5. Rear Element\n6. Exit\n";
		msg.show();
		cout<<"\n\nYour choice: ";
		cin>>ch;
		switch(ch) {
			case 1:{
				cout<<"\nPush value: ";cin>>x;msg.push(x);
				break;
			}			
			case 2:{
				if(msg.empty()) cout<<"\nQueue Underflow!!";
				else {
					x=msg.pop();
					cout<<"\nPopped value: "<<x;
				}
				getch();				
				break;
			}
			case 3:{
				cout<<"\nSize of Queue is "<<msg.size();
				getch();
				break;
			}
			case 4:{
				if(msg.empty()) cout<<"\nQueue Underflow!!";
				else {
					cout<<"\nFront element of Queue is "<<msg.frontel();
				}				
				getch();
				break;
			}
			case 5:{
				if(msg.empty()) cout<<"\nQueue Underflow!!";
				else {
					cout<<"\nRear element of Queue is "<<msg.rearel();
				}				
				getch();
				break;
			}				
			case 6: break;
			default: cerr<<"\nInvalid Choice!!!\n";getch();
		}
	}while(ch!=6);
	
	return 0;
}

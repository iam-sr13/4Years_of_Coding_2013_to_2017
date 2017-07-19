#include<iostream>
#include<iomanip>
#include<algorithm>
#include<conio.h>
#define CLR (system("cls"))//use system("clear") for linux

using namespace std;

class queue
{	
	int *q,front,rear,length,capacity;	
	void lshift() {
		for(int i=0;i<length-1;i++){
			q[i]=q[i+1];
		}
	}
	
	public:
	queue(int cap=0) { front=rear=0; length=0; capacity=cap; q=new int[cap];}	
	~queue() {delete[] q; q=NULL; length=0;}
	
	void push(int a);
	int pop();
	
	bool empty() { return !length;}
	void show();
	int size(){return length;}
	int frontel() {return q[front];}
	int rearel() {return q[rear-1];}
};

void queue::show()
{	
	cout<<"\nYour Queue:\n";
	cout<<"\n\\";for(int i=0;i<length;i++) cout<<"__";cout<<"/\n";	
	for(int i=0;i<length;i++) cout<<" "<<q[i];
	cout<<"\n/";for(int i=0;i<length;i++) cout<<"--";cout<<"\\";	
}
void queue::push(int a)
{
	if(length==capacity){
		cout<<endl<<"QUEUE OVERFLOW!!"<<endl;
		getch();
	} 
	else {
		q[rear++]=a;		
		length++;
	}		
}
int queue::pop()
{
	int a;
	if(rear==0) {
		cout<<endl<<"QUEUE UNDERFLOW!!"<<endl;		
	}
	else{
		a=q[front];
		lshift();
		rear--;
		length--;				 
	}	
	return a;	
}

main()
{
	int ch,x,n;
	cout<<"\nWelcome to Queue program!\n\nPlease enter MAX Capacity of your queue: "; cin>>n;
	queue msg(n);
	
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

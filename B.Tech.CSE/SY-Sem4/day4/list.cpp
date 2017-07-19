#include<iostream>
#include<cstdlib>
#define CLR (system("clear")) 
using namespace std;

struct node
{
	int data;
	node* next;
	node(int d=0, node* n=0) {data=d; next=n;}
};

class LIST
{
	node* front;
	int size;
	
	public:
		LIST() {front=0; size=0;}
		~LIST() {
			 node* t;
			 while(front!=0) {
				 t=front; 
				 front=front->next; 
				 delete t;
			 }
		}		
		
		void ins(int a)
		{
			if(front==0) {
				front=new node(a);
			}
			else {
				node* t=new node(a,front);
				front=t;
			}
		}
		void del()
		{
			if(front==0) {
				cout<<"\nLIST UNDERFLOW!!!"; cin.ignore().ignore();
			}
			else {				
				node* t=front;
				front=front->next;
				delete t;
			}
		}
		void show()
		{
			for(node* p = front; p!=0; p=p->next) {
				cout<<p->data;
				if(p->next==0) cout<<".";
				else cout<<", ";
			}
		}
};

int main()
{
	LIST mylist;
	int ch,a;
	
	do{
		CLR;
		cout<<"\nWELCOME to LIST program.......\n\n# MAIN MENU\n\nYour List: ";
		mylist.show();
		cout<<"\n\n1. Insert\n2. Delete\n3. Quit\n\nYour Choice: ";
		cin>>ch;
		
		switch(ch) {
			case 1: {
				cout<<"\nEnter any integer: "; cin>>a;
				mylist.ins(a);
				break;
			}
			case 2: {
				mylist.del();
				break;
			}
			case 3: {				
				break;
			}
			default: cout<<"\nINVALID CHOICE!!!"<<endl; cin.ignore().ignore();
		}
	}while(ch!=3);
	
	return 0;
}

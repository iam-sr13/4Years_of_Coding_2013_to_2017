#include<iostream>
#include<algorithm>
#include<conio.h>
#define CLR (system("cls"))
using namespace std;

enum{end=0,beg};

template<class Type>
struct node
{
	Type data;
	node *prev,*next;
	node() {
		prev=next=NULL;
	}
};

template<class Type>
class dllist
{
	protected:
		node<Type> *start,*end;
		int length;
	public:		
		dllist() {
			start=end=NULL;
			length=0;
		}
		~dllist() {
			while(start!=NULL) {
				node<Type>* temp=start->next;				
				delete start;
				start=temp;
			}
			length=0;
		}
		
		void ins_end(int x)
		{
			if(end==NULL) {
				start=new node<Type>;
				end=start;
				start->data=x;
			}else {
				end->next=new node<Type>;
				end->next->prev=end;
				end=end->next;
				end->data=x;				
			}
			length++;
		}		
		void ins_beg(int x)
		{
			if(start==NULL) {
				start=new node<Type>;
				end=start;
				start->data=x;
			}else {
				start->prev=new node<Type>;
				start->prev->next=start;
				start=start->prev;
				start->data=x;				
			}
			length++;
		}
		void insert(int x,int p) //validate input
		{
			if(start==NULL) {
				start=new node<Type>;
				end=start;
				start->data=x;
				length++;
			}			
			else {
				if(p==0) ins_beg(x);
				else if(p==length) ins_end(x);
				else {
					node<Type>* ps=start,*t=start->next;
					for(int i=1;i<p;i++) ps=t,t=t->next;
					ps->next=new node<Type>;					
					ps->next->data=x;
					t->prev=ps->next;
					ps->next->prev=ps;
					ps->next->next=t;
					length++;
				}				
			}			
		}
		
		void del(int x)
		{
			node<Type>* p=start,*t=new node<Type>;
			
			if(start==end){
				delete start;
				start=end=NULL;
			}	
			else if(x==0) {
				start=start->next;
				p->next=0;
				delete p;
				start->prev=NULL;
			}			
			else{
				for(int i=1;i<=x;i++,t=p,p=p->next);
				if(p==end) {
					t->next=NULL;
					p->prev=NULL;
					delete p;
				}
				else{
					t->next=p->next;
					p->next->prev=t;
					p->next=0;
					delete p;
				}						
			}
			length--;
		}
		
		/*void del(int p)
		{
			if(start==NULL) cout<<"\nUnderflow!\n";
			else if(length==1) {delete start; start=end=NULL; length=0;}
			else {
				if(p==0) {
					node<Type>* temp=start;
					start=start->next;
					temp->next=NULL;
					delete temp;
					start->prev=NULL;
				}
				if(p==length-1){
					node<Type>*t=end->prev;
					t->next=NULL;
					delete end;
					end=t;
				}
				else{
					node<Type>* ps=start,*t=start->next;
					for(int i=1;i<p;i++) ps=t,t=t->next;					
					ps->next=t->next;
					t->next->prev=ps;
					
					delete t;
					
					//t->prev=ps->prev;
				    //ps->prev->next=t;
				    //delete ps;
				}
				length--;
			}
		}*/
		
		void disp(int x=beg)
		{
			if(x) {
				node<Type>* p=start;
				while(p!=NULL) cout<<p->data<<" ",p=p->next;
			}else {
				node<Type>* p=end;
				while(p!=NULL) cout<<p->data<<" ",p=p->prev;
			}
		}
		
		void search(int x)
		{
			node<Type>* p=start;
			while(p!=NULL) {
				if(p->data==x){cout<<"\nElement FOUND!!";break;} 
				p=p->next;	
			}
			if(p==NULL) cout<<"\nElement NOT FOUND!!";
		}
		
		void sort()
		{
			node<Type>*p,*q;
			
			for(p=start;p!=NULL;p=p->next) {				
				for(q=start;q!=NULL;q=q->next){
					if((p->data)<(q->data)){
						Type t=p->data;
						p->data=q->data;
						q->data=t;
					}
				}
			}
		}		
		int size(){return length;}
		
		template<class T>		
		friend ostream& operator<<(ostream& out,dllist<T>& l);		
};

template<class Type>
ostream& operator<<(ostream& out,dllist<Type>& l)
{
	l.disp();
	return out;
}

int main()
{
	int c,el,pos;
	dllist<int> mylist;
		
	cout<<"\nWELCOME to DoublyLinkedList Program!\n\nCREATING YOUR LIST....\n\nPlease enter no. of elements: ";
	cin>>c;	
	cout<<"\nNow enter values one by one:\n";
	for(int i=0;i<c;i++) cin>>el,mylist.ins_end(el);
	
	do{
		CLR;
		cout<<"\nWELCOME to DoublyLinkedList Program!\n\n#Main Menu:\n\nYour List: "<<mylist<<"\nCurrent Length: "<<mylist.size()<<"\n\n1.Insert at beginning\n2.Insert at end\n3.Insert Anywhere\n4.Erase Element\n5.Print Reverse\n6.Search\n7.Sort\n8.Quit\n\nYour choice: ";
		cin>>c;
		
		switch(c) {
			case 1:{
				cout<<"\nPlease enter any integer value: "; cin>>el;
				mylist.ins_beg(el);
				break;
			}
			case 2:{
				cout<<"\nPlease enter any integer value: "; cin>>el;
				mylist.ins_end(el);
				break;
			}
			case 3:{
				cout<<"\nPlease enter any integer value: "; cin>>el;
				cout<<"\nPlease enter position: "; cin>>pos;
				if(pos<0 || pos>mylist.size()) {cout<<"\nINVALID POSITION!"; getch();}
				else mylist.insert(el,pos);				
				break;
			}
			case 4:{
				cout<<"\nPlease enter position: "; cin>>pos;
				if(pos<0 || pos>=mylist.size()) {cout<<"\nINVALID POSITION!"; getch();}
				else mylist.del(pos);				
				break;
			}
			case 5:{
				cout<<endl;
				mylist.disp(end);
				getch();
				break;
			}
			case 6:{
				cout<<"\nPlease enter any integer value: "; cin>>el;
				mylist.search(el);
				getch();
				break;
			}
			case 7:{
				mylist.sort();
				break;
			}
			case 8:{				
				break;
			}
			default: cout<<"\nWrongChoice!!";getch();				
		}		
	}while(c!=8);
	
	return 0;
}

#include<iostream>
#include<sstream>
#include<iomanip>
#include<cstring>
#include<conio.h> 
#include<algorithm>
#define sstream stringstream
#define CLR (system("cls"))
using namespace std;

template<class type>
class node
{
	public:
	type data;
	node<type>* next;
	void newlink(){this->next=new node<type>;}
	node(){this->next=0; this->data=0;}
	~node(){			
		delete next;			
	}
};

template<class type>
class llist
{
	node<type>* start;	
	void search();
	void sort();
	void reverse();
	void ins();
	void ins(type p);
	void del();
	public:
		void create();
		void display();
		int size();
		void menu();
		llist(){this->start=new node<type>;}
		llist(int n) {
			int i;
			this->start=new node<type>;
			node<type>* p=start;			
			for(i=1;i<n;i++,p=p->next) p->newlink();			
		}		
		~llist(){delete start;}		
		type &operator[](int n)
		{
			int i;
			node<type>* p=start;
			if(n>=(this->size())) {
				//cout<<"\n\nERROR!!!! Your list index has gone OUT OF RANGE!!!!\n\n";								
				for(i=1;p->next!=0;i++,p=p->next);
				for(;i<=n;i++,p=p->next) p->newlink();
				return p->data;
			}			
			for(i=1;i<=n;i++,p=p->next);
			return p->data;
		}
		void operator ()(int n)
		{
			int i;			
			node<type>* p=start;
			if(n>(this->size())) {
				for(i=1;p->next!=0;i++,p=p->next);
				for(;i<n;i++,p=p->next) p->newlink();
			}
			else {
				for(i=1;i<n;i++,p=p->next);
				delete p->next;
				p->next=0;
			}
		}
};

template<class type>
void llist<type>::sort()
{
	int i,j;
	for(i=1;i<this->size();i++)
		for(j=0;j<(this->size()-i);j++)
			if(this->operator[](j)>this->operator[](j+1)) swap(this->operator[](j),this->operator[](j+1));	
}

template<class type>
void llist<type>::reverse()
{
	node<type>*s2=start,*p=start,*t=new node<type>;	
	for(;s2->next!=0;s2=s2->next);	
	for(;start->next!=0;) {		
		for(;p->next!=0;t=p,p=p->next); 
		p->next=t;
		t->next=0;
		p=start;				
	}
	start=s2;
}

template<class type>
int llist<type>::size()
{
	int i;
	node<type>* p=start;
	for(i=0;p!=0;i++,p=p->next);
	return i;
}

template<class type>
void llist<type>::del()
{
	node<type>* p=start,*t=new node<type>;
	int x,i;	
	cout<<"\nEnter the position of the no. to be deleted: ";
	cin>>x;
	if(x==1) {
		start=start->next;
		p->next=0;
		delete p;
	}
	else{
		for(i=1;i<x;i++,t=p,p=p->next);
		t->next=p->next;
		p->next=0;
		delete p;		
	}
}

template<class type>
void llist<type>::ins()
{
	node<type>* p=start,*t=new node<type>;
	int x;	
	cout<<"\nEnter the no. to be inserted: ";
	cin>>x;
	if(x<p->data) {				
		t->data=x;		
		t->next=p;		
		start=t;		
	}
	else {
		for(;((p!=0)&&(x>p->data));t=p,p=p->next);
		t->newlink();
		t->next->data=x;
		t->next->next=p;
	}
}

template<class type>
void llist<type>::ins(type pos)
{
	node<type>* p=start,*t=new node<type>;
	int x,i;	
	cout<<"\nEnter the no. to be inserted: ";
	cin>>x;
	if(pos==1) {		
		t->data=x;
		t->next=p;
		start=t;
	}
	else{
		for(i=1;i<pos;i++,t=p,p=p->next);
		t->newlink();
		t->next->data=x;
		t->next->next=p;
	}
}

template<class type>
void llist<type>::create()
{	
	node<type>* p=start;
	int i,n;
	cout<<"\nPlease enter the no. of elements: ";
	cin>>n;
	cout<<"\nPlease enter the data one by one:\n\n";	
	for(i=1;i<=n;i++,p=p->next) {cin>>p->data; if(i<n)p->newlink();}	
}

template<class type>
void llist<type>::display()
{
	node<type>* p=start;
	if(start->next==0 && start->data==0) cout<<"\nNo list loaded!\nPlease load your list first!!!!\n";
	else {
		cout<<"\nThis is your list:\n";
		for(;p!=0;p=p->next) {
			cout<<p->data;
			if(p->next!=0) cout<<", ";
			else cout<<".";
		}
	}
}

template<class type>
void llist<type>::menu()
{	
	int c;
	for(;;) {
		cout<<"\n    WELCOME! to 'Linked->List' program!";		
		cout<<"\n\n MAIN MENU \n\n1. Create new list\n2. Open existing list\n3. Save current list\n4. See current list\n5. Search in the list\n6. Edit current list\n7. About\n8. Exit\n\nYour Choice: ";
		cin>>c;
		switch(c) {
			case 1: create();			    
				break;
			case 2: cout<<"Wait for next update!";
				getch();
				break;
			case 3: cout<<"Wait for next update!";
				getch(); 
				break;
			case 4: display();
				getch(); 
				break;
			case 5: cout<<"Wait for next update!";
					if(start->next==0 && start->data==0) cout<<"\nNo list loaded!\nPlease load your list first!!!!\n";
				getch(); 
				break;				
			case 6: 
					for(;;) {
						CLR;
						cout<<"\n\n Edit MENU:- \n\n1. Insert new element\n2. Insert new element(in sorted list)\n3. Delete existing element\n4. Sort the list\n5. Reverse the list\n6. Back\n";
						display();
						cout<<"\n\nYour Choice: ";
						cin>>c;
						switch(c) {
							case 1: int pos;
									if(start->next==0 && start->data==0) cout<<"\nNo list loaded!\nPlease load your list first!!!!\n";								
									else
									cout<<"\nEnter the position of the no. to be inserted: ";
									cin>>pos;
							    	ins(pos);
								break;
							case 2: if(start->next==0 && start->data==0) cout<<"\nNo list loaded!\nPlease load your list first!!!!\n";
									else
									ins();							
								break;
							case 3: if(start->next==0 && start->data==0) cout<<"\nNo list loaded!\nPlease load your list first!!!!\n";
									else
									del(); 
								break;
							case 4:	if(start->next==0 && start->data==0) cout<<"\nNo list loaded!\nPlease load your list first!!!!\n";
									else
									sort();								 						 
								break;
							case 5:	if(start->next==0 && start->data==0) cout<<"\nNo list loaded!\nPlease load your list first!!!!\n";
									else
									reverse(); 
								break;
							case 6:							 
								break;
							default: cout<<"INVALID INPUT!!!\n\n";	
							break;
					    }
					    if(c==6) break;
					}
				break;
			case 7: cout<<"SR rocks!";
				getch();
				break;
			case 8:
				break;
			default: cout<<"INVALID INPUT!!!\n\n";
			break;						
		}
		if(c==8) break;
		CLR;
	}	
}

void swap(int &x,int &y)
	{
		int t;
		t=x;
		x=y;
		y=t;
	}

main()
{	
	llist<int> z;
	int i,j,n;		
	cout<<"\nEnter size of list: ";
	cin>>n;
	for(i=0,j=0,cout<<"\nEnter elements: \n\n";i<n;i++) cin>>z[i];		
	for(i=0,cout<<"\nElements: ";i<z.size();i++) cout<<z[i]<<" ";
	cout<<endl<<endl<<"Size: "<<z.size();		
	cout<<endl<<endl<<"This is sorted=>\n\n";
	for(i=1;i<z.size();i++)
		for(j=0;j<z.size()-i;j++)
			if(z[j]>z[j+1]) swap(z[j],z[j+1]);
	for(i=0,cout<<"\nElements: ";i<z.size();i++) cout<<z[i]<<" ";	
}

/*int i,n,j;		
	cout<<"\nEnter size: ";
	cin>>n;
	for(i=0,cout<<"\nEnter elements: ";i<n;i++) cin>>z[i];
	for(i=0,cout<<"\nElements: ";i<z.size();i++) cout<<z[i]<<" ";
	cout<<endl<<endl<<"Size: "<<z.size();		
	cout<<endl<<endl<<"This is sorted=>\n\n";
	for(i=1;i<z.size();i++)
		for(j=0;j<z.size()-i;j++)
			if(z[j]>z[j+1]) swap(z[j],z[j+1]);
	for(i=0,cout<<"\nElements: ";i<z.size();i++) cout<<z[i]<<" ";*/

/*char q;	
	sstream st;
	for(i=0,cout<<"\nEnter elements: ";;i++){
		cin>>q;		
		if(isdigit(q)) {
			st<<q;
			st>>z[i];
			st<<"\b";						
		} 
		else break;		
	}*/	

/*Note:
z(n) means initialise list of n elements existing;(n>0)
z[n] access (n+1)th location of the list;(n>=0)
*/	

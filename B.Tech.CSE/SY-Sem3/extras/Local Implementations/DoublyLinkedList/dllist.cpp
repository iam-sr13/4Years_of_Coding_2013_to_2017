#include<iostream>
using namespace std;

enum{beg=1,end=0};

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
	public:
		dllist() {
			start=end=NULL;
		}
		~dllist() {
			while(start!=NULL) {
				node<Type>* temp=start->next;				
				delete start;
				start=temp;
			}
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
		}
		void insert(int x,int p) //validate input
		{
			if(start==NULL) {
				start=new node<Type>;
				end=start;
				start->data=x;
			}
			else {
				node<Type>* ps=start,*t=start->next;
				for(int i=1;i<p;i++) ps=t,t=t->next;
				ps->next=new node<Type>;
				ps->data=x;
				t->prev=ps->next;
				ps->next->prev=ps;
				ps->next->next=t;
			}
		}
		
		void del(int p)
		{
			if(start==NULL) cout<<"\nUnderflow!\n";
			else {
				if(p==1) {
					node<Type>* temp=start;
					start=start->next;
					delete temp;
					start->prev=NULL;
				}
				else{
					node<Type>* ps=start,*t=start->next;
					for(int i=1;i<p;i++) ps=t,t=t->next;
					t->prev=ps->prev;
					ps->prev->next=t;
					delete ps;
				}
			}
		}
		
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
};

int main()
{
	
	return 0;
}

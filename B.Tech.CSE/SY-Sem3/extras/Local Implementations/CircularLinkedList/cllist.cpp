#include<iostream>

using namespace std;

template<class Type>
struct node
{
	Type data;
	node<Type> *next;
	node() {
		next=NULL;
	}
};

template<class Type>
class cllist
{
	protected:
		node<Type>* head;
		
	public:
		cllist() {
			head=new node<Type>;			
		}
		~cllist() {
			node<Type> *p,*t=head->next;
			while(t!=head) {
				p=t;
				t=t->next;
				delete p;
			}			
		}
		
		//basic ADT functions
		
		int size()
		{
			int i;
			node<Type>* p=head->next;
			for(i=0;p!=head;i++,p=p->next);
			return i;
		}
		void ins_end(char x);
		void disp();		 
};

template<class Type>
void cllist<Type>::ins_end(char x)
{	
	node<Type> *p=new node<Type>,*t=head->next;
	if(p==NULL) cout<<"\nMemoryFull!\n";
	else{
		p->data=x;
		if(head->next==NULL) {		//if list is empty
			head->next=p;		
			p->next=head;				
		}
		else {					
			while(t->next!=head) { //trav till last node;
				t=t->next;
			}				
			p->next=head;
			t->next=p;		
		}
	}	
}
template<class Type>
void cllist<Type>::disp()
{
	node<Type> *t=head->next;
	for(;t!=head;t=t->next){		
		cout<<t->data<<" ";								
	}

}

int main()
{
	cllist<char> str;
	string s;
	cout<<"\nWelcome to Pallindrome test\n\nEnter your word: ";
	cin>>s;
	for(int i=0;i<s.size();i++) {
		str.ins_end(s[i]);
	}
	cout<<"\nYour String: "; str.disp();
	cout<<"\nYour Size: "<<str.size();	
	
	return 0;
}


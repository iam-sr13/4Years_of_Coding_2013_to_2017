#include<iostream>
#include<climits>

using namespace std;

struct node
{
	char data;
	node*next,*prev;
	node() {
		prev=next=NULL;
	}
};

class cllist
{
	protected:
		node* head;
		
	public:
		cllist() {
			head=new node;			
			head->data=CHAR_MAX;
		}
		~cllist() {
			node *p,*t=head->next;
			while(t!=head) {
				p=t;
				t=t->next;
				delete p;
			}			
		}
		
		//basic ADT functions
		
		void ins_end(char x);
		void disp();
		bool is_pali(); 
};

bool cllist::is_pali()
{
	node* p=head,*t=head;
	bool chk=true;
	
	while(p->next!=head)
	{
		p=p->next;
		t=t->prev;
		if(p->data!=t->data) {
			chk=false;
			break;
		}		
	}
	
	return chk;
}

void cllist::ins_end(char x)
{	
	node*p=new node,*t;
	if(head->next==NULL) {
		p->data=x;
		head->next=p;		
		p->next=head;
		
		head->prev=p;
		p->prev=head;		
	}
	else {
		t=head->prev;
		p->data=x;		
				
		p->next=head;
		t->next=p;
		
		head->prev=p;
		p->prev=t;
	}
}
void cllist::disp()
{
	node*t=head;
	while(t->next!=head){
		t=t->next;
		cout<<t->data<<" ";					
	}
}

int main()
{
	cllist str;
	string s;
	cout<<"\nWelcome to Pallindrome test\n\nEnter your word: ";
	cin>>s;
	for(int i=0;i<s.size();i++) {
		str.ins_end(s[i]);
	}
	
	if(str.is_pali()) cout<<"\nYour string is pallindrome!";
	else cout<<"\nYour string is NOT pallindrome!";
	
	return 0;
}


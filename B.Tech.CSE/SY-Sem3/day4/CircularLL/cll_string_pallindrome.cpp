/*******************************************************************************
 * Date: 8/09/16
 * Name: Shriraj P.S.
 * Roll no: 15cse1036
 * Description: w.a.p to check if a string is pallindrome using circular list.
 ******************************************************************************/

#include<iostream>

using namespace std;

struct node
{
	char data;
	node *next;
	node() {
		next=NULL;
	}
};

class cllist
{
	protected:
		node* head;
		
	public:
		//Constructor and Destructor
		cllist() {
			head=new node;			//a header node. 			
			head->next=head;
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
		int size();
		void ins_end(char x);
		void disp();
		bool is_pali(); 		
};

//Overloaded I/O ops
ostream& operator<<(ostream& out,cllist& obj)
{
	obj.disp();
	return out;
}
istream& operator>>(istream& in,cllist& obj)
{
	string s;
	in>>s;
	for(int i=0;i<s.size();i++) {   
		obj.ins_end(s[i]);     
	}
	return in;
}

//Class methods
bool cllist::is_pali()
{
	node* p=head->next,*t;
	bool chk=true;	
	
	for(int k=0;p!=head;p=p->next,k++)
	{				
		t=head;
		for(int j=k;j<size();j++){
			t=t->next;								
		}			
		
		if(p->data!=t->data) {
			chk=false;
			break;
		}		
	}
		
	return chk;
}
int cllist::size()
{
	int i;
	node* p=head->next;
	for(i=0;p!=head;i++,p=p->next);
	return i;
}
void cllist::ins_end(char x)
{	
	node*p=head->next;
	head->data=x;
	head->next=new node;
	head=head->next;
	head->next=p;	
}
void cllist::disp()
{		
	for(node*t=head->next;t!=head;t=t->next) cout<<t->data<<" ";
}

int main()
{
	cllist str;                                     // a circular list	
	
	cout<<"\nWelcome to Pallindrome test\n\nEnter your word: ";
	cin>>str;                                       //using overloaded input operator function, see above	
	
	if(str.is_pali()) cout<<"\nYour string is pallindrome!";
	else cout<<"\nYour string is NOT pallindrome!";
	
	return 0;
}


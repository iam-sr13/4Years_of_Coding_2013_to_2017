#include<iostream>
using namespace std;

class element
{
	public:
	int data;
	struct element *next;
};

int main()
{
	element a={1,NULL},b={2,NULL},c={3,NULL},*p;
	p=&a;
	a.next=&b;
	b.next=&c;
	for(;p!=NULL;p=p->next) cout<<p->data<<" ";	
	return 0;
}

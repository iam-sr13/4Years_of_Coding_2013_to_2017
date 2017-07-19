#include<iostream>

using namespace std;

struct node
{
	int data;
	node* next;
};

node* create(int x)
{
	node* p=new node;
	if(p!=NULL)
	{
		p->data=x;
		p->next=NULL;
	}
	return p;
} 

int main()
{
	int *p=new int,*t=p;
	delete t;
	delete p;
	
	node* z;
	z=create(10);
	cout<<z->data<<endl;
	cout<<z->data;
	return 0;
}

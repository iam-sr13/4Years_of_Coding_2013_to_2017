#include<iostream>
#include<iomanip>
#include<algorithm>
#include<conio.h>
#define CLR (system("cls"))

using namespace std;

struct node23
{
	int fdata,sdata;
	node23* p;
	node23* l,*m,*r;
	bool twoNode;
	
	node23(int ld=0,int md=0) {
		fdata=ld; sdata=md; 
		p=l=m=r=NULL;
		twoNode=false;		
	}
};

class tree23
{
	node23* root;
	node23* size;
	
	public:
		tree23() {root=NULL; size=0;}
		void insert(int);
		void insert(node23*,int);
		bool search(int,node23*);
		void show(node23*);
		void traverse(node23* current)
		{
			 if (current == NULL) return;		     
			
			   if(current->twoNode) {
			   		traverse(current->l);			
			        show(current);
			        traverse(current->m);			
			        show(current);
			        traverse(current->r);			            
			   }
			   else{			        
			        traverse(current->l);			
			        show(current);			
			        traverse(current->m);
			   }		   
		}
		node23* split(node23* t,int x)
		{
			node23* f=new node23,*s=new node23;
			if(x<t->fdata){
				f->fdata=x;
				s->fdata=t->sdata;
				
				t->twoNode=false;
				t->l=f;
				t->m=s;
				
				f->p=s->p=t;
			}
			else if(x<t->sdata) {
				f->fdata=t->fdata;
				s->fdata=t->sdata;
				
				t->twoNode=false; t->fdata=x;
				t->l=f;
				t->m=s;
				
				f->p=s->p=t;
			}
			else {
				f->fdata=t->fdata;
				s->fdata=x;
				
				t->twoNode=false; t->fdata=t->sdata;
				t->l=f;
				t->m=s;
				
				f->p=s->p=t;
			}
			return t;
		}		
};

bool tree23::search(int n, node23* &p) 
{
	node23* q;				
	if(root==NULL) return false;
				
	q=root;
	while(q!=NULL)
	{		
		if(q->twoNode) {
			if(q->fdata==n || q->sdata==n)
			{					
				p=q;
				return true;
			}
			if (n < q->fdata){
				p=q;
				q=q->l;
			}  
			else if(n < q->sdata){
				p=q;
				q=q->m;
			}
			else {
				p=q;
				q=q->m;
			}
		}
		else {
			if(q->fdata==n)
			{					
				x=q;
				return true;
			}
			if (n < q->fdata){
				p=q;
				q=q->l;
			}  
			else {
				p=q;
				q=q->m;
			}	
		}		
	}			
	return false;
}



void tree23::insert(int n)
{
	node23* t=root;
	
	if (root == NULL)  root=new node23(n);
	else if (root->l == NULL && !root->twoNode) {
		if(root->fdata>n) {
			root->sdata=root->fdata;
			root->fdata=n;
		}
		else root->sdata=n;
		root->twoNode=true;
	} 
	bool found = search(n,t);
	
	if(found) {
		cout<<endl<<"Such node already exist!!\n"; getch();     //code for only uniq elements i.e an ordered set, as defined
	}
	else {
		
		if(t->twoNode) {			
			if (n < t->fdata){
				
			}  
			else if(n < t->sdata){
				
			}
			else {
				
			}
		}
		else {			
			if (n < t->fdata){
			
			}  
			else {
				
			}	
		}		
	}
	
		
	
	size++;		
}                                    

void tree23::show(node23* node)
{
	if(node->twoNode) {
		cout<<node->fdata<<" "<<node->sdata<<" ";
	}
	else {
		cout<<node->fdata<<" ";
	}
}

int main()
{
	
	return 0;
}

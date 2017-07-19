#include<iostream>

using namespace std;

struct node
{
	float c;
	int e;
	node* next;
	node(float ci=0, int ei=0){c=ci; e=ei; next=NULL;}	
};

class polynomial
{
	node* start,*end;
	
	public:
		polynomial() {start=end=NULL;}
		
		node* term(){return start;}
		void insTerm(float ci, int ei);		
		void getPoly(int);
		void show();
		void add(polynomial p1,polynomial p2);
		void subtract(polynomial p1,polynomial p2);
		void multip(polynomial p1,polynomial p2);		
};

void polynomial::multip(polynomial p1,polynomial p2)
{
	for(node* p=p1.term(); p!=NULL; p=p->next) {		
		for(node* q=p2.term(); q!=NULL; q=q->next) {
			insTerm(p->c*q->c,p->e+q->e);						
		}		
	}
}
void polynomial::subtract(polynomial p1,polynomial p2)
{
	for(node* p=p1.term(),* q=p2.term(); p!=NULL; p=p->next,q=q->next) {						
			insTerm((p->c) - (q->c),p->e);
	}
}
void polynomial::add(polynomial p1,polynomial p2)
{
	for(node* p=p1.term(),* q=p2.term(); p!=NULL; p=p->next,q=q->next) {						
			insTerm(p->c + q->c,p->e);
	}	
}
void polynomial::show()
{	
	for(node* p=start; p!=NULL; p=p->next) {
		if(p->c!=0) {
			if(p->e==0) cout<<p->c;
			else cout<<p->c<<"X^"<<p->e;
			
			if(p->next!=NULL) cout<<" + ";
		}		
	}	
}
void polynomial::getPoly(int n)
{
	int ei;
	float ci;	
	cout<<"\nNow enter all terms in ascending order of power:\n";
	for(int i=0;i<n;i++) {
		cout<<"\nTerm X^"<<i<<":\nCoefficient= ";cin>>ci;				
		ei=i;
		insTerm(ci,ei);
	}
	cout<<endl;
}
void polynomial::insTerm(float ci, int ei)
{
	if(start==NULL)
	{
		start=new node(ci,ei);
		end=start;
	}
	else{
		node*p;
		for(node* p=start; p!=NULL; p=p->next) {
			if(p->e==ei) {
				p->c=p->c+ci;
				return;				
			}
		}
		end->next=new node(ci,ei);
		end=end->next;
	}
}

int main()
{
	int n;
	polynomial p1,p2,p3,p4,p5;
	cout<<"\nWelcome to Polynomial Program!!\n";cout<<"\nPlease enter no. of terms: ";cin>>n;
	cout<<"\nFor polynomial 1:\n";		
	p1.getPoly(n);
	cout<<"\nFor polynomial 2:\n";
	p2.getPoly(n);
	
	cout<<"\nYour Polynomials:\nPoly 1: "; p1.show();
	cout<<"\nPoly 2: ";p2.show();
	
	cout<<"\nP1 + P2 = ";
	p3.add(p1,p2);
	p3.show();
	
	cout<<"\nP1 - P2 = ";
	p4.subtract(p1,p2);
	p4.show();
	
	cout<<"\nP1 * P2 = ";
	p5.multip(p1,p2);
	p5.show();
	
	return 0;	
}

/*add fn trials..

int flag=0;
	for(node* p=p1.term(); p!=NULL; p=p->next) {
		flag=0;
		for(node* q=p2.term(); q!=NULL; q=q->next) {
			if(p->e==q->e){
				insTerm(p->c+q->c,p->e); flag=1;
			}			
		}
		if(!flag) {
			insTerm(p->c,p->e);
		} 
	}
	for(node* q=p2.term(); q!=NULL; q=q->next) {		
		for(node* p=p1.term(); p!=NULL; p=p->next) {
			if(q->e!=p->e){
				insTerm(q->c,q->e); 
			}			
		}	
	}*/

#include<iostream>
#include<conio.h>
#include<process.h>
#define CLR (system("cls"))//use system("clear") for linux

using namespace std;

struct node
{
   int coe,exp;        
   struct node *next;
   node(int c=0, int e=0) {next=NULL; coe=c; exp=e;}  
};


class polynomial
{
   struct node *start,*ptrn,*ptrp;
   
   public:
   	 polynomial(){ptrn=ptrp=start=NULL;}
     void get_poly(); 
     void show();     
     void add(polynomial p1,polynomial p2); 
     void subtract(polynomial p1,polynomial p2); 

};

void polynomial::get_poly()      
{
   char c='y';
   
   if(start==NULL)  start=new node; 
     
   for(ptrn=start;c=='y' || c=='Y';ptrn=ptrn->next)
   {     
      cout<<"\nEnter the coefficient: ";
      cin>>ptrn->coe;      
      cout<<"\nEnter the exponent: ";
      cin>>ptrn->exp;      
      cout<<"\nEnter y to add more nodes: ";
      cin>>c;
      if(c=='y'||c=='Y') {
      	ptrn->next=new node;
      }
   }   
}


void polynomial::show()  
{
    struct node *ptr;
    ptr=start;
    while(ptr!=NULL)
    {
       cout<<ptr->coe<<"X^"<<ptr->exp<<" + ";
       ptr=ptr->next;
    }
    cout<<" ";
}

void polynomial::add(polynomial p1,polynomial p2)  
{
   struct node *p1ptr,*p2ptr;
   int coe,exp;
   ptrn=ptrp=start=NULL;
   p1ptr=p1.start;
   p2ptr=p2.start;
   while(p1ptr!=NULL && p2ptr!=NULL)
   {
      if(p1ptr->exp==p2ptr->exp) 
      {
		 coe=p1ptr->coe+p2ptr->coe;
		 exp=p1ptr->exp;
		 p1ptr=p1ptr->next;
		 p2ptr=p2ptr->next;
      }
      else if(p1ptr->exp>p2ptr->exp)
      {
		 coe=p1ptr->coe;
		 exp=p1ptr->exp;
		 p1ptr=p1ptr->next;
      }
      else if(p1ptr->exp<p2ptr->exp)
      {
		 coe=p2ptr->coe;
		 exp=p2ptr->exp;
		 p2ptr=p2ptr->next;
      }
      ptrn=new node;
      if(start==NULL)
	  start=ptrn;
      ptrn->coe=coe;
      ptrn->exp=exp;
      ptrn->next=NULL;
      ptrp->next=ptrn;
      ptrp=ptrn;
   } 
   if(p1ptr==NULL)
   {
      while(p2ptr!=NULL)
      {
		 coe=p2ptr->coe;
		 exp=p2ptr->exp;
		 p2ptr=p2ptr->next;
		 ptrn=new node;
		 if(start==NULL)
		    start=ptrn;
		 ptrn->coe=coe;
		 ptrn->exp=exp;
		 ptrn->next=NULL;
		 ptrp->next=ptrn;
		 ptrp=ptrn;
      }
   }
   else if(p2ptr==NULL)
   {
      while(p1ptr!=NULL)
      {
		 coe=p1ptr->coe;
		 exp=p1ptr->exp;
		 p1ptr=p1ptr->next;
		 ptrn=new node;
		 if(start==NULL)
		    start=ptrn;
		 ptrn->coe=coe;
		 ptrn->exp=exp;
		 ptrn->next=NULL;
		 ptrp->next=ptrn;
		 ptrp=ptrn;
      }
   }
}  


void polynomial::subtract(polynomial p1,polynomial p2)  
{
   struct node *p1ptr,*p2ptr;
   int coe,exp;
   ptrn=ptrp=start=NULL;
   p1ptr=p1.start;
   p2ptr=p2.start;
   while(p1ptr!=NULL && p2ptr!=NULL)
   {
      if(p1ptr->exp==p2ptr->exp) 
      {
		 coe=p1ptr->coe-p2ptr->coe;
		 exp=p1ptr->exp;
		 p1ptr=p1ptr->next;
		 p2ptr=p2ptr->next;
      }
      else if(p1ptr->exp>p2ptr->exp)
      {
		 coe=p1ptr->coe;
		 exp=p1ptr->exp;
		 p1ptr=p1ptr->next;
      }
      else if(p1ptr->exp<p2ptr->exp)
      {
		 coe=0-p2ptr->coe;
		 exp=p2ptr->exp;
		 p2ptr=p2ptr->next;
      }
      ptrn=new node;
      if(start==NULL)
	  start=ptrn;
      ptrn->coe=coe;
      ptrn->exp=exp;
      ptrn->next=NULL;
      ptrp->next=ptrn;
      ptrp=ptrn;
   } 
   if(p1ptr==NULL)
   {
      while(p2ptr!=NULL)
      {
		 coe=0-p2ptr->coe;
		 exp=p2ptr->exp;
		 p2ptr=p2ptr->next;
		 ptrn=new node;
		 if(start==NULL)
		    start=ptrn;
		 ptrn->coe=coe;
		 ptrn->exp=exp;
		 ptrn->next=NULL;
		 ptrp->next=ptrn;
		 ptrp=ptrn;
      }
   }
   else if(p2ptr==NULL)
   {
      while(p1ptr!=NULL)
      {
		 coe=p1ptr->coe;
		 exp=p1ptr->exp;
		 p1ptr=p1ptr->next;
		 ptrn=new node;
		 if(start==NULL)
		    start=ptrn;
		 ptrn->coe=coe;
		 ptrn->exp=exp;
		 ptrn->next=NULL;
		 ptrp->next=ptrn;
		 ptrp=ptrn;
      }
   }
}  


int main()
{
   CLR;
   polynomial p1,p2,sum,diff;
   cout<<"First Polynomial.";
   p1.get_poly();
   cout<<"Second polynomial.";
   p2.get_poly();
   CLR;
   cout<<"The First polynomial is: ";
   p1.show();
   cout<<"The second polynomial is: ";
   p2.show();
   cout<<"The sum of two polynomials is: ";
   sum.add(p1,p2);
   sum.show();
   cout<<"The difference of two polynomials is: ";
   diff.subtract(p1,p2);
   diff.show();
   getch();
   return 0;
}


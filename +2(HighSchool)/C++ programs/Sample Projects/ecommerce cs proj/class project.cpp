#include<stdio.h>
#include<iostream>
#include<malloc.h>
#include<string.h>
#include<iomanip>
#include<ctype.h>
#include<fstream>

int c=0,bu=1,v=1;
using namespace std;
//using namespace std;
struct element 
{
	int code;
	char na[50];
	char th[80];
	int rs;
	struct element *next;
};
typedef struct element node;
class list
{
	
	protected:
	
	node*startbk1,*startbk2,*kartt,*kart1;
	void bkpro();
	void buy();
		void sort(int);
		void sortpro(int);
	void creationbk1();
	void display(int );
	void process(int,int);
	void kart(int,int);
	void creatkart();
	
void initise()
	{
		startbk1=NULL;
		
	}
	
};
void list::creatkart()
{
	kartt=(node*)malloc(sizeof(node));
			kartt->code=12;
	kart1=(node*)malloc(sizeof(node));		
	kart1=kartt;
}

void list::creationbk1()
{
	int u=1,rt;
	char l[80];
	if(c==0)creatkart();
	ifstream a("books1.txt",ios::in);
	node *ptr=NULL,*tep=NULL;
	startbk1=(node*)malloc(sizeof(node));
	startbk1->code=1;
	
	while(u<=3)
    {
		a.getline(l,80);
if(u==1)strcpy(startbk1->na,l);
  if(u==2){strcpy(startbk1->th,l);a>>rt;}
  else
 if(u==3)startbk1->rs=rt;
 u++;
}
 
startbk1->next=NULL;
ptr=startbk1;
u=1;
while(a.getline(l,80))
{
	
	if(u==1){tep=(node*)malloc(sizeof(node));
	strcpy(tep->na,l);
         }
  if(u==2){strcpy(tep->th,l);
	  a>>rt;}
    
  else 
 if(u==3){tep->rs=rt;}
 u++;
 	if(u==4)
 	{	
	tep->next=NULL;
	ptr->next=tep;
	ptr=tep;
	u=1;
    }
}

}

void list::display(int o)
{
	
	int k=1,t=0;node *ptr=NULL;
	if(o==startbk1->code)
ptr=startbk1;
  if(o==kartt->code) ptr=kartt;
	while(ptr!=NULL)
	{
		if(o==kartt->code){ t=t+ptr->rs;cout<<k++<<":";cout<<ptr->na<<"                "<<ptr->rs<<endl<<endl;
			                    
							}
		else{
		cout<<k++<<":";					
		cout<<ptr->na<<endl<<endl;
		    }
		ptr=ptr->next;
	}
	if(o!=kartt->code)
	{cout<<k<<"to sort by price"<<endl;
	k++;
	cout<<k<<"back";
}
	else cout<<"\n"<<endl<<"total:"<<t;
	
}
class pro
{
	
 protected: char a[80],b[80];
 char d[80],e[80];
	void mkacc();
            
  void login();
	  
};
class project:public pro, public list
{
	
	
	void start();
	void categories();	
	
	public:
	project()
	{
		initise();
		start();
		
	if(v!=0)categories();
	}
};

int main()
{
	cout<<"well to mykart"<<endl;
	project x;
	
	return 0;
}

void project::start()
{
	  int a,c;
	  char b;
	do
	{ 
	 cout<<"1:enter to start shopping"<<endl<<"2:exit"<<endl;
	  cout<<"enter chioce:";
	  cin>>a;
	  if(a==1)
	  {
		  cout<<"1:if you have an account"<<"2:if you are new to mykart"<<endl;
		  cout<<"enter:";
		  cin>>c;
		  cin.ignore();
		  if(c==1)
		  { 
			login();
			break;
		   }
			if(c==2){mkacc();
				      login();
				      break;
				    }
			
		}
	 
	  if(a==2)
	  {
		  cout<<"confirm that you really want to exit";
		  cout<<"\n"<<"\t"<<"\t"<<"y:confirm"<<"\t"<<"\t"<<"n:cancel"<<endl;
		  cout<<"enter:";
		  cin>>b;
		  if(b=='y')
		  {
			cout<<"\t"<<"\t"<<"\t"<<"EXIT"<<endl;  
		    a=2;
		    v=0;
		  }
		  if(b=='n') a=1;
	  }  
	  
		} while(a!=2);
		
		
}

void pro::login()
{
	ifstream u;
	
	int k=1,t=3,h,c;
	char l[80];
	u.open("login.txt",ios::in);
	while(t!=0)
	{
		cout<<"1";
		h=1;
		
	if(k>1)cout<<"enter have entered wrong emal address"<<endl;
	if(k>4){cout<<"your might have forgotten your email"<<endl<<"1:make new one"<<endl<<"2:exit";
		   cin>>c;cin.ignore();
		           if(c==1){mkacc();login();}
		          else if(c==2){t=0;v=0;}
		          break;
	        }
	cout<<"enter your valid email id or user name";
	cout<<"\n"<<"example:abc@gmail.com."<<endl;
	cout<<"enter:";
	
	cin.getline(a,80);
	while(u.getline(l,80)&&h!=0)
	{
		
	if(!strcmp(a,l))
	{
		cout<<endl<<"enter your password to login+";
	cout<<"enter:";
	cin.getline(b,80);
	if(h!=0)
	{ u.getline(l,80);
		h=0;
	if(!strcmp(b,l))t=0;
	else
    {
		k++;u.close();
		  u.open("login.txt",ios::in);
		/*u.seekg(ios::beg);*/
		
    }
    }
     }
      
     
	  }
	  if(t==3){k++;u.close();
		  u.open("login.txt",ios::in);
		       /*u.seekg(ios::beg);*/
		       }
   }
u.close();
}
void pro::mkacc()
{
	fstream a;
	a.open("login.txt",ios::out|ios::app);
	cout<<"enter your valid email address:";
	
cin.getline(d,30);
a<<d<<endl;
cout<<"enter your password to make account:";
cin.getline(e,30);
a<<e<<endl;
cout<<"your have successfully made your mykart account";
a.close();
}

	


void project::categories()
{
	
	int a;
	do
	{
	cout<<"choice one of the category you to shop your item";
	cout<<"1:books"<<endl<<"2:watches"<<endl<<"3:mobiles"<<endl<<"4:clothes"<<endl<<"5:footwear"<<endl<<"6:back"<<endl<<"etc.."<<endl;
	cout<<"enter:";
	cin>>a;
	switch(a)
	{
		case 1:
		
		bkpro();
		break;
		case 6:break;
		default:
		
			char k;
		cout<<"you have entered the wrong option"<<"press y to  see categories";
		cin>>k;
		if(k=='y') categories();	     
}
}while(a!=6&&bu!=0);

}
void list::sort(int t)
{
	node *ptr=NULL,*tep=NULL,*deo=NULL,*l=NULL;
	ptr=(node*)malloc(sizeof(node));
	tep=(node*)malloc(sizeof(node));
	deo=(node*)malloc(sizeof(node));
	l=(node*)malloc(sizeof(node));
	int r;
	char s[60],to[80];
	if(t==startbk1->code)
	ptr=startbk1;
	while(ptr->next!=NULL)
	{
		deo=ptr->next;
		l=deo;
		while(deo->next!=NULL)
		{
			tep=deo->next;
			if(l->rs<tep->rs) l=tep;
			deo=deo->next;
		}
		if(ptr->rs<l->rs)
		{
			strcpy(s,ptr->na);
			strcpy(to,ptr->th);
			r=ptr->rs;
			strcpy(ptr->na,l->na);
			strcpy(ptr->th,l->th);
			ptr->rs=l->rs;
			l->rs=r;
			strcpy(l->na,s);
			strcpy(l->th,to);
		}
		ptr=ptr->next;
	}
}

void list::process(int a,int t)
{

	int b;
	
	
		cout<<"1:Add this product to kart"<<endl<<"2:back"<<endl<<"enter choice:";
		cin>>b;
		
		
			switch(b)
	    {
		  case 1:kart(a,t);
		  break;
		  case 2:break;
		}
	
		if(b!=1&&b!=2)
		{
		cout<<endl<<"please enter a valid option:";cin>>b;
	    }
}

	void list::kart(int r,int s)
	{
		
		node *ptr=NULL,*deo=NULL;
		deo=(node*)malloc(sizeof(node));
		int f,t;
	    
		if(r==startbk1->code)ptr=startbk1;
		
		 if(s==1){
			     if(c==0){ c++;strcpy(kart1->na,ptr->na);strcpy(kart1->th,ptr->th);kart1->rs=ptr->rs;kart1->next=NULL;display(kartt->code);}
			     else{
			    deo->next=NULL;
			 strcpy(deo->na,ptr->na);strcpy(deo->th,ptr->th);deo->rs=ptr->rs;
			 kart1->next=deo; kart1=kart1->next;kart1->next=NULL;
			  display(kartt->code);
			 
		            }
				}	
		if(s==2)
		       {
				   ptr=ptr->next;
				    if(c==0){ c++;strcpy(kart1->na,ptr->na);strcpy(kart1->th,ptr->th);kart1->rs=ptr->rs;kart1->next=NULL;display(kartt->code);}
			     else{
			    deo->next=NULL;
			 strcpy(deo->na,ptr->na);strcpy(deo->th,ptr->th);deo->rs=ptr->rs;
			 kart1->next=deo; kart1=kart1->next;kart1->next=NULL;
			  display(kartt->code);
			 
		             } 
				   		
				}
		if(s==3)
		{
			for(t=1;t<=2;t++) ptr=ptr->next;
					 if(c==0){ c++;strcpy(kart1->na,ptr->na);strcpy(kart1->th,ptr->th);kart1->rs=ptr->rs;kart1->next=NULL;display(kartt->code);}
			     else{
			    deo->next=NULL;
			 strcpy(deo->na,ptr->na);strcpy(deo->th,ptr->th);deo->rs=ptr->rs;
			 kart1->next=deo; kart1=kart1->next;kart1->next=NULL;
			  display(kartt->code);
			         }
		 } 
		 if(s==4)
		 {
			 			for(t=1;t<=3;t++) ptr=ptr->next;
					 if(c==0){ c++;strcpy(kart1->na,ptr->na);strcpy(kart1->th,ptr->th);kart1->rs=ptr->rs;kart1->next=NULL;display(kartt->code);}
			     else{
			    deo->next=NULL;
			 strcpy(deo->na,ptr->na);strcpy(deo->th,ptr->th);deo->rs=ptr->rs;
			 kart1->next=deo; kart1=kart1->next;kart1->next=NULL;
			  display(kartt->code);
			         }
		  }	 
		  if(s==5)
		  {
			  			for(t=1;t<=4;t++) ptr=ptr->next;
					 if(c==0){ c++;strcpy(kart1->na,ptr->na);strcpy(kart1->th,ptr->th);kart1->rs=ptr->rs;kart1->next=NULL;display(kartt->code);}
			     else{
			    deo->next=NULL;
			 strcpy(deo->na,ptr->na);strcpy(deo->th,ptr->th);deo->rs=ptr->rs;
			 kart1->next=deo; kart1=kart1->next;kart1->next=NULL;
			  display(kartt->code);
			         }
		   }
		                            
		            
				cout<<endl<<"YOUR ITEM IS SUCESSFULLY ADDED TO KART"<<endl;
					 cout<<"1:proceed to pay"<<endl<<"2:back"<<endl;cin>>f;
					 if(f==1){ buy(); bu=0;}
			
					
				
}  
void list::buy()
{
	char add[100],n[30],to[20],st[15];
	cin.ignore();
	int ph,pin;
	cout<<"enter your full name:";cin.getline(n,30);
	cout<<"enter your pincode:";cin>>pin;
	cin.ignore();
	cout<<"enter your residential address:";cin.getline(add,100);
	cout<<"enter your city/town:";cin>>to;
	cin.ignore();
	cout<<"enter your state:";cin.getline(st,15);
	cout<<"enter your phone number:";cin>>ph;
	cout<<"the details provided by you are as follows:"<<endl<<endl;
	cout<<n<<endl<<add<<endl<<pin<<endl<<to<<endl<<st<<endl<<ph<<endl;
	cout<<"\nYOUR ORDER IS SUCCESSFULLY REGISTERED"<<endl<<endl;
	display(kartt->code);
	cout<<"YOUR ITEMS WILL BE DELIVERED TO YOUR LOCATION IN 2-3 WORKING DAYS"<<endl<<"'THANKS FOR SHOPPING'";
}
	

	
		
		int r;
	
void list::bkpro()
{

	int e;
	
	do
		{
			
	cout<<"1:school and collage referance books:"<<endl<<"2:other books"<<endl<<"3:back";
	cout<<endl<<"enter";
	cin>>e;
	switch(e)
	{
		case 1:
		do
		{
		
		
		creationbk1();
	
		do
		{
		display(startbk1->code);
		if(r!=6)sortpro(startbk1->code);
		
		
		if(r==6)
		{
		sort(startbk1->code);
		display(startbk1->code);
		sortpro(startbk1->code);

	    }
	}while(r!=7&&bu!=0);
	}while(r!=7&&r!=6&&bu!=0);
		
}
}while(e!=3&&bu!=0);

}	

void list::sortpro(int t)
{
	int u,k;
	node *ptr=NULL;
	
	if(t==startbk1->code) ptr=startbk1;
	
	cout<<"\n enter choice:";cin>>u;
	if(u==1){
		      cout<<"some information about the product"<<endl<<ptr->th<<endl<<"the price of this book="<<ptr->rs<<endl;
		      process(startbk1->code,u);
		    }
		    if(u==2){
				      ptr=ptr->next;
				      cout<<"some information about the product"<<endl<<ptr->th<<endl<<"the price of this book="<<ptr->rs<<endl;
		      process(startbk1->code,u);
		            }
  if(u==3){
	     for(k=1;k<=2;k++)ptr=ptr->next;
	     cout<<"some information about the product"<<endl<<ptr->th<<endl<<"the price of this book="<<ptr->rs<<endl;
		      process(startbk1->code,u);
		  }
   if(u==4){
	     for(k=1;k<=3;k++) ptr=ptr->next;
	     cout<<"some information about the product"<<endl<<ptr->th<<endl<<"the price of this book="<<ptr->rs<<endl;
		      process(startbk1->code,u);
		  }
  if(u==5)
    {
		for(k=1;k<=4;k++) ptr=ptr->next;
		cout<<"some information about the product"<<endl<<ptr->th<<endl<<"the price of this book="<<ptr->rs<<endl;
		      process(startbk1->code,u);
    }
    if(u==6)r=6;
    if(u==7)r=7;			      
}		  
	

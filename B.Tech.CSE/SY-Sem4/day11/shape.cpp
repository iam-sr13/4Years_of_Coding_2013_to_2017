#include<iostream>
#include<typeinfo>
#include<cstdlib>
#define CLR system("clear") 

using namespace std;

void getch(){cin.ignore().ignore();}

class shape
{
	protected:
	double x,y;
	
	public:
	shape(double a=0,double b=0){x=a; y=b;}
	
	virtual void getData()
	{
		cout<<"\nEnter Parameter 1: "; cin>>x;
		cout<<"Enter Parameter 2: "; cin>>y;
	}
	virtual void displayArea()=0;
};

class triangle: public shape
{
	public:
	triangle(double a=0,double b=0):shape(a,b){}
	void getData()
	{
		cout<<"\nEnter base: "; cin>>x;
		cout<<"Enter height: "; cin>>y;
	}
	void displayArea()
	{
		cout<<"\nArea of Triangle = 1/2*base*height = "<<0.5*x*y<<endl;
	}
};

class rectangle: public shape
{
	public:
	rectangle(double a=0,double b=0):shape(a,b){}
	void getData()
	{
		cout<<"\nEnter length: "; cin>>x;
		cout<<"Enter breadth: "; cin>>y;
	}
	void displayArea()
	{
		cout<<"\nArea of Rectangle = length*breadth = "<<x*y<<endl;
	}
};

int main()
{
	int ch;
	char c;
	triangle t;
	rectangle r;
	shape* sp=0;
	
	do{
		do{
			CLR;
			cout<<"\nLets play with shapes.....\n\nChoose your shape:-\n1.Triangle\n2.Rectangle\n\nYour choice: ";
			cin>>ch;
			switch(ch){
				case 1: sp=&t; break;
				case 2: sp=&r; break;
				default: cout<<"\nINVALID CHOICE!!\nPlease try again...."; getch();
			}
		}while(ch!=1 && ch!=2);
		
		string typ=typeid(*sp).name(); typ[0]=' ';
		cout<<"\nYou have chosen"<<typ<<" as your shape...."<<endl;
		
		cout<<"\nNow enter following data for your"<<typ<<" :-";
		sp->getData();
		sp->displayArea();
		
		cout<<"\nDo you want try again? : "; cin>>c; 
	}while(c!='n' && c!='N');
	
	
	return 0;
}

#include<iostream>

using namespace std;

class COMPLEX
{	
	float real,img;
	
	public:
		COMPLEX() {real=img=0;}
		COMPLEX(float r,float i) {get(r,i);}		
		void get(float r,float i) {real=r; img=i;}
		void disp(){cout<<real<<" + i"<<img;}
		
		COMPLEX add(int a)
		{
			COMPLEX c(a+this->real,this->img);
			return c;
		}
		COMPLEX add(COMPLEX &s1)
		{
			COMPLEX c(s1.real+this->real,s1.img+this->img);
			return c;
		}		
		
		COMPLEX operator + (int a)
		{
			return add(a);
		}
		COMPLEX operator + (COMPLEX& s)
		{
			return add(s);
		}
};

COMPLEX operator + (int a, COMPLEX& s)
{
	return s.add(a);
}
istream& operator >>(istream& in, COMPLEX &c)
{
	float r,i;
	cout<<"\nReal: "; cin>>r;
	cout<<"Imaginary: "; cin>>i;
	c.get(r,i);
	return in;
}
ostream& operator <<(ostream& out, COMPLEX &c)
{
	c.disp();
	return out;
}

int main()
{
	int a;
	COMPLEX s1,s2,s3,s4;
	
	cout<<"\nLets play with complex numbers....."<<endl;
	cout<<"\nPlease enter value for complex no. 1 :-"; cin>>s1;
	cout<<"\nPlease enter value for complex no. 2 :-"; cin>>s2;
	cout<<"\nYour complex nos are: \ns1 = "<<s1<<"\ns2 = "<<s2<<endl;
	cout<<"\nNow enter any integer: "; cin>>a;
	s3=a+s2;
	cout<<"\ns3 = a + s2 = "<<s3<<endl;
	s4=s1+s2;
	cout<<"\ns4 = s1 + s2 = "<<s4<<endl;	
	
	return 0;
}

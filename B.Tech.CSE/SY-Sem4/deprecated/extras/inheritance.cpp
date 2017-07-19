#include<iostream>

using namespace std;

class base1
{
	protected:
	int x;
	
	public:
	base1(int n=0){x=n; cout<<"\nbase1 constructed!";}
	~base1(){cout<<"\nbase1 destructed!";}
	void show(){cout<<x;}
};

class base2
{
	protected:
	int x;
	
	public:
	base2(int n=0){x=n; cout<<"\nbase2 constructed!";}
	~base2(){cout<<"\nbase2 destructed!";}
	void show(){cout<<x;}
};

class derived:public base1, public base2
{
	int x;
	
	public:
	derived(int a=0, int b=0, int n=0):base2(a), base1(b)
	{
		x=n; 
		cout<<"\nderived constructed!";
	}
	~derived(){cout<<"\nderived destructed!";}
	void show(){cout<<endl<<base1::x<<", "<<base2::x<<", "<<x<<endl;}
};

int main()
{
	derived ob;
	return 0;
}

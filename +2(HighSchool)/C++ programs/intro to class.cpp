#include <iostream>
#include<iomanip>
#include<windows.h>

using namespace std;

class complex
{
	int real,img;	
	public:
		void putdata(complex p,complex q)
		{
			real=p.real+q.real;
			img=p.img+q.img;
			cout<<"The sum is "<<real<<" + "<<img<<"i";
		}
		void getdata()
		{
			cout<<"Enter the real and imaginary part of complex no. seperately:\n";
			cin>>real>>img;			
		}
};

int main()
{
	cout<<"Welcome...\n\nLet us add some complex nos..\n\n";
	complex a,b,c;
	a.getdata();
	b.getdata();
	c.putdata(a,b);
	ShellExecute( 0,"open","Project test.exe",0,0,SW_SHOWNORMAL);
	
	return 0;	
}

#include<iostream>
#include<string.h>
using namespace std;

class shri
{
	int i;
	public:
		char *a;
		shri(char *x,int j) {
			i=j;
			a=new char[strlen(x)+1];
			strcpy(a,x);
			cout<<"\nConstructor "<<i<<" called.\n";
		}
		~shri()
		{
			delete a;
			cout<<"\nDestructor "<<i<<" called.\n";
		}
};

int main()
{
	shri l("hi! ",1),m("hello! ",2),n("by! ",3);
	cout<<l.a<<m.a<<n.a;
	return 0;
}

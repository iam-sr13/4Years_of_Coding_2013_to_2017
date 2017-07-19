#include<iostream>

using namespace std;

void xtest(int test)
{
	cout<<"\nInside xtest("<<test<<")"<<endl;
	if(test){ cout<<"\nThrows: "<<test<<endl; throw test;}
	else cout<<"\nNo throw!!"<<endl;
}

int main()
{
	cout<<"\nStart"<<endl;
	try{
		cout<<"\nInside try block"<<endl;
		xtest(0);
		xtest(1);
		xtest(2);
	}
	catch(int i)
	{
		cout<<"\nCaught: "<<i<<endl;
	}
	return 0;
}

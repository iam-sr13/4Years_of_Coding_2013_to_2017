#include<iostream>

using namespace std;

void xhandler(int test)
{
	cout<<"\nInside xhandler("<<test<<")"<<endl;
	try{
		cout<<"\nInside try block"<<endl;
		if(test){ cout<<"\nThrows: "<<test<<endl; throw test;}
		else cout<<"\nNo throw!!"<<endl;
	}
	catch(int i)
	{
		cout<<"\nCaught: "<<i<<endl;
	}
}

int main()
{
	cout<<"\nStart"<<endl;	
		
		xhandler(0);
		xhandler(1);
		xhandler(2);	
	
	return 0;
}

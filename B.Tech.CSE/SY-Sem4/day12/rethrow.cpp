#include<iostream>

using namespace std;

int main()
{
	int i;
	float f;
	cout<<"\nstart";	
	
	try {
		cout<<"\nTry block 1!!";
		try {
			cout<<"\nTry block 2!!";
			cout<<"\nEnter any int: "; cin>>i;
			cout<<"\nEnter any float: "; cin>>f;
			if(i) throw i;
			if(f) throw f;
		}
		catch(int e)
		{
			cout<<"\nRethrowing from try block 2... to try block 1!!";
			throw e;
		}
		catch(float f)
		{
			cout<<"\nHandling try block 2!!\nCaught float "<<f<<endl;			
		}
	}
	catch(int e)
	{
		cout<<"\n Handling try block 1!!\nCaught rethrowed int "<<e<<endl;
	}
	return 0;
}

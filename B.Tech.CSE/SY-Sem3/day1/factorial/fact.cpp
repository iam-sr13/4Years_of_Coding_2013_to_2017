#include<iostream>

using namespace std;

int fact(int n)
{
	if(n<=1) return 1;
	else return n*fact(n-1);
}

int main()
{
	int n;
	
	cout<<"\nHey hi, welcome to recursive factorials....\nPlease enter any positive integer: ";
	cin>>n;
	cout<<"\n"<<n<<"! = "<<fact(n)<<"\n\nThank you."<<endl;
	
	return 0;
}

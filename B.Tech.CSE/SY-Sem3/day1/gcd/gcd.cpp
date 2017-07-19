#include<iostream>

using namespace std;

int gcd(int m,int n)
{
	if(m<n) return gcd(n,m);
	return ((m%n==0)?n:gcd(n,m%n));
}

int main()
{
	int m,n;
	
	cout<<"\nHey hi, welcome to Greatest Common Divisor....\nPlease enter any positive integer..\n";
	cout<<"Number 1: ";
	cin>>m;
	cout<<"Number 2: ";
	cin>>n;
	cout<<"\ngcd("<<m<<","<<n<<") = "<<gcd(m,n)<<"\n\nThank you."<<endl;
	
	return 0;
}

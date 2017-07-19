/*
*Author: Shriraj Sawant
*Date: 11/1/2017
*Description: See Q.1 in psheet.jpg
*/
#include<iostream>

using namespace std;

long double power(double m, int n=2)
{
	long double p=1;
	
	for(int i=1; i<=n; i++) {
		p=p*m;
	}
	return p;
}

int main()
{	
	int n=3;
	double m=9;
	
	cout<<"\nPower("<<m<<","<<n<<") = "<<power(m,n)<<endl;
	cout<<"\nPower("<<m<<") = "<<power(m)<<endl;
	return 0;
}

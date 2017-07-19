/*
*Author: Shriraj Sawant
*Date: 11/1/2017
*Description: See Q.2 in psheet.jpg
*/
#include<iostream>
#include<iomanip>
using namespace std;

long double power(double m, int n=2)
{
	long double p=1;
	
	for(int i=1; i<=n; i++) {
		p=p*m;
	}
	return p;
}
long int power(int m, int n=2)
{
	long int p=1;
	
	for(int i=1; i<=n; i++) {
		p=p*m;
	}
	return p;
}

int main()
{	
	int n=3,o=5;
	double m=9;
	
	cout<<setprecision(5)<<"\nWith double Power("<<m<<","<<n<<") = "<<power(m,n)<<endl;
	cout<<"\nWith int Power("<<o<<","<<n<<") = "<<power(o,n)<<endl;
	return 0;
}

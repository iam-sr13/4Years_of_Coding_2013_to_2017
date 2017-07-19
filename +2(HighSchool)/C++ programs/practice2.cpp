#include<iostream>
using namespace std;
#include<cmath>
#include<iomanip>



int vol(int a,int b,int c)
{
	return a*b*c;
}
float vol(int x,int n)
{
	return 4*22.0/7*pow(x+n,3);
}
int vol(int a)
{
	return pow(a,3);
}

int &maxi(int &a, int &b)
{
	if(a>b) return a;
	else return b;
}

int main()
{
	
    int p=1,q=2,r=3;

    maxi(p,q)=vol(3,4,5); 
    cout<<q;
    maxi(q,r)=vol(2,0);
    p=4;
    maxi(r,p)=vol(2);
    cout<<setw(7)<<p<<setw(7)<<q<<setw(7)<<r;
	
	return 0;
}




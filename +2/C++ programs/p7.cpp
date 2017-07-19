#include<iostream>
#include<iomanip>
using namespace std;


main()
{	
	int x,y,z,p;
	x=y=-1;z=0;
	p=x++||--y&&++z;
	cout<<"\nx="<<x<<"\ny="<<y<<"\nz="<<z<<"\np="<<p;
}





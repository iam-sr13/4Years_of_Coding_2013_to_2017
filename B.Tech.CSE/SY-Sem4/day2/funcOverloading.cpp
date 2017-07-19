/*
*Author: Shriraj Sawant
*Date: 11/1/2017
*Description: See Q.3 in psheet.jpg
*/
#include<iostream>
#include<iomanip>
using namespace std;

int manip(int num1, int num2)
{
	return num1*num2;
}
int manip(float num1, float num2)
{
	return num1/num2;
}

int main()
{
	int x=3;
	int y=7;
	int z;
	float a=6.8;
	float b=13.6;
	int c;
	
	z=manip(x,y);
	c=manip(a,b);
	cout<<z<<c<<endl;
	
	return 0;
}

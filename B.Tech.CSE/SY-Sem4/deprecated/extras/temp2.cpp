#include<iostream>
#include<cstdio>

using namespace std;

void funcA(int X, double Y)
{
	cout<<"First func"<<endl;
}
void funcA(char X, float Y)
{
	cout<<"Second func"<<endl;
}

int main()
{
	funcA('a',int(12));
	//for(int i=0; i<256; i++) cout<<i<<" "<<char(i)<<endl;
	
	return 0;
}

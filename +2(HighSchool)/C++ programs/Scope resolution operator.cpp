#include<iostream>
using namespace std;
int a=5;

int main()
{
	int a=10;
	int b='a';
	cout<<"\nb="<<b;
	{
		int a=20;
		cout<<"\na="<<a;
		cout<<"\na="<<::a;
	}
	cout<<"\na="<<a;
	return 0;
}

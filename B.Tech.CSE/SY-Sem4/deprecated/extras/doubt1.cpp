#include<iostream>

using namespace std;

class s1
{
	int a;
	public:
	s1(){a=13;}
	
};

class s2
{
	public:
	int b;
};

int main()
{
	s1 x;
	s2* p=(s2*)&x;
	cout<<p->b;
	return 0;
}

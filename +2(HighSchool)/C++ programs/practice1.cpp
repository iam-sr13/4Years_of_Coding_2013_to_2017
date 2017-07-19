#include<iostream>
#define r return 
using namespace std;
typedef int i;
int f(int n)
{
	i p=1;
	for(int i=2;i<=n;i++)p*=i;
	r p;
}
int main()
{	
	i a;
	
	cout<<"Enter 1-5: ";
	cin>>a;
	wchar_t b='~';
	enum states {goa,delhi=7,mh,ap=1,mp};
	switch(a) {
		case 0:cout<<"goa adsdjhslvhska \
                  n "<<goa<<delhi<<mh<<ap<<mp<<"\n"<<f(5)<<b;break;
		case delhi:cout<<"delhi\n ";break;
		case mh:cout<<"mh\n ";break;
		case ap:cout<<"ap\n ";break;
		case mp:cout<<"mp\n ";break;
	}
	r 0;	
}

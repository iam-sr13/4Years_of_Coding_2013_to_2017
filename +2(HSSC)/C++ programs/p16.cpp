#include<iostream>
#include<stdlib.h>
#include<iomanip>

using namespace std;

class fibbo
{
	int n;
	bool fibcheck();
	public:
		fibbo() {
			cout<<"\n\nPlease enter any integer: ";
			cin>>n;
			if(fibcheck()) cout<<"\nThe no. "<<n<<" BELONG to fibbonacci series!\n";
			else cout<<"\nThe no. "<<n<<" DOESN'T BELONG to fibbonacci series!\n";
		}
};

bool fibbo::fibcheck()
{
	int f1=0,f2=1,f3=1;
	if(n==0 || n==1) return true;
	else {
		for(;f3<=n;) {
			f3=f1+f2;
			if(f3==n) return true;
			f1=f2;
			f2=f3;
		}
	}
	return false;
}

main()
{
	cout<<"0,1";
	for(int i=1,f1=0,f2=1,f3=1;i<=40;i++)
	{		
		f3=f1+f2;
		cout<<","<<f3;
		f1=f2;
		f2=f3;
	}
	cout<<".\n";
	for(;;)fibbo z;
}


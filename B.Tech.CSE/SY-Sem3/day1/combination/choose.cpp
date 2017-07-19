#include<iostream>

using namespace std;

int choose(int n,int r)
{
	if(n<r || n<0 || r<0) throw "Illegal Parameter Value";
	else
	if(r==0||n==r) return 1;
	else return choose(n-1,r)+choose(n-1,r-1);
}

int main()
{
	int n,r,rpt;	
	
	do{
		rpt=0;
		cout<<"\nHey hi, welcome to Combination (nCr)....\nPlease enter any positive integer..\n";
		cout<<"n: ";
		cin>>n;
		cout<<"r: ";
		cin>>r;
		try {
			cout<<"\n"<<n<<"\n C  = "<<choose(n,r)<<"\n  "<<r<<"\n\nThank you."<<endl;
		}
		catch(...)
		{
			cout<<"\nException caught.. use n>r, and n,r +ve always!"<<endl;
			rpt=1;
		}
	}while(rpt);	
	
	return 0;
}

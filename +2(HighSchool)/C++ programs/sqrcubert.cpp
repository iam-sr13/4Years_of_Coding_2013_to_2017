#include<iostream>
#include<math.h>
#include<fstream>
using namespace std;

/*float rem(float w1, float w2)
{
	int q,wi1=w1,wi2=w2;
	q=wi1/wi2;
	return (w1-w2*q);
}
int cubrt(int x)
{
	int i=1;	
	for(;(float)i<=sqrt(x);i++)
	{
		if(pow(i,3)==x) break;		
	}  
	return i;
}*/

main()
{
	int n=0,a,b;
	float sq,cu;
	cin>>a>>b;
	cout<<endl;	
	for(;a<=b;a++)
	{
		sq=pow(a,0.5);
		cu=pow(a,(1.0/3.0));		
		if((int)cu!=cu || (int)sq!=sq) continue;
		else n++;
		//else if(rem(sq,cu)==0) {cout<<a<<endl;n++;}
		//sc=sqrt(cu);
		//if((sq/cu)==sc) {cout<<a<<endl;n++;}
	}
	cout<<endl<<n<<endl;	
}

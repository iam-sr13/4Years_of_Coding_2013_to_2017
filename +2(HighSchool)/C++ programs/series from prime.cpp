#include<iostream>
#include<cmath>

using namespace std;

main()
{
	float sum=0;
	for(int n=1;n<=100000;n++) {
		for(int i=1;i<=100000;i++)
		{
			sum+=pow((float)i,-n);
		}
		cout<<"For "<<n<<" prime= "<<sum<<endl;
		sum=0;
	}
}

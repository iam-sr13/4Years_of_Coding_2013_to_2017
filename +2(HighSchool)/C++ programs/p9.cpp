#include<iostream>
#include<iomanip>
using namespace std;
main()
{
	int i,dat=14663;
	cout<<"\n\nENCRYPTING....";
	for(i=0;i<dat;i++) {		
	 cout<<setprecision(2)<<setw(6)<<((float)i/dat*100)<<"% complete.\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
	}
	cout<<"100.00% complete.";
	cout<<"\n\nENCRYPTION SUCCESSFULL!";
}

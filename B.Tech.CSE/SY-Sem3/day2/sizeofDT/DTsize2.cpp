#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main()
{
	enum Enum{};
	
	cout<<"\n__________________________________________________________";
	cout<<"\nData Type   | Size (bytes) | Range\n____________|______________|______________________________\n            |              |          ";
	cout<<"\nint         |  "<<sizeof(int)<<"           | "<<-pow(2,31)<<" TO "<<pow(2,31);
	cout<<"\nsignedint   |  "<<sizeof(signed int)<<"           | "<<-pow(2,31)<<" TO "<<pow(2,31);
	cout<<"\nunsignedint |  "<<sizeof(unsigned int)<<"           |           "<<0<<" TO "<<pow(2,32);
	cout<<"\nshortint    |  "<<sizeof(short)<<"           |      "<<-pow(2,15)<<" TO "<<pow(2,15);
	cout<<"\nlongint     |  "<<sizeof(long)<<"           | "<<-pow(2,31)<<" TO "<<pow(2,31)<<"\n            |"<<"              |";
	cout<<"\nfloat       |  "<<sizeof(float)<<"           | "<<"1.2E-38"<<" TO "<<"3.4E+38";
	cout<<"\ndouble      |  "<<sizeof(double)<<"           | "<<"2.2E-308"<<" TO "<<"1.8E+308";
	cout<<"\nlong double |  "<<sizeof(long double)<<"          | "<<"1.1E-317"<<" TO "<<"1.1E+317"<<"\n            |"<<"              |";
	cout<<"\nchar        |  "<<sizeof(char)<<"           | "<<-pow(2,7)<<" TO "<<pow(2,7)<<"\n            |"<<"              |";
	cout<<"\nenum        |  "<<sizeof(Enum)<<"           | "<<0<<" TO n";
	
	return 0;
}

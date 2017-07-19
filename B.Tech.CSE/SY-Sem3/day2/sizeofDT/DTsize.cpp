#include<iostream>
#include<iomanip>
#include<climits>
#include<cfloat>
using namespace std;

int main()
{
	enum Enum{};
	
	cout<<"\n__________________________________________________________";
	cout<<"\nData Type   | Size (bytes) | Range\n____________|______________|______________________________\n            |              |          ";
	cout<<"\nint         |  "<<sizeof(int)<<"           | "<<INT_MIN<<" TO "<<INT_MAX;
	cout<<"\nsignedint   |  "<<sizeof(signed int)<<"           | "<<INT_MIN<<" TO "<<INT_MAX;
	cout<<"\nunsignedint |  "<<sizeof(unsigned int)<<"           |           "<<0<<" TO "<<UINT_MAX;
	cout<<"\nshortint    |  "<<sizeof(short)<<"           |      "<<SHRT_MIN<<" TO "<<SHRT_MAX;
	cout<<"\nlongint     |  "<<sizeof(long)<<"           | "<<LONG_MIN<<" TO "<<LONG_MAX<<"\n            |"<<"              |";
	cout<<"\nfloat       |  "<<sizeof(float)<<"           | "<<FLT_MIN<<" TO "<<FLT_MAX;
	cout<<"\ndouble      |  "<<sizeof(double)<<"           | "<<DBL_MIN<<" TO "<<DBL_MAX;
	cout<<"\nlong double |  "<<sizeof(long double)<<"          | "<<LDBL_MIN<<" TO "<<LDBL_MAX<<"\n            |"<<"              |";
	cout<<"\nchar        |  "<<sizeof(char)<<"           | "<<CHAR_MIN<<" TO "<<CHAR_MAX<<"\n            |"<<"              |";
	cout<<"\nenum        |  "<<sizeof(Enum)<<"           | "<<0<<" TO n";
	
	return 0;
}

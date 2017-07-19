#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

int main()
{
	fstream ifile,ofile;
	ofile.open("file.dat",ios::out);
	int a,b,c,d,e,f;
	cout<<"enter:\n";
	cin>>a>>b>>c;
	ofile<<a<<" "<<b<<endl<<c;
	ofile.close();
	ifile.open("file.dat",ios::in);
	cout<<"\nYou entered:\n";	
	
	ifile>>d;
	ifile>>e;
	ifile>>f;
	ifile.close();
	
	cout<<"\n"<<d<<" "<<e<<" "<<f;	
	return 0;
}
	

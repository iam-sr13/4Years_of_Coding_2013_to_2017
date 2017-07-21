#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;

main()
{
	//fstream fin,fout,fbin;
	string sym,nam,n="119";
	float mn;
	ifstream fin(("D:\\C++ programs\\QPT\\test prog\\elements\\"+n+".txt").c_str());	
	fin>>sym;
	fin>>nam;
	fin>>mn;
	fin.close();
	cout<<sym<<" ! "<<nam<<" ! "<<mn;
	/*fin.open("in.txt",ios::in);
	fout.open("out.txt",ios::out);

	int i,n1,n2;
	float f1,f2;
	
	string s1,s2,s3,s4;
	fin>>n1>>n2>>f1>>f2;
	fin>>s3>>s4;
	fin.ignore();
	getline(fin,s1);
	getline(fin,s2);
	
	fin.close();
	
	fout<<"\nThis is the data:\n\nint: "<<n1<<", "<<n2<<"\n\nfloat: "<<f1<<", "<<f2<<"\n\nstrings: "<<s4<<", "<<s3;
	fout<<"\n\nThis are the string lines:\n"<<s1<<endl<<s2;
	fout<<char(26);
	fout<<"\n\nThank you!";
	
	
	fout.close();	
	fin.open("out.txt",ios::in);
	while(!fin.eof()) {
		fin>>s1;
		cout<<endl<<s1;
	}
	fin.close();
	fout.open("in.txt",ios::out|ios::app);
	fout<<endl<<"hi!";
	fout.close();*/
}

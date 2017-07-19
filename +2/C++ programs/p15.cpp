#include<iostream>
#include<iomanip>
#include<conio.h>
#include<sstream>
#include<cmath>
#define sstream stringstream
using namespace std;
int binary(int a)
	{
		int i,n=0;
		for(i=0;a!=0;a/=2,i++) n+=(a%2)*pow(10,i);
		return n;
	}	
	
int decimal(int a)
{
	int i,n=0;
	for(i=0;a!=0;a/=10,i++) n+=(a%10)*pow(2,i);
	return n;
}

int int_(char a)//yahoo....this is my success function of ndCRPTR 4.0!!!!!!!
{
	int n=int(a);
	if(n<0) return 256+n;
	else return n;
}

main()
{
	int j;
	string data;
	for(j=0;j<=255;j++) {
		sstream temp;
		int i,c,a;
		long long int x=0;	
		string t;
		data=char(j);
		
		/*cout<<"\n\nENCRYPTING....";
		for(i=0;i<data.size();i++) {		
			for(a=0,c=0;c<=127;c++,a++) if(data[i]==(char)c) {data[i]=(char)(2*a);x=1;break;}
			cout<<setprecision(2)<<setw(6)<<(((float)i/data.size())*100)<<"% complete.\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
			if(i==(data.size()-1)) cout<<"100.00% complete.";
			if(x) continue;
			for(a=0,c=128;c<=255;c++,a++) if(data[i]==(char)c) {data[i]=(char)(2*a+1);x=1;break;}							
		}	
		cout<<"\n\nENCRYPTION SUCCESSFULL!";
		cout<<"\n\nYour encrypted DATA:=         (press any key)\n\n";
		getch();
		cout<<data;*/	
			
		for(i=0;i<data.size();i++) {			
			temp<<(1000000000+binary(int_(data[i])));
			t+=temp.str();
			temp.str("");		
		}
		cout<<"\nDATA=\n\n"<<t<<endl<<endl;
		string d2;	
		for(i=0;i<t.size();) {
			for(c=1,x=0;c<=10;c++,i++) {			
				a=t[i]-48;			
				x=x*10+a;			
			}		
			d2+=char(decimal(x-1000000000));
		}
		cout<<"\nDATA=\n\nnext:-\n"<<d2<<endl<<endl;
	}
}

#include<iostream>
#include<math.h>
#include<sstream>
#define stin stringstream 
using namespace std;


void delay(int i)
{
	int j;
	for(j=0;j<=i;j++) delay(i-1);
}

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

main()
{
	int a,k;
	char b='a';
	a=int(b);
	string z=string(a);
	stin(z)>>k;
	cout<<k<<" "<<z<<endl;
	cout<<binary(260);
	cout<<" "<<decimal(binary(13));
	cout<<endl<<b<<"="<<a<<"="<<binary(int('a'))<<"="<<char(decimal(binary(int('a'))));
	//string c;
    //for(i=1;i<=26;i++,a++) cout<<a<<endl;	
	

//	for(a=0;a<=256;a++) {cout<<" "<<(char)a<<" "<<(char)a<<(char)a<<" "<<a<<endl;}
//	for(a=0;a<100;a++) {
//		c=(char)219;	
//		cout<<c;
//		delay(9);
//	}
    	
}


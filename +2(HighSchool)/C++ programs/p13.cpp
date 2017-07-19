#include<iostream>
#include<math.h>
#include<sstream>
#define sstream stringstream 
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

string enc2(string data)
{
	int i;
	sstream temp;
	string t="";	
	for(i=0;i<data.size();i++) {
		temp<<(10000000000+binary(int(data[i])));		
	}
	t=temp.str();
	cout<<"\nDATA=\n\n"<<t<<endl;	
	return t;
}

void dec2(string data)
{
	int i,j,k;
	unsigned long long int x;
	sstream temp;
	string u="00000000000",v;
	for(i=0,k=0;i<data.size();i++,k++) {
		u[k]=data[i];				
		if(k==10) {
			cout<<u<<endl;
			temp.str(u);
			temp>>x;
			cout<<x<<endl;			
			k=-1;			
		}
	}
}

main()
{
	string z="H",a="abc";//a="Hi! I am Shri. I live in bicholim. By!\n\n";
	cout<<binary(int(z[0]));
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	/*int a=13;
	//char b='a';
	//a=int(b);
	string z="abc",y;
	ss k;
	k<<(10000000000+binary(int(z[0])));
	y=k.str();
	cout<<y<<endl<<binary(97);
	/*cout<<binary(260);
	cout<<" "<<decimal(binary(13));
	cout<<endl<<b<<"="<<a<<"="<<binary(int('a'))<<"="<<char(decimal(binary(int('a'))));*/
	//string c;
    //for(i=1;i<=26;i++,a++) cout<<a<<endl;	
	

//	for(a=0;a<=256;a++) {cout<<" "<<(char)a<<" "<<(char)a<<(char)a<<" "<<a<<endl;}
//	for(a=0;a<100;a++) {
//		c=(char)219;	
//		cout<<c;
//		delay(9);
//	}
    	



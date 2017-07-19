#include<cstring>
#include<cctype>
#include<iostream>
#include<stdio.h>

using namespace std;
int main()
{
	char **p,*x=new char;
	int n,i,j;
	cout<<"\nEnter total no. of names: ";
	cin>>n;
	p=new char*[n];
	for(i=0;i<n;i++) p[i]=new char;
	for(i=0,cout<<"\n\nEnter names:";i<n;i++) {
		cout<<"\n"<<i+1<<": ";	
		cin>>p[i];   
	}                     
	
	for(i=1;i<n;i++) {
		cout<<"\n!\n";
		strcpy(x,p[i]);
		cout<<"\n!\n";
		for(j=i-1;(j>=0 && (strcmp(x,p[j])<0));j--)
			strcpy(p[j+1],p[j]);
			cout<<"\n!\n";
		strcpy(p[j+1],x);
		cout<<"\n!\n";
	}
			
	for(i=0,cout<<"\n\nYour sorted list:";i<n;i++) {
		cout<<"\n"<<i+1<<": "<<p[i];		
	}
                                    
	return 0;
}

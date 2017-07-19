#ifndef _MYSTACKARR_
#define _MYSTACKARR_

#include<iostream>
#include<conio.h>
#define MAX 10

using namespace std;

class stackarr
{
	char *s;
	int top,capacity;
	
	public:
	stackarr(int n=MAX){capacity=n; top=0; s=new char[capacity];}
	~stackarr(){delete[] s;}
	
	void push(char a);
	char pop();
	char topelem();
	
	void show();
	int size();	
	bool empty(){if(top==0) return true; else return false;}	
};
char stackarr::topelem()
{
	return s[top-1];
}
int stackarr::size()
{
	return top;
}
void stackarr::show()
{
	for(int i=top-1;i>=0;i--) cout<<endl<<"  "<<s[i];
}
void stackarr::push(char a)
{
	if(top==MAX){
		cout<<endl<<"STACK OVERFLOW!!"<<endl;
		getch();
	} 
	else s[top++]=a;	
}
char stackarr::pop()
{
	char a;
	if(top==0) {
		cout<<endl<<"STACK UNDERFLOW!!"<<endl;
		getch();		
	}
	else a=s[--top];		 
		 
	return a;	
}

#endif

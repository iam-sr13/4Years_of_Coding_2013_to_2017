#include<iostream>
#include<iomanip>
#define CLR (system("cls"))
#define MAX 10
using namespace std;

class stack
{
	int *s,top,cap;
	public:
	stack(int n=MAX){ s=new int[n];cap=n;top=0;}
	void push(int a);
	int pop();
	void show();	
};
void stack::show()
{
	for(int i=top-1;i>=0;i--) cout<<endl<<s[i];
}
void stack::push(int a)
{
	if(top==cap) cout<<endl<<endl<<"STACK OVERFLOW!!"<<endl;
	else s[top++]=a;	
}
int stack::pop()
{
	int a;
	if(top==0) cout<<endl<<endl<<"STACK UNDERFLOW!!"<<endl;
	else a=s[--top];
	return a;	
}

main()
{
	int n,x;
	stack balls;
	cout<<"\nEnter no. of balls and then their size: ",cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>x;
		balls.push(x);
	}
	for(int i=n;i>=1;i--) cout<<endl<<balls.pop();
}

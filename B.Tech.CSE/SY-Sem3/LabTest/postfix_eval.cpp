#include<iostream>
#include<iomanip>
#include<conio.h>
#include<algorithm>
#define CLR (system("cls"))

using namespace std;

class stack
{
	int *a,top,size,capacity;
	
	public:
		stack(int xcapacity = 10)
		{
			capacity = xcapacity;
			top = size = 0;
			a = new int[capacity];
		}
		~stack()
		{
			top=size=capacity=0;
			delete[] a;
		}
		
		bool isEmpty()
		{
			if(size==0) return true; else return false;
		}
		void push(int x)
		{
			if(top == capacity){
				cout<<"\nStack Overflow!!"<<endl;
				getch();
			} 
			else{
				a[top++] = x;
				size++;
			}
		}
		void pop()
		{
			if(size == 0)
			{
				cout<<"\nStack Empty!!"<<endl;
				getch();
			} 
			else {
				top--;
				size--;
			}
		}
		int topElem()
		{
			return a[top-1];
		}
		
};

int main()
{
	string q;
	stack p(100);
	
	cout<<"\nWELCOME to Postfix Evaluation Program!!\n\nPlease enter your postfix expression: ";
	cin>>q;
	
	for(int i=0; i<q.size(); i++) {
		if(isdigit(q[i])) p.push(int(q[i])-48);
		else {
			int a,b;
			switch(q[i]) {
				case '+': {
					b=p.topElem(); p.pop();
					a=p.topElem(); p.pop();
					p.push(a+b);
					break;
				}
				case '-': {
					b=p.topElem(); p.pop();
					a=p.topElem(); p.pop();
					p.push(a-b);
					break;
				}
				case '*': {
					b=p.topElem(); p.pop();
					a=p.topElem(); p.pop();
					p.push(a*b);
					break;
				}
				case '/': {
					b=p.topElem(); p.pop();
					a=p.topElem(); p.pop();
					p.push(a/b);
					break;
				}
				default: cout<<"\nSysError!!"<<endl;
			}
		}
	}
	
	cout<<"\nYour Answer is : "<<p.topElem();	
	
	return 0;
}






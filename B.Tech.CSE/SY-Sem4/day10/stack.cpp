#include<iostream>
#include<cstdlib>
#define CLR system("clear") 

using namespace std;

void getch(){cin.ignore().ignore();}

class Stack1
{
	protected:
	int* a;
	int n,top;	
	
	public:
	Stack1(int x=0) {
		n=x;
		top=0;
		if(n>0){
			a=new int[n];
		}
	}
	~Stack1() {
		if(n>0) delete[] a;
		n=0;
		top=0;
	}
	int size(){return top;}
	void renew(int x)
	{
		if(n>0) delete[] a;
		n=x;
		top=0;
		if(n>0){
			a=new int[n];
		}
	}
	
	virtual void push(int x)
	{		
		//if(top<n) {
			a[top]=x;
			top++;
		//}		
	}
	virtual int pop()
	{			
		//if(top>0) {			
			top--;			
			return a[top];
		//}
		//return 0;	
	}	
	void display()
	{
		cout<<endl<<"^";
		for(int i=top-1;i>=0;i--) cout<<endl<<a[i]; 
		cout<<endl<<"_";		
	}	
};

class Stack2:public Stack1
{
	public:
	Stack2(int x=0):Stack1(x){}
	void push(int x)
	{
		if(top<n) {
			a[top]=x;
			top++;
		}
		else{
			throw "STACK OVERFLOW!!";
		}
	}
	int pop()
	{
		if(top>0) {			
			top--;			
			return a[top];
		}
		else{
			throw "STACK UNDERFLOW!!";
		}
	}	
};

ostream& operator <<(ostream& out,Stack1& z)
{
	z.display();
	return out;
}
ostream& operator <<(ostream& out,Stack2& z)
{
	z.display();
	return out;
}

int main()
{
	int n,ch;	
	
	cout<<"\nLets play with stacks....\nEnter the max size of your stack: "; cin>>n;
	
	do{
		CLR;
		cout<<"\n#MAIN MENU\n\n1.Type\n2.Quit\n\nYour choice: "; cin>>ch;
		
		switch(ch){
			case 1: {
				cout<<"\n1.Stack1(Unsafe)\n2.Stack2\n\nYour choice: "; cin>>ch;
				switch(ch){
					case 1: {
						int x;						
						Stack1 z(n);
						
						do{
							CLR;
							cout<<"\n#Stack1 MENU\n\nYour Stack1: "<<z<<"\n\n1.Push\n2.Pop\n3.Back\n\nYour choice: "; cin>>ch;
							switch(ch) {
								case 1:{
									cout<<"\nEnter any integer: "; cin>>x;
									z.push(x);									
									break;
								}
								case 2:{
									z.pop();									
									break;
								}
								case 3:{
									break;
								}
								default: cout<<"\nINVALID CHOICE!! Please try again....\n"; getch();
							}
						}while(ch!=3);
						
						break;
					}
					case 2: {
						int x;
						Stack2 z(n);
						
						do{
							CLR;
							cout<<"\n#Stack2 MENU\n\nYour Stack2: "<<z<<"\n\n1.Push\n2.Pop\n3.Back\n\nYour choice: "; cin>>ch;
							switch(ch) {
								case 1:{
									cout<<"\nEnter any integer: "; cin>>x;
									try{z.push(x);}
									catch(char const* e){cout<<endl<<e<<endl; getch();}
									break;
								}
								case 2:{
									try{z.pop();}
									catch(char const* e){cout<<endl<<e<<endl; getch();}
									break;
								}
								case 3:{
									break;
								}
								default: cout<<"\nINVALID CHOICE!! Please try again....\n"; getch();
							}
						}while(ch!=3);
						
						break;
					}
					
					default: cout<<"\nINVALID CHOICE!! Please try again....\n"; getch();
				}
				break;
			}
			case 2: {
				break;
			}
			default: cout<<"\nINVALID CHOICE!! Please try again....\n"; getch();
		}
	}while(ch!=2);		

	return 0;
}

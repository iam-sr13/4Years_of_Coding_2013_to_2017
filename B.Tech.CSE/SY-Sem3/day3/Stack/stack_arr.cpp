#include<iostream>
#include<iomanip>
#include<algorithm>
#include<conio.h>
#define CLR (system("cls"))
#define MAX 10
using namespace std;

class stack
{
	int s[MAX],top;
	public:
	stack()	{ top=0;}
	void push(int a);
	int pop();
	void show();
	int size();
	int topelem();
	bool empty(){if(top==0) return true; else return false;}	
};
int stack::topelem()
{
	return s[top-1];
}
int stack::size()
{
	return top;
}
void stack::show()
{
	for(int i=top-1;i>=0;i--) cout<<endl<<setw(2)<<s[i];
}
void stack::push(int a)
{
	if(top==MAX){
		cout<<endl<<"STACK OVERFLOW!!"<<endl;
		getch();
	} 
	else s[top++]=a;	
}
int stack::pop()
{
	int a;
	if(top==0) {
		cout<<endl<<"STACK UNDERFLOW!!"<<endl;		
	}
	else{
		a=s[--top];
		cout<<"\nPopped value: "<<a; 
	}
	getch(); 
	return a;	
}

main()
{
	int n,x,c;
	stack mystk;
	
	do{
		CLR;
		cout<<"\nWELCOME to Stack Program!\n\n#Main Menu:\n\nYour Stack: \n"; mystk.show(); 
		cout<<"\n\n1.Push Element\n2.Pop Element\n3.Top element\n4.Size\n5.IsEmpty\n6.Quit\n\nYour choice: ";
		cin>>c;
		
		switch(c) {
			case 1:{
				cout<<"\nPlease enter any integer value: "; cin>>x;				
				mystk.push(x);
				break;
			}
			case 2:{				
				mystk.pop();
				break;
			}
			case 3:{
				if(mystk.empty())cout<<"\nStack is empty";
				else cout<<"\nTop Element: "<<mystk.topelem();
				getch();
				break;
			}
			case 4:{
				cout<<"\nStack current size: "<<mystk.size(); getch();
				break;
			}
			case 5:{
				if(mystk.empty())cout<<"\nStack is empty!";
				else cout<<"\nStack is not empty!";
				getch();
				break;
			}
			case 6:{				
				break;
			}
			default: cout<<"\nWrongChoice!!";getch();				
		}		
	}while(c!=6);
	
	return 0;
}

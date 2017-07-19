#include<iostream>
#include<iomanip>
#include<cstdlib>
#define CLR (system("cls"))

using namespace std;

void getch() {system("pause");/*cin.ignore().ignore().clear();*/}

class stack
{
	int *s,top,MAX;
	
	public:
	stack(int m=10)	{ 
		s=0; 
		top=0;
		if(m) {
			MAX=m;
			s=new int[MAX];
		}
	}
	void push(int a);
	int pop();
	void show();
	int size();
	int topelem();
	bool empty(){if(top==0) return true; else return false;}
	
	stack operator+(int a)
	{
		push(a);
		return *this;	
	}	
	stack operator--()
	{
		pop();
		return *this;	
	}
	stack operator--(int i)
	{
		pop();
		return *this;	
	}
	stack operator-()
	{
		pop();
		return *this;	
	}
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
		cout<<"\nPopped value: "<<a<<endl; 
	}
	getch(); 
	return a;	
}

ostream& operator <<(ostream& out,stack s)
{
	s.show();
	return out;
}

int main()
{
	int x,c;
	stack s1;
	
	do{
		CLR;
		cout<<"\nWELCOME to Stack Program!\n\n#Main Menu:\n\nYour Stack: \n"<<s1<<endl; 
		cout<<"\n1.Push Element\n2.Pop Element\n3.Top element\n4.Size\n5.IsEmpty\n6.Quit\n\nYour choice: ";
		cin>>c;
		
		switch(c) {
			case 1:{
				cout<<"\nPlease enter any integer value: "; cin>>x;				
				s1=s1+x;
				break;
			}
			case 2:{				
				s1=-s1;
				break;
			}
			case 3:{
				if(s1.empty())cout<<"\nStack is empty"<<endl;
				else cout<<"\nTop Element: "<<s1.topelem()<<endl;
				getch();
				break;
			}
			case 4:{
				cout<<"\nStack current size: "<<s1.size()<<endl; getch();
				break;
			}
			case 5:{
				if(s1.empty())cout<<"\nStack is empty!"<<endl;
				else cout<<"\nStack is not empty!"<<endl;
				getch();
				break;
			}
			case 6:{				
				break;
			}
			default: cout<<"\nWrongChoice!!"<<endl; getch();				
		}		
	}while(c!=6);
	
	return 0;
}

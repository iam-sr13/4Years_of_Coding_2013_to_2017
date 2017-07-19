#include<iostream>
#include<cctype>
#include"stack.hpp"

using namespace std;

int chartoint(unsigned char a)
{
	return a-48;
}

int main()
{
	string q;	
	stack p; //int	
	
	cout<<"\nWELCOME!! This is InfixPostfix Program\n\nNow enter your Postfix Expression: ";
	cin>>q;	
	
	for(int i=0;i<q.size();i++) {
		if(isdigit(q[i])) p.push(chartoint(q[i]));
		else {
			switch(q[i]) {
				case'+':{
					int b=p.pop(),a=p.pop(),c=a+b;
					p.push(c);					
					break;
				}
				case'-':{
					int b=p.pop(),a=p.pop(),c=a-b;
					p.push(c);	
					break;
				}
				case'*':{
					int b=p.pop(),a=p.pop(),c=a*b;
					p.push(c);	
					break;
				}
				case'/':{
					int b=p.pop(),a=p.pop(),c=a/b;
					p.push(c);	
					break;
				}
			}
		}
	}
	cout<<"\nYour Answer: "<<p.topelem();	
	
	return 0;	 
}

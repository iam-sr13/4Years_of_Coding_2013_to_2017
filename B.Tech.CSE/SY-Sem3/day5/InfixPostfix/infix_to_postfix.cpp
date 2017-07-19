#include<iostream>
#include<cctype>
#include"stack_arr.hpp"

using namespace std;

int op(char a)
{
	switch(a) {
		case'+':{
			return 1;
			break;
		}
		case'-':{
			return 1;
			break;
		}
		case'*':{
			return 2;
			break;
		}
		case'/':{
			return 2;
			break;
		}
		default: return 0;
	}
}

int main()
{
	string q;
	stackarr p(100); //char		
	
	cout<<"\nWELCOME!! This is InfixPostfix Program\n\nNow enter your Infix Expression: ";
	cin>>q;
	
	cout<<"\nYour Postfix Expression: ";
	for(int i=0;i<q.size();i++) {
		if(isalnum(q[i])) cout<<q[i];
		else {
			switch(q[i]) {
				case '(':{
					p.push(q[i]);
					break;
				}
				case ')':{					
					while(p.topelem()!='(') {						
						cout<<p.topelem();
						p.pop();
					}
					p.pop();
					break;
				}				
				default:{
					if( p.empty() || p.topelem()=='(' || op(p.topelem()) < op(q[i]) ) p.push(q[i]);						
						else {
							cout<<p.topelem();
							p.pop();
							p.push(q[i]);
						}
				}
					/*if( p.empty() || p.topelem()=='(' ) p.push(q[i]);
					else if(p.topelem()!='('){
						if( op(p.topelem()) < op(q[i]) ) p.push(q[i]);
						else {
							cout<<p.topelem();
							p.pop();
							p.push(q[i]);
						}
					}*/
								
			}
		}
	}
	while(!p.empty())
	{												
		cout<<p.topelem();
		p.pop();
	}
	
	return 0;	 
}

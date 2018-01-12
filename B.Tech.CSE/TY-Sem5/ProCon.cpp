#include<iostream>
#include<queue>
#define MAX 5

using namespace std;

queue<int> buff;

void producer()
{
	while(buff.size()<MAX)
	{
		int a;
		char c;
		cout<<"\nWant to produce value (y/n)?\n";
		cin>>c;
		if(c=='n') break;
		
		cout<<"\nEnter Product value: ";
		cin>>a;
		buff.push(a);		
	}
}

void consumer()
{
	while(buff.size()>0)
	{
		cout<<"\nConsumed value: "<<buff.front()<<endl;
		buff.pop();
	}
}

int main()
{
	while(1)
	{
		producer();
		consumer();
	}
	return 0;
}

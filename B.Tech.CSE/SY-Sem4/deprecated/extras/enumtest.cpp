#include<iostream>
#include<cstdio>
#define func (x) (x)*10
using namespace std;

enum a{x,y,z};
enum b{p,q};

class test
{
	int a;
	public:
		test(int v);
};
test::test(int v){a=v;}

int& fun()
{
	int static a = 10;
	return a;
}

int main()
{
	//for(int i=q; i<=z;i++) cout<<i<<" "; 
	
	/*int& y=fun();
	y=y+30;
	cout<<fun();*/
	
	/*for(unsigned char i=0; i<300; i++) cout<<(unsigned int)i<<endl;*/
	
	/*int y=func(5);	
	cout<<y;*/
	
	/*int i=20,j;
	i=(printf("Hello"),printf(" All Good "));
	printf("%d",i);*/
	
	test z[10]={1,2,3,4,5,6,7,8,9,0};
	
	return 0;
}

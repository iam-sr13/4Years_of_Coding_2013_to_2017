#include<iostream>

int main()
{
	int a[5]={1,6,3,4,5};
	int* p=&a[0];
	
	std::cout<<p<<" ";
	std::cout<<*p<<" ";
	//std::cout<<*++p<<" ";
	std::cout<<*p++<<" "<<a[0]<<" "<<a[1];
	//std::cout<<*p++;
	return 0;
}

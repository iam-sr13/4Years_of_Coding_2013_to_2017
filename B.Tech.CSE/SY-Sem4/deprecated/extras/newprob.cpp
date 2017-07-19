#include<iostream>

int main()
{
	int *p=new int;
	*p=1;
	std::cout<<p<<" "<<*p<<" "<<sizeof(*p)<<" "<<sizeof(p)<<std::endl;
	
	delete[] p;
	
	std::cout<<p<<" "<<*p<<" "<<sizeof(*p)<<" "<<sizeof(p)<<std::endl;
	p=0;
	delete p;
	
	///static
	
	int a[5];
	std::cout<<a<<" "<<*(a+13)<<" "<<sizeof(*a)<<" "<<sizeof(a);
	
	
	return 0;
}

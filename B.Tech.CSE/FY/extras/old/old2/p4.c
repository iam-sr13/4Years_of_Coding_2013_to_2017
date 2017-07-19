#include<stdio.h>

int main()
{
	int a=5,*pa;
	
	pa=&a;
	printf("\n%p\n%p\n%d\n%d\n",pa,&a,a,*pa);	

	return 0;
}

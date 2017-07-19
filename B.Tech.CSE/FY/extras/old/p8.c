#include<stdio.h>
int main()
{
	int x,y,z;

	printf("\nEnter any number: x=  ");
	scanf(" %d",&x);
	printf("\nx = %d",x);
	y=x;
	printf("\n++y = %d",++y);
	printf("\ny = %d",y);
	z=x;
	printf("\nz++ = %d",z++);
	printf("\nz = %d\n\n",z);
	
	return 0;
}

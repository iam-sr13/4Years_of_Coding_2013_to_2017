#include<stdio.h>
int main()
{
	int a,b,c,l;
	printf("\n enter any 3 integers seperated by a blank space:");
	scanf("%d %d %d",&a,&b,&c);
	l=a;
	l=l<b && b>c?b:(c>l?c:l);
	printf("\n the largest no. is %d \n",l);
	return 0;
}

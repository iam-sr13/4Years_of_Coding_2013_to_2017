#include<stdio.h>
int main()
{
	int a,b,l;
	printf("\n enter any 2 integers seperated by a blank space:");
	scanf("%d %d",&a,&b);
	l=a;
	l=l<b?b:a;
	printf("\n the largest no. is %d",l);
	return 0;
}




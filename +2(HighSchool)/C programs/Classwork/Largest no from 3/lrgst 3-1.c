#include<stdio.h>
int main()
{
	int a,b,c,l;
	printf("\n enter any 3 integers seperated by a blank space:");
	scanf("%d %d %d",&a,&b,&c);
	l=a;
	if(l<b) l=b;
	if(l<c) l=c;
	printf("\n The largest among 3 is %d",l);
	return 0;
}

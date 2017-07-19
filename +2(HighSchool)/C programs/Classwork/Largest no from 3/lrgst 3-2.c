#include<stdio.h>
int main()
{
	int a,b,c;
	printf("\n enter any 3 integers seperated by a blank space:");
	scanf("%d %d %d",&a,&b,&c);
	if(a>b&&a>c) printf("\nThe largest among three is %d",a);
	if(b>a&&b>c) printf("\nThe largest among three is %d",b);
	if(c>a&&c>b) printf("\nThe largest among three is %d",c);
	return 0;
}

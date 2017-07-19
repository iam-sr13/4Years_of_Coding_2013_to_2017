#include<stdio.h>

void main()
{
	int a,b,c;

	printf("\nThis is program of summation of any two integers\n\nPlease enter any two integers:\n");
	scanf(" %d %d",&a,&b);
	c=a+b;
	printf("\nThe sum of %d and %d is %d\n",a,b,c);
	c=a*b;
	printf("\nThe product of %d and %d is %d\n",a,b,c);
	c=a-b;
	printf("\nThe difference of %d and %d is %d\n",a,b,c);
	if(!b){
	printf("\nThe quotient of %d and %d is not defined\n",a,b);
	}
	else printf("\nThe quotient of %d and %d is %d\n",a,b,c);
	c=a%b;
	printf("\nThe remainder of %d and %d is %d\n",a,b,c);
}

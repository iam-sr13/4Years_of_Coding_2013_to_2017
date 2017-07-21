#include<stdio.h>
int main()
{
	int a,sum,d;
	printf("\nEnter a 4 digit integer:");
	scanf("%d",&a);
	sum=0;
	d=a%10;
	sum=sum+d;
	a=a/10;	
	d=a%10;
	sum=sum+d;
	a=a/10;	
	d=a%10;
	sum=sum+d;
	a=a/10;		
	sum=sum+a;	
	printf("\nThe sum of the digits is %d.",sum);
	return 0;
}

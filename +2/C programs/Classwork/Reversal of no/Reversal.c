#include<stdio.h>
int main()
{
	int n,r=0,d;
	printf("\nEnter any number:");
	scanf("%d",&n);
	do {
		d=n%10;
		r=r*10+d;
		n=n/10;
	}
	while (n>0); 
	printf("\nThe reversal of the no. is %d",r);
	return 0;
}

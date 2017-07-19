#include<stdio.h>
int main()
{
	int n,x,sum,d,p;
	printf("\nEnter any number:");
	scanf("%d",&n);
	x=n;
	sum=0;
	do {
		d=n%10;
		p=d*d*d;
		sum=sum+p;
		n=n/10;
	}
	while (n>0);
	if (sum==x) printf("\nThe no. %d is ARMSTRONG NUMBER.",x);
	else printf("\nThe no. %d is NOT AN ARMSTRONG NUMBER.",x);
	return 0;
}
		

28#include<stdio.h>
int main()
{
	int n,i=1,s=0;
	printf("\nEnter the value for determining whether it is perfect or not:");
	scanf("%d",&n);
	while(i<=n/2) {
		if (n%i==0) s=s+i;
		i++;
	}
	if(s==n) printf("\nThe no. %d is PERFECT NUMBER",n);
	else printf("\nThe no. %d is NON PERFECT NUMBER",n);
	return 0;
}

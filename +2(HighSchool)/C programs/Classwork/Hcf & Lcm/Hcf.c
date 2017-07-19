#include<stdio.h>
int main()
{
	int a,b,i=2,p=1,m,n;
	printf("\nEnter two values for determining their hcf:");
	scanf("%d %d",&a,&b);
	m=a;n=b;
	if (a>b) i=b;
	else i=a;
	while (a!=1 && b!=1 && i>=2) {
		if (a%i==0 && b%i==0) {
			a=a/i;
			b=b/i;
			p=p*i;
		}
		i--;
	}
	printf("\nThe hcf of %d and %d is %d",m,n,p);
	return 0;
}

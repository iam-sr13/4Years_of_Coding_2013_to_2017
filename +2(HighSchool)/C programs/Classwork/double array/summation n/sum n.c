#include<stdio.h>
int main()
{
	int ipas(char*);	
	int n,sum=0,i;
	n=ipas("\nEnter the nth value for summation: ");
	for(i=1;i<=n;i++) {
		sum=sum+2*i;
	}
	printf("\nThe summation of %dth natural even nos is: %d",n,sum);
	return 0;
}

int ipas(char c[])
{
	int scan;
	printf("\n%s",c);
	scanf(" %d",&scan);
	return scan;
}

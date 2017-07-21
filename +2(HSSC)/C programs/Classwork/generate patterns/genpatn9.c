#include<stdio.h>
int pas(char c[])
{
	int n;
	printf("\n%s",c);
	scanf(" %d",&n);
	return n;
}
int main()
{
	int n,i,j,k;
	n=pas("Enter value: ");	
	k=n*(n+1)/2;	
	for(i=n;i>=1;i--) {
		for(j=1;j<=i;j++) printf(" %d",k--);
		printf("\n");		
	}
	return 0;
}

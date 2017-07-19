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
	int n,i,j;
	n=pas("Enter value: ");
	for(i=1;i<=n;i++) {
		for(j=1;j<=i;j++) printf("%d",j);
		printf("\n");		
	}
	return 0;
}

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
	int i,n;
	n=pas("Enter value: ");
	for(i=1;i<=n;i++) {
		printf("%d",i);
		printf("\n");
	}
	return 0;
}

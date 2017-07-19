#include<stdio.h>
int main()
{
	int n,i,j,k;
	printf("\nEnter value: ");
	scanf(" %d",&n);
	for(i=1;i<=n;i++) {
		for(k=n-(i-2);k<=n;k++) 
			printf(" ");
		for(j=n;j-(i-1)>=1;j--) 
			printf("*");
			printf("\n");
		}
		return 0;
	}

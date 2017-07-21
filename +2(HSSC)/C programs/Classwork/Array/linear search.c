#include<stdio.h>
int pas(char c[])
{
	int d;
	printf("\n%s",c);
	scanf(" %d",&d);
	return d;
}
int main()
{
	int i,n,x;
	n=pas("Enter the no. of elements you are going to enter: ");
	int a[n];
	printf("\nEnter the numbers:\n ");
	for (i=0;i<n;i++) 
		scanf("%d", &a[i]);
	
	x=pas("\nNow enter any no. you want to search in the array\n(if the no. is present it will be shown): ");
	for(i=0;i<n;i++)
		if(a[i]==x) {
			printf("\nThe no. %d is present at the location %d.",x,i+1);
			break;
		}
	if(n==i) printf("\nThe no. %d is absent.",x);
	return 0;
}
	
	

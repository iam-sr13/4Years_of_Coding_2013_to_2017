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
	int i,n,s;
	n=pas("Enter the no. of elements you are going to enter: ");
	int a[n];
	printf("\nEnter the numbers:\n ");
	for (i=0;i<n;i++) 
		scanf("%d", &a[i]);
		
	s=a[0];
	for(i=1;i<n;i++)
		if(s>a[i]) s=a[i];
		
	printf("\n\nThe smallest among the numbers is: %d",s);
	return 0;
}
		
		
		
	

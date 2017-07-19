#include<stdio.h>
int main()
{
	int i,n,x,pos;
	n=ipas("\nEnter the size of the array: ");
	int a[n];	
	for(i=0;i<n;i++) 
	{
		printf("\n\nEnter the %d element of the array: ",i+1);
		scanf(" %d",(a+i));
	}
	
	printf("\n\nThis is your array: ");
	for(i=0;i<n-1;i++) 
	printf("%d,",a[i]);
	
	printf("%d.",a[n-1]);
	
	x=ipas("\nenter element you want to insert: ");
	pos=ipas("\nenter the position of the no.: ");
					
	for(i=n-1;i>=pos-1;i--) 
		a[i+1]=a[i];
		a[pos-1]=x;
		n++;
	printf("\nThis is new array\n");
	for (i=0;i<n;i++)
	printf("\n %d",*(a+i));
	return 0;
}

int ipas(char c[])
{
	int scan;
	printf("\n%s",c);
	scanf(" %d",&scan);
	return scan;
}

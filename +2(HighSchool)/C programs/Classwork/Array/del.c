#include<stdio.h>
int main()
{
	int i,n,j,x;
	n=ipas("\nEnter the size of the array: ");
	int a[n];	
	for(i=0;i<n;i++) {
		printf("\n\nEnter the %d element of the array: ",i+1);
		scanf(" %d",(a+i));
	}
	printf("\n\nThis is your array: ");
	for(i=0;i<n-1;i++) printf("%d,",*(a+i));
	printf("%d.",*(a+n-1));					
	printf("\nenter element you want to del: ");
	scanf(" %d",&x);
	for(i=0;i<n;i++) {
		if(x==a[i]) {
			 for(j=i;j<n;j++) a[j]=a[j+1];
			 break;
		 }		
	}
	n--;
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

#include<stdio.h>
void scanarr(int n,int *a)
{
	int i;
	for (i=0;i<n;i++) 
		scanf("%d", &a[i]);
}
	
void linear_sort(int n,int *a)
{
	int i,j;
	for(i=0;i<n-1;i++) 
		for(j=i+1;j<n;j++) 
			if(*(a+i)>*(a+j))
		    swap((a+i),(a+j));
}
	
void swap(int *x,int *y)
{
	int t;
	t=*x;
	*x=*y;
	*y=t;
}

int pas(char c[])
{
	int d;
	printf("\n%s",c);
	scanf(" %d",&d);
	return d;
}

void dispcount(char c[],int n,int *a)
{
	int i,j,k;
	printf("\n%s",c);
	for(i=0,k=1;i<n-1;i++) { 
		for(j=i+1;j<n;j++) 
			if(*(a+i)==*(a+j)) {
				k++;
				i++;
			}
		printf("\n\n==> The number '%d' has occured '%d' times in the array.",*(a+i),k);
		k=1;
	}
}
	
int main()
{
	int n;
	n=pas("Enter the no. of elements you are going to enter: ");
	int a[n];
	printf("\nEnter the numbers:\n");
	scanarr(n,&a[0]);
	
	linear_sort(n,&a[0]);				
	
	dispcount("\nIn the array there are following elements with their respective occurunces: ",n,&a[0]);
    
	return 0;
}

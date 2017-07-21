#include<stdio.h>
void disparr(int n,int *a)
{
	int i;
	for (i=0;i<n;i++)
		printf("\n %d",*(a+i));
}

void scanarr(int n,int *a)
{
	int i;
	for (i=0;i<n;i++) 
		scanf("%d", &a[i]);
}
	
void selection_sort(int n,int *a)
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

void binsearch(int n,int x,int *a)
{
	int low,high,mid;
	for(low=0,high=n-1;low<=high;) {
		mid=(low+high)/2;
		if(*(a+mid)==x) {			
			printf("\nThe no. %d is present at the location %d.",x,mid+1);
			break;
		}
		else if(x>*(a+mid))
			low=mid+1;
			else 
			high=mid-1;
	}
	if(low>high) printf("\nNOT FOUND!!");
}

int main()
{
	int n,x;
	n=pas("Enter the no. of elements you are going to enter: ");
	int a[n];
	printf("\nEnter the numbers:\n");
	scanarr(n,&a[0]);
	
	selection_sort(n,&a[0]);
	
	printf("\nThe sorted array is as follows: ");
	
	disparr(n,&a[0]);
			
	x=pas("\nNow enter any no. you want to search in the array\n(if the no. is present it will be shown):");
	
	binsearch(n,x,&a[0]);
    
	return 0;
}

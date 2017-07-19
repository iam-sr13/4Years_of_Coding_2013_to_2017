//Program for Bubble Sort, linear and binary search....
#include<stdio.h>

void getdata(int*,int),putdata(int*,int),bubsort(int*,int),linsearch(int*,int,int),binsearch(int*,int,int);

int main()
{
	int n,c,e;	
	
	printf("\nPlease enter the size of your list: ");
	scanf("%d",&n);
	
	int a[n];
	
	getdata(a,n);
	printf("\nBefore sorting,");
	putdata(a,n);
	printf("\n\nAfter sorting,");
	bubsort(a,n);
	putdata(a,n);	
	
	printf("\n\nEnter any number you want to search for in your list: ");
	scanf("%d",&e);
	printf("\nNow choose your method of searching (1 or 2):\n 1) Linear Search\n 2) Binary Search\n\nYour Choice: ");
	scanf("%d",&c);
	
	if(c==1) linsearch(a,n,e);
	else binsearch(a,n,e);
	
	return 0;
}

void linsearch(int* a,int n,int e)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]==e) {
			printf("\n%d is Present in your list.",e);
			return;
		}
	}
	printf("\n%d is Absent in your list.",e);	
}

void binsearch(int* a,int n,int e)
{
	int l=0,h=n-1,m=(l+h)/2;
	
	for(;l<=h;m=(l+h)/2)
	{
		if(a[m]==e) {
			printf("\n%d is Present in your list.",e);
			return;
		}
		else if(a[m]>e) h=m-1;
		else l=m+1;		
	}
	printf("\n%d is Absent in your list.",e);
}

void getdata(int* a,int n)
{	
	int i;
	printf("\nPlease enter the elements of your list:\n");
	for(i=0;i<n;i++) scanf("%d",a+i);	
}

void putdata(int* a,int n)
{
	int i;
	printf("\nThis is your list:\n");
	for(i=0;i<n;i++) {
		printf("%d",a[i]);
		if(i<n-1) printf(", ");
		else printf(".");
	}
}

void bubsort(int* a,int n)
{
	int i,j,t;
	
	for(i=1;i<n;i++)
		for(j=0;j<n-i;j++)
			if(a[j]>a[j+1])
				{
					t=a[j];
					a[j]=a[j+1];
					a[j+1]=t;
				}					
}

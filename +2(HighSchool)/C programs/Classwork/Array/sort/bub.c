#include<stdio.h>
int main()
{
	int ipas(char*);
	void bubsort(int*, int*);	
	int n,i;	
	n=ipas("\nEnter the size of the array: ");
	int a[n];
	for(i=0;i<n;i++) {
	printf("\n\nEnter the %d element of the array: ",i+1);
	scanf(" %d",(a+i));
	}
	printf("\n\nThis is your array: ");
	for(i=0;i<n-1;i++) printf("%d,",*(a+i));
	printf("%d.",*(a+n-1));
	bubsort(a,&n);
	printf("\nThis is the sorted array: ");
	for(i=0;i<n;i++) printf("\n%d.",*(a+i));
	return 0;			
}

void bubsort(int *a, int *n)
{
	void swap(int*, int*);
	int i,j;
	for(i=1;i<=*n-1;i++) for(j=0;j<=*n-i-1;j++) if(*(a+j)>*(a+j+1)) swap((a+j),(a+j+1));
}

int ipas(char c[])
{
	int scan;
	printf("\n%s",c);
	scanf(" %d",&scan);
	return scan;
}

int cpas(char c[])
{
	char scan;
	printf("\n%s",c);
	scanf(" %c",&scan);
	return scan;
}	

void swap(int *x,int *y)
{
	int t;
	t=*x;
	*x=*y;
	*y=t;
}

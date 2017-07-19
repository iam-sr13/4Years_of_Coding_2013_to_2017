#include<stdio.h>
int main()
{
	int ipas(char*);
	void bubsort(int*, int*);	
	int m,n,i,j,r;
	printf("\nPlease Enter the following details for merging the arrays: \n");
	m=ipas("\nEnter the size of the array 1: ");
	int a[m];
	for(i=0;i<m;i++) {
	printf("\n\nEnter the %d element of the array 1: ",i+1);
	scanf(" %d",(a+i));
	}
	bubsort(a,&m);
	n=ipas("\nEnter the size of the array 2: ");
	int b[n];
	for(i=0;i<n;i++) {
	printf("\n\nEnter the %d element of the array 2: ",i+1);
	scanf(" %d",(b+i));
	}
	bubsort(b,&n);
	int k=m+n;
	int c[k];
	
	for(i=0,j=0,r=0;i<=m-1 && j<=n-1;) {
		 if(*(a+i)<*(b+j)) c[r++]=a[i++];
			else c[r++]=b[j++];
		}
	if(i==m) for(;j<=n-1;j++) c[r++]=b[j];
	if(j==n) for(;i<=m-1;i++) c[r++]=a[i];
	
	
	printf("\nThis is the merged array: ");
	for(i=0;i<k;i++) printf("\n%d.",c[i]);	
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

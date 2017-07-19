#include<stdio.h>
int main()
{
	int n,i,a[n];
	arracc(a,&n);
	selsort(a,n);
	printf("\n\nThis is your sorted array: ");
	for(i=0;i<n-1;i++) printf("%d,",*(a+i));
	printf("%d.",*(a+n-1));
	return 0;
}
void selsort(int *a,int n)
{	
	int i,j,k,sml,pos;
	for(i=0;i<n-1;i++) {
		pos=i+1;
		sml=*(a+pos);		
		for(j=i+2;j<n;j++) 	if(*(a+j)<sml) { sml=*(a+j); pos=j;}
		if(*(a+i)>*(a+pos)) {
			k=*(a+i);
			*(a+i)=*(a+pos);
			*(a+pos)=k;
		}
	}
}

int ipas(char c[])
{
	int scan;
	printf("\n%s",c);
	scanf(" %d",&scan);
	return (scan);
}
void arracc(int *a,int *n)
{
	int i;
	*n=ipas("\nEnter the size of the array: ");	
	for(i=0;i<*n;i++) {
		printf("\n\nEnter the %d element of the array: ",i+1);
		scanf(" %d",(a+i));
	}
	printf("\n\nThis is your array: ");
	for(i=0;i<*n-1;i++) printf("%d,",*(a+i));
	printf("%d.",*(a+*n-1));
}


	
						
	


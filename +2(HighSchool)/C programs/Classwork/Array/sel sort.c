#include<stdio.h>
int main()
{
	int i,n,j,k,sml,pos;
	n=ipas("\nEnter the size of the array: ");
	int a[n];	
	for(i=0;i<n;i++) {
		printf("\n\nEnter the %d element of the array: ",i+1);
		scanf(" %d",(a+i));
	}
	printf("\n\nThis is your array: ");
	for(i=0;i<n-1;i++) printf("%d,",a[i]);
	printf("%d.",a[n-1]);
	
	for(i=0;i<n-1;i++) {
		pos=i+1;
		sml=a[pos];		
		for(j=i+2;j<n;j++) 	if(a[j]<sml) { sml=a[j]; pos=j;}
		if(a[i]>a[pos]) {
			k=a[i];
			a[i]=a[pos];
			a[pos]=k;
		}
	}
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



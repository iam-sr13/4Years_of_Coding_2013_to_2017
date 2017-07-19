#include<stdio.h>
int main()
{
	int ipas(char*);
	
	int r,c,i,j,x;
	r=ipas("\nEnter the no. of rows for the matrix: ");
	c=ipas("\nEnter the no. of columns for the matrix: ");
	int a[r][c],b[c][r];
	printf("\nEnter the elements of the matrix: \n");	
	for(i=0;i<=r-1;i++) 
		for(j=0;j<=c-1;j++)
			scanf(" %d",&a[i][j]);
	printf("\nThe elements of the matrix are: \n");	
	for(i=0;i<=r-1;i++) {
		for(j=0;j<=c-1;j++)
			printf(" %d",a[i][j]);
		printf("\n");
	}
	for(i=0;i<=r-1;i++) 
		for(j=0;j<=c-1;j++)
			b[j][i]=a[i][j];
	printf("\nThe elements of the transpose are: \n");	
	for(i=0;i<=c-1;i++) {
		for(j=0;j<=r-1;j++)
			printf(" %d",b[i][j]);
		printf("\n");
	}
	for(i=0;i<=r-1;i++) 
		for(j=0;j<=c-1;j++)
			if(a[i][j]!=a[j][i]) {x=0;break;}
	if(x) printf("\nThe matrix is Symmetric!");
	else printf("\nThe matrix is Not Symmetric!");
	
	return 0;
}

int ipas(char c[])
{
	int scan;
	printf("\n%s",c);
	scanf(" %d",&scan);
	return scan;
}


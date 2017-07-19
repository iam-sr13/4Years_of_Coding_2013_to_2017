#include<stdio.h>
int main()
{
	int ipas(char*);
	void scan2arr(int,int,int*);
	void disp2arr(int,int,int*);
	int r,c,sumr,sumc,i,j;
	r=ipas("\nEnter the no. of rows for the matrix: ");
	c=ipas("\nEnter the no. of columns for the matrix: ");
	int a[r][c];
	printf("\nEnter the elements of the matrix:\n");
	
	scan2arr(r,c,&a[0][0]);
	disp2arr(r,c,&a[0][0]);
	
	for(i=0;i<=r-1;i++){
		sumr=0;
		for(j=0;j<=c-1;j++)
		sumr=sumr+a[i][j];
		printf("\nThe sum of %d row is : %d",i+1,sumr);
	}
	for(j=0;j<=c-1;j++){
		sumc=0;
		for(i=0;i<=r-1;i++)
		sumc=sumc+a[i][j];
		printf("\nThe sum of %d column is : %d",j+1,sumc);
	}
	return 0;
}

int ipas(char c[])
{
	int scan;
	printf("\n%s",c);
	scanf(" %d",&scan);
	return scan;
}

void scan2arr(int r,int c,int *a)
{
	int i,j;
	for(i=0;i<=r-1;i++) 
		for(j=0;j<=c-1;j++)
			scanf(" %d",(a+i*c+j));
}
void disp2arr(int r,int c,int *a)
{	
	int i,j;
	printf("\n");
	for(i=0;i<=r-1;i++) {
		for(j=0;j<=c-1;j++)
			printf(" %d",*(a+i*c+j));
		printf("\n");
	}
}

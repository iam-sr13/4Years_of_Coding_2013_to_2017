#include<stdio.h>
int main()
{
	int i,j,a[4][4];
	printf("Enter the elements of the matrix\n");
	for(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}

	printf("\nThe entered matrix is\n");
	for(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j++)
		{
			printf("%d\t",a[i][j]);
			
		}
		printf("\n");
	}
	
	printf("\nThe transpose of the matrix is\n");
	for(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j++)
		{
			printf("%d\t",a[j][i]);
			
		}
		printf("\n");
	}
	return 0;
}


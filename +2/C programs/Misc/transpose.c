#include<stdio.h>
int main()
{
	int i,j,a[4][4],b[4][4];
	;
	printf("Enter the elements of the matrix\n");
	for(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j++)
		{
			b[j][i]=a[i][j];
		}
	}
	for(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j++)
		{
			printf("%d",b[i][j]);
		}
		printf("\n");
	}
		return 0;
	}

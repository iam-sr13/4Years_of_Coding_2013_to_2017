#include<stdio.h>
main()
{
	int a[3][3],b,c,d[3][3],sum,e[3][3],f;

	printf("Enter the elements of Matrix 1\n");
	
	for(b=0;b<=2;b++)
	{
		for(c=0;c<=2;c++)
		{
			scanf("%d",&a[b][c]);
		}
	}

	printf("Enter the elements of Matrix 2\n");
	
	for(b=0;b<=2;b++)
	{
		for(c=0;c<=2;c++)
		{
			scanf("%d",&d[b][c]);
		}
	}

	printf("The elements of matrix 1 are\n");

	for(b=0;b<=2;b++)
	{
		for(c=0;c<=2;c++)
		{
			printf("%d\t",a[b][c]);
		}
		printf("\n");
	}

	printf("The elements of matrix 2 are\n");

	for(b=0;b<=2;b++)
	{
		for(c=0;c<=2;c++)
		{
			printf("%d\t",d[b][c]);
		}
		printf("\n");
	}

	for(b=0;b<=2;b++)
	{
		for(c=0;c<=2;c++)
		{
			sum=0;
			for(f=0;f<=2;f++)
			{
				sum=sum+a[b][f]*d[f][c];
				e[b][c]=sum;
			}
		}
	}

	printf("The product of the matrices is\n");
	for(b=0;b<=2;b++)
	{
		for(c=0;c<=2;c++)
		{
			printf("%d\t",e[b][c]);
		}
		printf("\n");
	}
}









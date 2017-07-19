#include<stdio.h>
main()
{
	int a[6][6],d[6][6],b,c;

	printf("Enter the elements of matrix 1\n");
	
	for(b=0;b<=5;b++)
	{
		for(c=0;c<=5;c++)
		{
			scanf("%d\t",&a[b][c]);
		}
	}


	printf("Enter the elements of matrix 2\n");
	
	for(b=0;b<=5;b++)
	{
		for(c=0;c<=5;c++)
		{
			scanf("%d\t",&d[b][c]);
		}
	}

	printf("\nThe elements of matrix 1 are:\n");

    for(b=0;b<=5;b++)
	{
		for(c=0;c<=5;c++)
		{
			printf("%d\t",a[b][c]);
		}
		printf("\n");
	}

	printf("\nThe elements of matrix 2 are:\n");
	
	for(b=0;b<=5;b++)
	{
		for(c=0;c<=5;c++)
		{
			printf("%d\t",d[b][c]);
		}
		printf("\n");
	}


	printf("\nSum:\n");
	
	for(b=0;b<=5;b++)
	{
		for(c=0;c<=5;c++)
		{
			printf("%d\t",a[b][c]+d[b][c]);
		}
		printf("\n");
	}
}

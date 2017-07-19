#include<stdio.h>
main()
{
	int a[4][4],b,c;
	int least;
	least=a[1][1];
	int arr[4][4];

	printf("Enter the elements of the matrix\n");

	for(b=0;b<=3;b++)
	{
		for(c=0;c<=3;c++)
		{
			scanf("%d",&a[b][c]);
		}
	}

	printf("\nThe original matrix is\n");

	for(b=0;b<=3;b++)
	{
		for(c=0;c<=3;c++)
		{
			printf("%d\t",a[b][c]);
		}
		printf("\n");
	}

	if(a[b][c]>least)
	{
		temp=a[b][c];
		a[b][c]=least;
		least=temp;
	}

	arr[b][c]=


		



	

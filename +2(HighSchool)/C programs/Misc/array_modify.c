#include<stdio.h>
int modify(int *arr,int n);
main()
{
	int i;
	int array[]={1,2,3,4,5,6,7,8,9,10};

	printf("The array is\n");
	for(i=0;i<=9;i++)
	{
		printf("%d\t",array[i]);
	}

	modify(array,10);
	printf("\nThe modified array is\n");
	for(i=0;i<=9;i++)
	{
		printf("%d\t",array[i]);
	}
}
	
	modify(int *arr,int n)
	{
		int i;
		for(i=0;i<=9;i++)
		{
			*arr*=3;
			arr++;
		}
	}



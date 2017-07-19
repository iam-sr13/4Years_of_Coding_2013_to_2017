#include<stdio.h>
main()
{
	int a[5][5]={
					{2,6,4,8,13},
					{5,1,23,16,10},
					{4,8,5,2,12},
					{0,25,13,17,19},
					{7,19,6,20,23}
				};
	int i,j,big=a[1][1];
	for(i=0;i<=4;i++)
	{
		for(j=0;j<=4;j++)
		{
			printf("%d\t",a[i][j]);
			if(a[i][j]>=big)
			{
				big=a[i][j];
			}
		}
		printf("\n");
	}

	printf("\nThe biggest number is %d\n",big);
}
		   

					

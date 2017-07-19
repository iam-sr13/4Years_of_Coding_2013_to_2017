 /* SELECTION SORT METHOD */
#include<stdio.h>
main()
{
	int i[5]={44,33,55,22,11};
	int n=0,m,temp;
	/*for(n=0;n<=4;n++)
	{
		printf("Enter the numbers\n");
		scanf("%d",&i[n]);
	}*/

	for(m=0;m<=4;m++)
	{
		for(n=m;n<=4;n++)
		{
			if(i[m]>i[n])
			{
				temp=i[m];
				i[m]=i[n];
				i[n]=temp;
			}
		}
	}


     for(n=0;n<=4;n++)
	{
		printf("\n%d\n",i[n]);
	}
}


#include<stdio.h>
#define LENGTH 5 
main()
{
	int i[5]={44,33,55,22,11};
	int temp,n,m;

	for(m=0;m<=(LENGTH-1);m++)
	{
		for(n=0;n<=(LENGTH-1-m);n++)
		{
			if(i[n]>i[n+1])
			{
				temp=i[n];
				i[n]=i[n+1];
				i[n+1]=temp;
			}
		}
	}	

	for(n=0;n<=(LENGTH-1);n++)
	{
		printf("%d\n",i[n]);
	}
}



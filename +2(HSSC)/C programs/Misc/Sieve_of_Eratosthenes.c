#include<stdio.h>
main()
{
	int i[100],n,x,y,a;

	for(n=0;n<=99;n++)
	{
		i[n]=n+1;
		printf("%d\t",i[n]);         		
	}
		
	for(n=1;n<=99;n++)
	{
		if(i[n]!=0)
		{
			for(x=1;x<=100;x++)
			{
				a=x*i[n];
				a=0;
				i[n]=x*i[n];
				/*a=0;
				i[a]=x*i[n];
				n=a;
				/*i[n*x]=y;*/
				/*i[n]=0;*/
				i[n]=i[a];
				
			}
		}
	}
	for(n=0;n<=99;n++)
	{
		if(i[n]!=0)
		{
			printf("%d\t",i[n]);
		}
	}
}




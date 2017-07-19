#include<stdio.h>
main()
{
	int i[5]={44,33,55,22,11};
	int n,temp,m;

	for(n=0;n<=0;n++)
	{
		for(m=0;m<=4;m++)
		{
			if(i[m]<i[n])
			{
				temp=i[n];
				i[n]=i[m];
				i[m]=temp;//continue;  
			} 
		}//break;
	}
	
	for(n=0;n<=4;n++)
	{
		printf("%d\n",i[n]);
	}
}





			



			
























































































































































































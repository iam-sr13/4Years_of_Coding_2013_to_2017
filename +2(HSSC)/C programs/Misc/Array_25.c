/* FINDING THE TOTAL NUMBER OF ODD,EVEN,POSITIVE & NEGATIVE NUMBERS IN AN ARRAY */

#include<stdio.h>
main()
{
	int i[5];
	int n=0,x;
	int a=0,b=0,c=0,d=0;
	for(x=0;x<=4;x++)
	{       
		printf("Enter a number\n");
		scanf("%d",&i[n]);
		n++;
	}
	for(n=0;n<=4;n++)
	{
		if(i[n]>=0)
			{
			a++;
			}
	    if(i[n]<0)
			{
			b++;
			}
		if(i[n]%2==0)
			{
			c++;
			}
		if(i[n]%2==1)
			{
			d++;
			}
	}
	printf("Number of positive numbers=%d\n",a);
	printf("Number of negative numbers=%d\n",b);
	printf("Number of even numbers=%d\n",c);
	printf("Number of odd numbers=%d\n",d);
}
		

		


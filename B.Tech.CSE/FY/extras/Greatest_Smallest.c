#include<stdio.h>
main()
{
	int A[30];
	int greatest=0;
	int smallest=0;
	printf("Enter the 10 numbers\n");
	int a;int i; 
	for(a=0;a<10;a++)
		scanf("%d",&A[a]);
	greatest=A[0];
	smallest=A[0];
	for(i=0;i<10;i++)
		{	if(greatest<A[i])
			greatest=A[i];
		}
	printf("The greatest number is %d\n",greatest);
	for(i=0;i<10;i++)
		{	if(smallest>A[i])
			smallest=A[i];
		}
	printf("The smallest number is %d\n",smallest);
}
		

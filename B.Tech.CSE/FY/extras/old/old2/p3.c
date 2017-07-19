#include<stdio.h>

int main()
{
	int a[5],i;
	
	printf("\nEnter any 5 integers:\n");
	for(i=0;i<5;i++)
		scanf(" %d",&a[i]);
	printf("\nThe numbers and their addresses are:\n");
	for(i=0;i<5;i++)
		printf("The no. %d is stored at address %p.\n",a[i],&a[i]);

	return 0;
}
		

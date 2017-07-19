#include<stdio.h>
int main()
{
	int n,i=1;
	printf("\nEnter any value for displaying numbers:");
	scanf("%d",&n);
	printf("\nThe first n natural nos are:");
	do {
		printf("\n%d",i);
		i++;
	}
	while(i<=n);
	return 0;
}
		

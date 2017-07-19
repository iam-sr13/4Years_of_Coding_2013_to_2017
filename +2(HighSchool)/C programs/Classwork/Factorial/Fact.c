#include<stdio.h>
int main()
{
	float n,i=2,p=1;
	printf("\nEnter the value for determining its factorial:");
	scanf("%f",&n);
	while(i<=n)
	{
		p=p*i;
		i++;
	}
	printf("\nThe %.0f!=%.0f.\n",n,p);
	return 0;
}

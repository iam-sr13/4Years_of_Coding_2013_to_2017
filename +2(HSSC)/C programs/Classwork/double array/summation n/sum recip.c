#include<stdio.h>
#include<math.h>
int main()
{
	int ipas(char*);
	float sum=0;	
	int n,i;
	n=ipas("\nEnter the nth value for summation: ");
	for(i=1;i<=n;i++) {
		sum=sum+pow(2*i-1,-2);
	}
	printf("\nThe summation of %dth reciprocal of sqr of odd nos is: %f",n,sum);
	
	return 0;
}
int ipas(char c[])
{
	int scan;
	printf("\n%s",c);
	scanf(" %d",&scan);
	return scan;
}

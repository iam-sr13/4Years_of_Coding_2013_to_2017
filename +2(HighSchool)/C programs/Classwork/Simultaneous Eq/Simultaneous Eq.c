#include<stdio.h>
int main()
{
	int a1,b1,c1,a2,b2,c2,n;
	float x,y;
	printf ("\n Enter the values of the variables say a1,b1,c1 for eq1 and a2,b2,c2 for eq2 \n resp:");
	scanf ("%d %d %d %d %d %d", &a1,&b1,&c1,&a2,&b2,&c2);
	n=(a2*b1)-(a1*b2);
	if (n==0){
		printf("\n The solution is not defined since y=n/0 where n is some value.......\n");
		return 0;
	}
	y=((a2*c1)-(a1*c2))/n;	
	x=(c1-(b1*y))/a1;
	printf ("The solution for the equation, x=%.2f y=%.2f\n",x,y);
	return 0;
}

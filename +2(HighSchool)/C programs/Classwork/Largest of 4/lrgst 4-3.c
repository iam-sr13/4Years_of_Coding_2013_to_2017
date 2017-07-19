#include<stdio.h>
int main()
{
	int a,b,c,d;
	printf("\nEnter any 4 numbers seperated by space:");
	scanf("%d %d %d %d",&a,&b,&c,&d);
	if (a>b && a>c && a>d) printf("\nThe largest among all is %d\n",a);
	if (b>a && b>c && b>d) printf("\nThe largest among all is %d\n",b);
	if (c>b && c>a && c>d) printf("\nThe largest among all is %d\n",c);
	if (d>b && d>a && d>c) printf("\nThe largest among all is %d\n",d);
	return 0;
}

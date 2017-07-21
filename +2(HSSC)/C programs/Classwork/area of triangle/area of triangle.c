#include<stdio.h>
int main()
{
	int b,h;
	float a;
	printf("enter the base and height of triangle respectively:");
	scanf("%d %d",&b,&h);
	a=0.5*b*h;
	printf("the area is %.2f",a);
	return 0;
}

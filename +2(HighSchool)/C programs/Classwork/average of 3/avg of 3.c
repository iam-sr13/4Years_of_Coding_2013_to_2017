#include<stdio.h>
int main()
{
	int a,b,c;
	float avg;
	printf("\n enter any 3 integers seperated by blank space:");
	scanf("%d %d %d",&a,&b,&c);
	avg=(a+b+c)/3.0;
	printf("\n the average is %.2f",avg);
	return 0;
}

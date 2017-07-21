#include<stdio.h>
int main()
{
	int a,b,c;
	printf("\nEnter the values of sides of triangle:\n");
	scanf("%d %d %d",&a,&b,&c);
	if (a+b<=c || a+c<=b || b+c<=a) {
		printf("\nInvalid Triangle!!\n");
		printf("\nProgram will now exit.....\n");
	}
	else if (a==b && b==c && a==c) printf("\nEquilateral Triangle\n");
	else if (a==b || b==c || a==c) printf("\nIsosceles Triangle\n");
	else printf("\nScalene Triangle\n");
	return 0;	
}
	

#include<stdio.h>
int main()
{
	int a,b,c,d,l;
	printf("\nEnter any 4 numbers seperated by space:");
	scanf("%d %d %d %d",&a,&b,&c,&d);
	l=a;
	if (l<b) l=b;
	if (l<c) l=c;
	if (l<d) l=d;
	printf("\nThe largest of all is %d",l);
	return 0;
}

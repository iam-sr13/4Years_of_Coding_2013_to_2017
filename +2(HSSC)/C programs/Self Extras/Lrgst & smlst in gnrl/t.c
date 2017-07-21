#include<stdio.h>
int main()
{
	int a=0,l=0;
	printf("\nEnter Values:\n");
	do {
		scanf("%d",&a);
		if(a=='*') break;
		if(l<a) l=a;
		fflush(stdin);
		a='*';
	}
	while (l!=0);
	printf("\nThe largest is %d\n",l);
	return 0;
}
		
		
		

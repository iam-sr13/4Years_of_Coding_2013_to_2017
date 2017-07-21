#include<stdio.h>
int main()
{
	int a=0,s=0;
	printf("\nEnter Values:\n");
	do {
		scanf("%d",&a);
		if(a=='*') break;
		if(s==0) s=a;		
		if(s>a) s=a;		
		fflush(stdin);
		a='*';
	}
	while (s!=0);
	printf("\nThe smallest is %d\n",s);
	return 0;
}

#include<stdio.h>
int main()
{
	int a,b,c;
	printf("\n enter any 3 integers seperated by a blank space:");
	scanf("%d %d %d",&a,&b,&c);
	if(a>b){
		if(a>c) printf("\nThe largest among three is %d",a);
		else printf("\nThe largest among three is %d",c);
	}
	else {
		if(b>c) printf("\nThe largest among three is %d",b);
		else printf("\nThe largest among three is %d",c);
	}
	return 0;
}
	

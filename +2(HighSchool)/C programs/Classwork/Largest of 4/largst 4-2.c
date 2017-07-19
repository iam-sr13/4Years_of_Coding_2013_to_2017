#include<stdio.h>
int main()
{
	int a,b,c,d;
	printf("\nEnter any 4 numbers seperated by space:");
	scanf("%d %d %d %d",&a,&b,&c,&d);
	if (a>b) {
		if (a>c) {
			if (a>d) printf("\nThe largest of all is '%d'",a);
			else     printf("\nThe largest of all is '%d'",d);
		}
		else {
			if (c>d) printf("\nThe largest of all is '%d'",c);
			else     printf("\nThe largest of all is '%d'",d);
		}
	}
	else {
		if (b>c) {
			if (b>d) printf("\nThe largest of all is '%d'",b);
			else     printf("\nThe largest of all is '%d'",d);
		}
		else {
			if (c>d) printf("\nThe largest of all is '%d'",c);
			else     printf("\nThe largest of all is '%d'",d);
		}
	}
	return 0;
}
			 

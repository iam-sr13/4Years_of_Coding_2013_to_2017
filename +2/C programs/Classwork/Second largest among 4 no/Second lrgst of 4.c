#include<stdio.h>
int main()
{
	int a,b,c,d,l,sl;
	printf("\nEnter any 4 numbers seperated by space:");
	scanf("%d %d %d %d",&a,&b,&c,&d);
	if (a>b) {
		l=a;
		sl=b;
	}
	else {
		l=b;
		sl=a;
	}
	if (c>l) {
		sl=l;
		l=c;
	}
	else if (c>sl) sl=c;
	if (d>l) {
		sl=l;
		l=d;
	}
	else if (d>sl) sl=d;
	printf("\nThe second largest among these is '%d'",sl);
	return 0;
}
		
	

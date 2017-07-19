#include<stdio.h>
int main()
{
	int n,c;
	float f1,f2,f3;
	printf("\nEnter the no. of terms for Fibs series:");
	scanf("%d",&n);
	f1=0;f2=1;c=1;
	if (n==1) printf("\n%.0f",f1);
	if (n==2) printf("\n%.0f\n%.0f",f1,f2);
	if (n>2) {
		printf("\n%.0f\n%.0f",f1,f2);
		while (c<=n-2) {		
			f3=f1+f2;
			printf("\n%.0f",f3);
			c++;
			f1=f2;
			f2=f3;
		}
	}
	return 0;
}

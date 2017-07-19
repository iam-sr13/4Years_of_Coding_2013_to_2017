#include<stdio.h>
int main()
{
	int n1,n2,c;
	float f1,f2,f3;
	printf("\nEnter the range (e.g. 20 to 30) from which you want to \ndisplay the terms of the Fibbonacci series:");
	scanf("%d to %d",&n1,&n2);
	f1=0;f2=1;c=1;
	if (n1==1) printf("\n%.0f",f1);
	if (n1==2 || n2==2) printf("\n%.0f",f2);	
	if(n1==1 && n2>2) {
		printf("\n%.0f",f2);
		while (c<=n2-2) {		
			f3=f1+f2;
			printf("\n%.0f",f3);
			c++;
			f1=f2;
			f2=f3;
		}
		return 0;
	}
	if (n1==2 && n2>2) {		
		while (c<=n2-2) {		
			f3=f1+f2;
			printf("\n%.0f",f3);
			c++;
			f1=f2;
			f2=f3;
		}
		return 0;
	}
	if (n1>2 && n2>2) {
		while (c<=n2-2) {		
			f3=f1+f2;
			if(n1<=c+2) printf("\n%.0f",f3);
			c++;
			f1=f2;
			f2=f3;
		}		
	}
	return 0;	
}

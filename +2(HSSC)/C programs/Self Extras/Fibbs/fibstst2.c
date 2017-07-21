#include<stdio.h>
int main()
{
	int n1,n2,c=1;
	float f1=0,f2=1,f3=1;
	printf("\nEnter the range (e.g. 20 to 30) from which you want to \ndisplay the values of the Fibbonacci series in order:");
	scanf("%d to %d",&n1,&n2);	
	if (n1==0) printf("\n%.0f",f1);
	if (n1==1 || n2==1) printf("\n%.0f\n%.0f",f2,f2);	
	if(n1==0 && n2>1) {
		printf("\n%.0f",f2);
		while (n2>f3) {		
			f3=f1+f2;
			if(f3<=n2) printf("\n%.0f",f3);
			f1=f2;
			f2=f3;
		}
		return 0;
	}
	if (n1==1 && n2>1) {		
		while (n2>f3) {		
			f3=f1+f2;
			if(f3<=n2 && f3>n1) printf("\n%.0f",f3);
			f1=f2;
			f2=f3;
		}
		return 0;
	}
	if (n1>1 && n2>1) {
		while (n2>f3) {		
			f3=f1+f2;			
			if(f3<=n2 && f3>=n1) {
				printf("\n%.0f",f3);
				c++;
			}			
			f1=f2;
			f2=f3;			
		}
	}
	if(f3>n2 && c==1) printf("\nThis values does not exist in The FIBBONACCI Series!!\n");			
	return 0;		
}

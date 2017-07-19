#include<stdio.h>
int main()
{
	int n,c=1,i=2;
	printf("\nEnter value: ");
	scanf(" %d",&n);
	while(n>1 && c) {
		n=n/i;
		if((n%i)!=0) {
			printf("\nINVALID");
			c=0;
		}
		if(n==1) break;
		i++;
	}
	if(c) printf("\nThe inverse factorial is %d.",i);
	return 0;
}
		
	

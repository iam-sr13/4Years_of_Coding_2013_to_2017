#include<stdio.h>
int main()
{
	int n,c=1,i=2;
	printf("\nEnter value: ");
	scanf(" %d",&n);
	while(n>1 && c) {		
		if((n%i)!=0) {
			printf("\nINVALID");
			c=0;
		}
		n=n/i;
		i++;
	}
	if(c) printf("\nThe inverse factorial is %d.",i-1);
	return 0;
}
		
	

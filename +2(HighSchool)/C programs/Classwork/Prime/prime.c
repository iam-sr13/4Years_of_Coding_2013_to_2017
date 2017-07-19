#include<stdio.h>
#include<math.h>
int main()
{
	int n,i=2,c=1;
	printf("\nEnter any number: ");
	scanf(" %d",&n);
	while (i<=sqrt(n) && c) {
		if(n%i==0) {
			printf("\nThe no. is Composite.");
			c=0;
		}
		i++;
	}
	if(c) printf("\nThe no. is Prime.");
	return 0;
}
		

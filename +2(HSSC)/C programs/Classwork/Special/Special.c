#include<stdio.h>
int main()
{
	int n,d,s,p,i,x;
	printf("\nEnter any number: ");
	scanf(" %d",&n);
	x=n;
	for(s=0;n>0;) {
		d=n%10;
		for(p=1,i=1;i<=d;i++) {p*=i;}
		s+=p;
		n/=10;
	}
	if(s==x) printf("\nThe no. is Special.");
	else printf("\nThe no. is not special.");
	return 0;
}
		
			

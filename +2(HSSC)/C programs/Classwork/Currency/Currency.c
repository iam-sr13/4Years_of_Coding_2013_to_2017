#include<stdio.h>
int main()
{
	int n,th=0,fh=0,h=0,ff=0,tw=0,tn=0,fv=0,two=0,one=0;
	printf("\nEnter the value of money for determining The min. no. of notes for it:");
	scanf("%d",&n);
	th=n/1000;if(th>0) printf("\nThousand rupee notes=%d",th);
	n=n%1000;
	fh=n/500;if(fh>0) printf("\nFive Hundred rupee notes=%d",fh);
	n=n%500;
	h=n/100;if(h>0) printf("\nHundred rupee notes=%d",h);
	n=n%100;
	ff=n/50;if(ff>0) printf("\nFifty rupee notes=%d",ff);
	n=n%50;
	tw=n/20;if(tw>0) printf("\nTwenty rupee notes=%d",tw);
	n=n%20;
	tn=n/10;if(tn>0) printf("\nTen rupee notes=%d",tn);
	n=n%10;
	fv=n/5;if(fv>0) printf("\nFive rupee notes=%d",fv);
	n=n%5;
	two=n/2;if(two>0) printf("\nTwo rupee coins=%d",two);
	n=n%2;
	one=n/1;if(one>0) printf("\nOne rupee coins=%d",one);
	printf("\nTotal no. of indvidual Currency Required=%d\n",th+fh+h+ff+tw+tn+fv+two+one);
	return 0;
}

	
	
	

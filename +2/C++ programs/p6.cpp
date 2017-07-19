#include<iostream>
#include<string.h>
using namespace std;

void scan2arr(int r,int c,int **a)
	{
		int i,j;
		for(i=0;i<=r-1;i++) 
			for(j=0;j<=c-1;j++)
				scanf(" %d",(a[i]+j));
	}
	void disp2arr(int r,int c,int **a)
	{	
		int i,j;
		printf("\n");
		for(i=0;i<=r-1;i++) {
			for(j=0;j<=c-1;j++)
				printf(" %d",*(a[i]+j));
			printf("\n");
		}
	}

int main()
{
	int **a,**t,m,n,i,j;
		cout<<"\nPlease enter the no. of rows and columns required for your matrix: ";
		cin>>m>>n;		
	    a=new int* [m];
	    for(i=0;i<m;i++) a[i]=new int[n];
		t=new int* [n];
		for(i=0;i<n;i++) t[i]=new int[m];
		cout<<"\nPlease enter the elements of your matrix:\n";
		scan2arr(m,n,a);
		for(i=0;i<m;i++) for(j=0;j<n;j++) *(t[j]+i)=*(a[i]+j);
		cout<<"\nThis is your "<<m<<" x "<<n<<" matrix :\n";
		disp2arr(m,n,a);
		cout<<"\nAnd this is its transpose:\n";
		disp2arr(n,m,t);
	
	
	return 0;
}

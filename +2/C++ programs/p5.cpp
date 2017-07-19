#include<iostream>
#include<malloc.h>
#include<string.h>
using namespace std;
void scan2arr(int r,int c,int *a)
{
	int i,j;
	for(i=0;i<=r-1;i++) 
		for(j=0;j<=c-1;j++)
			scanf(" %d",(a+i*c+j));
}
void disp2arr(int r,int c,int *a)
{	
	int i,j;
	printf("\n");
	for(i=0;i<=r-1;i++) {
		for(j=0;j<=c-1;j++)
			printf(" %d",*(a+i*c+j));
		printf("\n");
	}
}
int main()
{
	int *a;
	a=new int [3];
	scan2arr(3,4,a);
	disp2arr(3,4,a);
	return 0;
}



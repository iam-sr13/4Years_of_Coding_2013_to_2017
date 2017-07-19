#include<stdio.h>

int main()
{
	char a='c';
	int i=13;
	float f=13.43;
	double d=53.1997;

	printf("\nThe values are:\na=%c\ni=%d\nf=%f\nd=%g\n",a,i,f,d);
	printf("\nAnd their sizes are:\nchar = %ld\nint = %ld\nfloat = %ld\ndouble = %ld\n",sizeof(char),sizeof(int),sizeof(float),sizeof(double));

	return 0;
}  
  	
 


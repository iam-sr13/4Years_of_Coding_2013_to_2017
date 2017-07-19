/*This program displays the sizes of different data types in c*/
//---By Shriraj.

#include<stdio.h>
int main()
{
	char c='a';
	int i=1;
	float f=1.3;
	double d=1.35;
	short s=3;
	long l=13;
	long long int ll=100;
	long double ld=130.13;
	
	 printf("\nThe size of 1 char is: %ld bytes.",sizeof(char));
	 printf("\nThe size of 1 int is: %ld bytes.",sizeof(int));
	 printf("\nThe size of 1 float is: %ld bytes.",sizeof(float));
	 printf("\nThe size of 1 double is: %ld bytes.",sizeof(double));
	 printf("\nThe size of 1 short int is: %ld bytes.",sizeof(short));
	 printf("\nThe size of 1 long int is: %ld bytes.",sizeof(long));
	 printf("\nThe size of 1 long long int is: %ld bytes.",sizeof(long long int));
	 printf("\nThe size of 1 long double is: %ld bytes.",sizeof(long double));
 	 printf("\nThe size of 1 void is: %ld bytes.\n",sizeof(void));      
	return 0;
}

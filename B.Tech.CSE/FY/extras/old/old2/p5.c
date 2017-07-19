#include<stdio.h>

typedef struct {
	int a,b,c;

}sample;

void main()
{
	sample z,*pz;
	pz=&z;
	//printf("\nenter: ");
	//scanf(" %d",pz);
	//printf("\n %p,%p\n",pz+1,&z.b);
	printf("\n %ld\n",sizeof(long double));
}

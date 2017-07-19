#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c,d;
	float r1,r2,x,y;
	printf("\n Enter the coefficients of quadratic eq. seperated by blank spaces:");
	scanf("%d %d %d",&a,&b,&c);
	d=(b*b)-(4*a*c);	
	if(d>0){
		r1=(-b+sqrt(d))/(2*a);
		r2=(-b-sqrt(d))/(2*a);
		printf("\n the roots are %.2f and %.2f\n",r1,r2);
	}
	else if(d==0){
		r1=r2=-b/(2.0*a);
		printf("\n the roots are equal and it is %.2f\n",r1);
	}
	else if(d<0){
		x=-b/(2.0*a);
		y=sqrt(-d)/(2*a);
		printf("\n the roots are unreal and they are %.2f+%.2fi & %.2f-%.2fi\n",x,y,x,y);		
	}		
	return 0;
}

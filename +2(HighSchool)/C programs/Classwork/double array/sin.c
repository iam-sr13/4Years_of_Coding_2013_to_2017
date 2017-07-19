#include<stdio.h>
#include<math.h>
int main()
{
	int fact(int);
	int ipas(char*);	
	float x,y,sum=0;
	int n,i,p=1;
	x=ipas("\nEnter the value for finding its sin in degrees: ");
	n=ipas("\nEnter the value for no. of terms: ");
	y=x;
	x=x*22/7/180;
	for(i=1;i<=n;i++)
	{
		sum=sum+p*pow(x,2*i-1)/fact(2*i-1);
		p=p*-1;
	}
	printf("\n\nThe sin(%.4f)=%.4f",y,sum);	
	return 0;	
}

int fact(int n)
{
	int i=2,p=1;
	while(i<=n)
	{
		p=p*i;
		i++;
	}
	return p;
}

int ipas(char c[])
{
	int scan;
	printf("\n%s",c);
	scanf(" %d",&scan);
	return scan;
}

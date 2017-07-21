#include<stdio.h>
float det(float b[3][3]);
void co_factor(float c[3][3]);
void transpose(float b[3][3]);
void inverse(float b[3][3],float det);

void main()
{
	float a[3][3]={
					-4,2,3,
					1,2,1,
					1,-2,3
				};
	float sum,*co;
	int m,n;

	printf("The original matrix is\n\a");
	for(m=0;m<=2;m++)
	{
		for(n=0;n<=2;n++)
		{
			printf("%.2f\t",a[m][n]);
		}
		printf("\n");
	}
	sum=det(a);
	printf("The determinant is %.2f\n",sum);
	printf("\n\n");

	co_factor(a);
	printf("The cofactor matrix is\n");
	for(m=0;m<=2;m++)
	{
		for(n=0;n<=2;n++)
		{
			printf("%.2f\t",a[m][n]);
		}
		printf("\n");
	}
	printf("\n\n");

	transpose(a);
	printf("The adjoint matrix is\n");
	for(m=0;m<=2;m++)
	{
		for(n=0;n<=2;n++)
		{
			printf("%.2f\t",a[m][n]);
		}
		printf("\n");
	}
	printf("\n\n");

	inverse(a,sum);
	printf("The inverse matrix is\n");
	for(m=0;m<=2;m++)
	{
		for(n=0;n<=2;n++)
		{
			printf("%.2f\t",a[m][n]);
		}
		printf("\n");
	}

}

float det(float b[3][3])
{
	int m,n,i=0;
	float sum=0;

	for(m=0;m<=0;m++)
	{
		for(n=0;n<=2;n++)
		{
			if(i%2==0)
			{
				sum=sum+b[m][n]*((b[(m+1)%3][(n+1)%3]*b[(m+2)%3][(n+2)%3])-(b[(m+2)%3][(n+1)%3]*b[(m+1)%3][(n+2)%3]));
			}
			if(i%2==1)
			{
				sum=sum-b[m][n]*((b[(m+1)%3][(n+1)%3]*b[(m+2)%3][(n+2)%3])-(b[(m+2)%3][(n+1)%3]*b[(m+1)%3][(n+2)%3]));
			}
		}
		i++;	
	}
	return(sum);
}


void co_factor(float c[3][3])
{
	int m,n;
	float d[3][3],e[9];
	for(m=0;m<=2;m++)
	{
		for(n=0;n<=2;n++)
		{
			d[m][n]=(c[(m+1)%3][(n+1)%3]*c[(m+2)%3][(n+2)%3])-(c[(m+2)%3][(n+1)%3]*c[(m+1)%3][(n+2)%3]);
		}
	}
	for(m=0;m<=2;m++)
	{
		for(n=0;n<=2;n++)
		{
//			e[m*3+n]=d[m][n];
			c[m][n]=d[m][n];
		}
	}

}
	
void transpose(float c[3][3])
{
	int m,n;
	float d[3][3];
	for(m=0;m<=2;m++)
	{
		for(n=0;n<=2;n++)
		{
			d[m][n]=c[n][m];
		}
	}
	for(m=0;m<=2;m++)
	{
		for(n=0;n<=2;n++)
		{
//			e[m*3+n]=d[m][n];
			c[m][n]=d[m][n];
		}
	}

}

  
void inverse(float b[3][3],float det)
{
	int m,n;
	for(m=0;m<=2;m++)
	{
		for(n=0;n<=2;n++)
		{
			b[m][n]=b[m][n]/det;
		}
	}
}
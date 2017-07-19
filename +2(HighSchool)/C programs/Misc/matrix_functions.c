#include<stdio.h>
float det(float b[10][10],int m);
float mat(int i,int j,int m);

void main()
{
	float sum,a[10][10];
	int m,i,j;


	printf("Enter the order of the square matrix\n");
	scanf("%d",&m);

	printf("Enter the elements of the matrix\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%f",&a[i][j]);
		}
	}

	printf("The original matrix is\n\a");
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%.2f\t",a[i][j]);
		}
		printf("\n");
	}
	sum=det(a,m);
	printf("The determinant is %.2f\n",sum);
	printf("\n\n");
}


float det(float b[10][10],int m)
{
	int i,j,k=0;
	float a[10][10];
	static float sum;

	if(m==3)
	{
		for(i=0;i<=0;i++)
		{
			for(j=0;j<=2;j++)
			{
				if(k%2==0)
				{
					sum=sum+b[i][j]*((b[(i+1)%3][(j+1)%3]*b[(i+2)%3][(j+2)%3])-(b[(i+2)%3][(j+1)%3]*b[(i+1)%3][(j+2)%3]));
				}
				if(k%2==1)
				{
					sum=sum-b[i][j]*((b[(i+1)%3][(j+1)%3]*b[(i+2)%3][(j+2)%3])-(b[(i+2)%3][(j+1)%3]*b[(i+1)%3][(j+2)%3]));
				}
			}
			k++;
		}
		//return(sum);
	}

	else if(m!=3)
	{
		sum=1;i=0;
		for(j=0;j<m;j++)
		{
			//sum=sum+a[0][j]*mat(i+1,j+1,m);

		}
	}
	return(sum);
}
		
float mat(int i,int j,int m)
{
	float a[10][10],sum;
	if(m>3)
	{
		sum=sum*a[i][j]*mat(i+1,j+1,m);
		m--;
	}

	if(m==3)
	{
		sum=sum*det(a,m);
	}
	return(sum);
}

				
			


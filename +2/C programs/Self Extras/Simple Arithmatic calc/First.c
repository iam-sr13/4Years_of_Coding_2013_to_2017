#include<stdio.h>
int main()
{
	float a,b,x,l;
	char c='y';
	while(c=='y')
	{			
		printf("\n Enter any two whole no. variables seperated by a blank space:");
		scanf("%f %f",&a,&b);
		printf("\n Enter the function which you want to perform for the two variables \n 1=addition,\n 2=multiplication,\n 3=subtraction,\n 4=division,\n 0=exit.\n\tyour choice:\a");
		scanf("%f",&x);
		if(x==1){l=a+b;}else if(x==2){l=a*b;}else if(x==3){l=a-b;}else if(x==4){l=a/b;}else if(x==0){return 0;}
		printf("The result=%.2f",l);
		fflush(stdin);
		printf("\nDo you want to perform another set of calcultion?\nEnter y for yes or n to exit the program.");
		scanf("%c",&c);		
	}
	return 0;
}	

#include<stdio.h>
int main()
{
	float c,f;
	int i;
	printf("\n Enter 1 for converting deg c to deg f\nor enter 2 for converting deg f to deg c:\n");
	scanf("%d",&i);
	if (i==1) {
		printf("\n Enter the value of temperature in degree C:\n");
		scanf("%f",&c);
		f=c*18/10.0+32;
		printf("\nThe value of temp in F = %.2f\n",f);
		return 0;		
	}
	if (i==2) {
		printf("\n Enter the value of temperature in degree F:\n");
		scanf("%f",&f);
		c=(f-32)*10.0/18;
		printf("\nThe value of temp in C = %.2f\n",c);
		return 0;
	}
	else printf("\n Wrong option!!\nProgram will end......\n");
	return 0;
}
			
		

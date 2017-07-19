#include<stdio.h>
int main()
{
	printf("\nNOTE:-\n1) In the following program, enter your marks in 'M.O/M.M' format.\n    M.O=Marks Obtained.\n    M.M=Maximum Marks.\n2) For entering marks for next subject put a ','(comma) after entering marks\n   for the first subject.\n3) Put a ';'(semicolon) after entering marks for the last subject.\n");
	float p=0,i=0,a,b;
	char n;
	do {
		printf("\nEnter the marks for your respective subject:");
		scanf("%f/%f%c",&a,&b,&n);		 
		p+=(a/b);
		i++;				
	}
	while (n!=';');
	p*=(100/i);
	printf("\nYour Percentage is '%.2f %%'.",p);
	if (p>=91) if (p<=100) printf("\nYour Grade is 'A'");
	if (p>=81) if (p<91) printf("\nYour Grade is 'B'");
	if (p>=71) if (p<81) printf("\nYour Grade is 'C'");
	if (p>=61) if (p<71) printf("\nYour Grade is 'D'");
	if (p>=51) if (p<61) printf("\nYour Grade is 'E'");
	if (p>=41) if (p<51) printf("\nYour Grade is 'F'");
	if (p>=33) if (p<41) printf("\nYour Grade is 'G'");
	if (p>=21) if (p<33) printf("\nYour Grade is 'H'");
	if (p>=0) if (p<21) printf("\nYour Grade is 'I'");
	if (p>33) printf("\nYou have passed! Congratulations!!\n");
	if (p<33) printf("\nYou have failed!\n");
	return 0;
}

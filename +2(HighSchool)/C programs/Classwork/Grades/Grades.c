#include<stdio.h>
int main()
{
	float p;
	printf("\nEnter your percentage:");
	scanf("%f",&p);
	if (p>=91) if (p<=100) printf("\nYour Grade is 'A'");
	if (p>=81) if (p<91) printf("\nYour Grade is 'B'");
	if (p>=71) if (p<81) printf("\nYour Grade is 'C'");
	if (p>=61) if (p<71) printf("\nYour Grade is 'D'");
	if (p>=51) if (p<61) printf("\nYour Grade is 'E'");
	if (p>=41) if (p<51) printf("\nYour Grade is 'F'");
	if (p>=33) if (p<41) printf("\nYour Grade is 'G'");
	if (p>=21) if (p<33) printf("\nYour Grade is 'H'");
	if (p>=0) if (p<21) printf("\nYour Grade is 'I'");
	if (p>33) printf("\nYou have passed! Congratulations!!");
	if (p<33) printf("\nYou have failed!");
	return 0;
}

#include<stdio.h>
int main()
{
	printf("\nIn the following program, enter your marks in 'M.O/M.M' format.\nM.O=Marks Obtained.\nM.M=Maximum Marks.\n");
	float p,e1,sl1,m1,p1,c1,cs1;
	int e2,sl2,m2,p2,c2,cs2;
	printf("\nEnter your marks for English:");
	scanf("%f/%d",&e1,&e2);
	printf("\nEnter your marks for Second Language:");
	scanf("%f/%d",&sl1,&sl2);
	printf("\nEnter your marks for Maths:");
	scanf("%f/%d",&m1,&m2);
	printf("\nEnter your marks for Physics:");
	scanf("%f/%d",&p1,&p2);
	printf("\nEnter your marks for Chemistry:");
	scanf("%f/%d",&c1,&c2);
	printf("\nEnter your marks for Computer Science:");
	scanf("%f/%d",&cs1,&cs2);	
	p=(e1+sl1+m1+p1+c1+cs1)/(e2+sl2+m2+p2+c2+cs2)*100;
	printf("\nYour Percentage is '%.2f%%'.",p);
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

	
	



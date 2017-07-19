#include<stdio.h>
int main()
{
	int a,b,c;
	printf("\nEnter the values of angles of triangle:\n");
	scanf("%d %d %d",&a,&b,&c);
	if (a+b+c!=180 || a==0 || b==0 || c==0) {
		printf("\nInvalid Triangle!!\n");
		printf("\nProgram will now exit.....\n");
	}
	else if (a<90 && b<90 && c<90) printf("\nAcute Triangle\n");
	else if (a==90 || b==90 || c==90) printf("\nRight Angled Triangle\n");
	else printf("\nObtuse Triangle\n");
	return 0;	
}

#include<stdio.h>
#include<ctype.h>

void main()
{
	char a;
	printf("\nEnter any character you like: ");
	scanf(" %c",&a);
	if(isalpha(a))
		printf("\nYou typed an alphabet.\n");
	else
		printf("\nYou didn't typed an alphabet.\n");
}

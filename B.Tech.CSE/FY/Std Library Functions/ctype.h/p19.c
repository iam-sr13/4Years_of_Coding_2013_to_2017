#include<stdio.h>

int isspace(int a)
{
	if((a>=9 && a<=13) || a==' ') return 1;
	return 0;
}

void main()
{
        char a;
        printf("\nEnter any character you like: ");
        scanf("%c",&a);
        if(isspace(a))
                printf("\nYou typed a whitespace character.\n");
        else
                printf("\nYou didn't typed a whitespace character.\n");
}


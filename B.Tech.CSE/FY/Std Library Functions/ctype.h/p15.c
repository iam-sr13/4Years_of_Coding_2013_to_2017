#include<stdio.h>

int isprint(int a)
{
	if((a>=9 && a<=13) || (a>=32 && a<=126)) return 1;
	return 0;
}

void main()
{
        char a;
        printf("\nEnter any character you like: ");
        scanf("%c",&a);
        if(isprint(a))
                printf("\nYou typed a printable character.\n");
        else
                printf("\nYou didn't typed a printable character.\n");
}


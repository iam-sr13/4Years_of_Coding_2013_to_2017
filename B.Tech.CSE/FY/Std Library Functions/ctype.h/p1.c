#include<stdio.h>


int isdigit(int a)
{
	if(a>='0' && a<='9') return 1;
	else return 0;
}

void main()
{
        char a;
        printf("\nEnter any character you like: ");
        scanf(" %c",&a);
        if(isdigit(a))
                printf("\nYou typed a digit.\n");
        else
                printf("\nYou didn't typed a digit.\n");
}


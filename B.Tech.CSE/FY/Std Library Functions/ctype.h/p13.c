#include<stdio.h>

int iscntrl(int a)
{
	if(a>=0 && a<=31) return 1;
	else return 0;
}

void main()
{
        char a;
        printf("\nEnter any character you like: ");
        scanf("%c",&a);
        if(iscntrl(a))
                printf("\nYou typed a control character.\n");
        else
                printf("\nYou didn't typed a control character.\n");
}


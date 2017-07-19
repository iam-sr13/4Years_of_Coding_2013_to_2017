#include<stdio.h>
#include<ctype.h>

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


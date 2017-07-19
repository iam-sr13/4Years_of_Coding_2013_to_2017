#include<stdio.h>
#include<ctype.h>

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


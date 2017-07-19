#include<stdio.h>
#include<ctype.h>

void main()
{
        char a;
        printf("\nEnter any character you like: ");
        scanf("%c",&a);
        if(isxdigit(a))
                printf("\nYou typed a hexadecimal character.\n");
        else
                printf("\nYou didn't typed a hexadecimal character.\n");
}


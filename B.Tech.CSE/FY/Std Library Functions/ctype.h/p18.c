#include<stdio.h>
#include<ctype.h>

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


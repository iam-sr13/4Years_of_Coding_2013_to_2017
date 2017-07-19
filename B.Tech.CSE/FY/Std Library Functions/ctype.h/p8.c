#include<stdio.h>
#include<ctype.h>

void main()
{
        char a;
        printf("\nEnter any character you like: ");
        scanf(" %c",&a);
        if(isalnum(a))
                printf("\nYou typed an alphanumeric.\n");
        else
                printf("\nYou didn't typed an alphanumeric.\n");
}


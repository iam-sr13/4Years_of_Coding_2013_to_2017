#include<stdio.h>
#include<ctype.h>

void main()
{
        char a;
        printf("\nEnter any character you like: ");
        scanf(" %c",&a);
        if(isupper(a))
                printf("\nYou typed a upper case alpha.\n");
        else
                printf("\nYou didn't typed a upper case alpha.\n");
}



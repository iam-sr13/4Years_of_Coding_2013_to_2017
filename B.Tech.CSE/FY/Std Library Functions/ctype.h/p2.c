#include<stdio.h>
#include<ctype.h>

void main()
{
        char a;
        printf("\nEnter any character you like: ");
        scanf(" %c",&a);
        if(islower(a))
                printf("\nYou typed a lower case alpha.\n");
        else
                printf("\nYou didn't typed a lower case alpha.\n");
}

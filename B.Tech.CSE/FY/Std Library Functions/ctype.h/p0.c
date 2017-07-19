#include<stdio.h>
#include<ctype.h>

void main()
{
        char a;
        printf("\nEnter any character you like: ");
        scanf(" %c",&a);
        if(isdigit(a))
                printf("\nYou typed a digit.\n");
        else
                printf("\nYou didn't typed a digit.\n");
        getch();
}


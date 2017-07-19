#include<stdio.h>
#include<ctype.h>

void main()
{
        char a;
        printf("\nEnter any character you like: ");
        scanf("%c",&a);
        if(isgraph(a))
                printf("\nYou typed a graphic character.\n");
        else
                printf("\nYou didn't typed a graphic character.\n");
}


#include<stdio.h>
#include<ctype.h>

void main()
{
        char a;
        printf("\nEnter any character you like: ");
        scanf("%c",&a);
        if(ispunct(a))
                printf("\nYou typed a punctuation character.\n");
        else
                printf("\nYou didn't typed a punctuation character.\n");
}


#include<stdio.h>

int ispunct(int a)
{
	if((a>='!' && a<='/') || (a>=':' && a<='@') || (a>='[' && a<='`')||(a>='{' && a<='~')) return 1;
	return 0;
}

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


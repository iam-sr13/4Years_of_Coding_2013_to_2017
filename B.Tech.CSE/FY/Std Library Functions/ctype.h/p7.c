#include<stdio.h>

int isalpha(int a)
{
	if((a>='a' && a<='z')||(a>='A' && a<='Z')) return 1;
	else return 0;
}

void main()
{
        char a;
        printf("\nEnter any character you like: ");
        scanf(" %c",&a);
        if(isalpha(a))
                printf("\nYou typed an alphabet.\n");
        else
                printf("\nYou didn't typed an alphabet.\n");
}


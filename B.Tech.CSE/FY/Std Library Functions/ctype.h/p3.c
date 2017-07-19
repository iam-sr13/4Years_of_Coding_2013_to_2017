#include<stdio.h>

int islower(int a)
{
	if(a>='a' && a<='z') return 1;
	else return 0;
}

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



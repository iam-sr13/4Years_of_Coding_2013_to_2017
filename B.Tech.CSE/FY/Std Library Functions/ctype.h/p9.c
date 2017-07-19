#include<stdio.h>


int isalnum(int a)
{
	if((a>='a' && a<='z')||(a>='A' && a<='Z')||(a>='0' && a<='9')) return 1;
	else return 0;
}

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


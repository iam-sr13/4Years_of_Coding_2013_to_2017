#include<stdio.h>

int isxdigit(int a)
{
	if((a>='0' && a<='9')||(a>='a' && a<='f')||(a>='A' && a<='F')) return 1;
	return 0;
}

void main()
{
        char a;
        printf("\nEnter any character you like: ");
        scanf("%c",&a);
        if(isxdigit(a))
                printf("\nYou typed a hexadecimal character.\n");
        else
                printf("\nYou didn't typed a hexadecimal character.\n");
}


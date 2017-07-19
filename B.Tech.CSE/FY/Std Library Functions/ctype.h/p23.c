#include<stdio.h>

int tolower(int a)
{
	if(a>='A' && a<='Z') return a+32;
	return a;
}

void main()
{
        char a;
        printf("\nEnter any character you like: ");
        scanf("%c",&a);
        
        printf("\nYou typed \"%c\" and its lower form is \"%c\".",a,tolower(a)); 
}


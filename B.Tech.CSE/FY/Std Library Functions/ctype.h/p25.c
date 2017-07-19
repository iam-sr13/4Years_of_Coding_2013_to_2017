#include<stdio.h>

int toupper(int a)
{
	if(a>='a' && a<='z') return a-32;
	return a;
}

void main()
{
        char a;
        printf("\nEnter any character you like: ");
        scanf("%c",&a);
        
        printf("\nYou typed \"%c\" and its upper form is \"%c\".",a,toupper(a)); 
}


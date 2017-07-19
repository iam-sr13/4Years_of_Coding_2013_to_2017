#include<stdio.h>
#include<ctype.h>

void main()
{
        char a;
        printf("\nEnter any character you like: ");
        scanf("%c",&a);
        
        printf("\nYou typed \"%c\" and its upper form is \"%c\".",a,toupper(a)); 
}


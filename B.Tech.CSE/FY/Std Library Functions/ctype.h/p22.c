#include<stdio.h>
#include<ctype.h>

void main()
{
        char a;
        printf("\nEnter any character you like: ");
        scanf("%c",&a);
        
        printf("\nYou typed \"%c\" and its lower form is \"%c\".",a,tolower(a)); 
}

